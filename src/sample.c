#include <glmods/gl_plugin.h>

#define GLMODS_DEFINE_LUA_FUNCTIONS
#include <glmods/ext/gl_lua.h>

#include <glmods/ext/gl_console.h>
#include <glmods/ext/gl_log.h>

#define GL_SAMPLE_VERSION_MAJOR 0
#define GL_SAMPLE_VERSION_MINOR 1
#define GL_SAMPLE_VERSION_PATCH 0

static const gl_author_info_t authors[] = {
    {"Francesco Bertolaccini", "francesco@bertolaccini.dev"},
    {NULL, NULL},
};

static const char *dependencies[] = {
    GL_LOGGING_PLUGIN,
    GL_LUA_PLUGIN,
    NULL,
};

static const uintptr_t detours[] = {
    0xf0031337,
    0,
};

static const gl_plugin_host_t *plugin_host = NULL;

static const gl_lua_t *lua;
static const gl_logging_t *log;

static const gl_plugin_info_t *get_plugin_info(void) {
  static gl_plugin_info_t plugin_info = {
      .name = "Sample Plugin",
      .description =
          "This plugin does nothing and only serves as an example of "
          "how to use the GLMods SDK",
      .plugin_version = GL_VERSION(GL_SAMPLE_VERSION),
      .target_api_version = GL_VERSION(GL_API_VERSION),
      .authors = authors,
      .dependencies = dependencies,
      .detours = detours,
      .provided_extensions = NULL,
  };
  return &plugin_info;
}

static bool plugin_init(const gl_plugin_host_t *host) {
  plugin_host = host;
  gl_lua_params_t lua_params = {
      .modules = NULL,
  };

  lua = (const gl_lua_t *)host->get_extension(
      host, GL_EXT_LUA, (gl_version_t)GL_VERSION(GL_EXT_LUA), &lua_params);

  gl_lua_funcs_t lua_funcs;
#define GLMODS_GL_LUA_FUNCTION(name, rettype, ...) lua_funcs.name = &name;
#include <glmods/ext/gl_lua_funcs.inc.h>

  lua->get_funcs(lua, &lua_funcs);
  log = (const gl_logging_t *)host->get_extension(
      host, GL_EXT_LOGGING, (gl_version_t)GL_VERSION(GL_EXT_LOGGING), NULL);
  log->sinfo(log, "Sample plugin initialized");

  return true;
}

static void plugin_deinit(void) {
  lua->deinit(lua);
  log->deinit(log);
}

GL_ENTRY_FUNC(gl_host_info_t *host_info) {
  static gl_plugin_t plugin = {
      .get_plugin_info = &get_plugin_info,
      .init = &plugin_init,
      .deinit = &plugin_deinit,
      .get_extension = NULL,
  };
  return &plugin;
}