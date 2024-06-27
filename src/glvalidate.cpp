#include <glmods/gl_plugin.h>

#include <iomanip>
#include <iostream>
#include <memory>
#include <system_error>
#include <type_traits>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

using Module =
    std::unique_ptr<std::remove_pointer_t<HMODULE>,
                    decltype([](HMODULE module) { ::FreeLibrary(module); })>;

static gl_host_info_t host_info{
    .host_version = {0, 0, 1},
};

static gl_version_t api_version = GL_VERSION(GL_API_VERSION);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: glvalidate <plugin>\n";
    return 1;
  }

  Module plugin_module{::LoadLibrary(argv[1])};
  if (!plugin_module) {
    auto errcode = ::GetLastError();
    auto errmsg = std::system_category().message(errcode);
    std::cerr << "FAILURE: Error loading plugin: " << errmsg << '\n';
    return 1;
  }

  auto plugin_entry = reinterpret_cast<gl_plugin_entry_t>(
      ::GetProcAddress(plugin_module.get(), "gl_plugin_entry"));
  if (!plugin_entry) {
    auto errcode = ::GetLastError();
    auto errmsg = std::system_category().message(errcode);
    std::cerr << "FAILURE: Error loading plugin entry point: " << errmsg
              << '\n';
    return 1;
  }

  auto plugin = plugin_entry(&host_info);

  if (!plugin) {
    std::cerr << "FAILURE: `gl_plugin_entry` returned NULL.";
    return 1;
  }

  if (!plugin->get_plugin_info) {
    std::cerr << "FAILURE: `get_plugin_info` is NULL.";
    return 1;
  }

  auto plugin_info = plugin->get_plugin_info();

  if (!plugin_info) {
    std::cerr << "FAILURE: `get_plugin_info` returned NULL.";
    return 1;
  }

  if (!plugin_info->name) {
    std::cerr << "FAILURE: Plugin name is NULL.";
    return 1;
  }

  std::cout << "Plugin info:\n";
  std::cout << "\tName: " << plugin_info->name << '\n';

  if (plugin_info->description) {
    std::cout << "\tDescription: " << plugin_info->description << '\n';
  }

  std::cout << "\tVersion: " << (int)plugin_info->plugin_version.major << '.'
            << (int)plugin_info->plugin_version.minor << '.'
            << (int)plugin_info->plugin_version.patch << '\n';

  std::cout << "\tTarget API version: "
            << (int)plugin_info->target_api_version.major << '.'
            << (int)plugin_info->target_api_version.minor << '.'
            << (int)plugin_info->target_api_version.patch << '\n';

  if (plugin_info->authors) {
    for (auto author = plugin_info->authors; author->name; ++author) {
      std::cout << "\tAuthor: " << author->name;
      if (author->email) {
        std::cout << " <" << author->email << ">\n";
      } else {
        std::cout << '\n';
      }
    }
  }

  if (plugin_info->dependencies) {
    for (auto dep = plugin_info->dependencies; *dep; ++dep) {
      std::cout << "\tPlugin requires plugin `" << *dep << "`\n";
    }
  }

  if (plugin_info->detours) {
    for (auto det = plugin_info->detours; *det; ++det) {
      std::cout << "\tPlugin detours 0x" << std::hex << std::setw(8)
                << std::setfill('0') << *det << "\n";
    }
  }
}