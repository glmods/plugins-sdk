#ifndef GLMODS_GL_PLUGIN_H
#define GLMODS_GL_PLUGIN_H

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>

static_assert(sizeof(void *) == 4,
              "GLMods plugins can only be compiled as 32bit libraries");

#ifndef _WIN32
#error "GLMods plugins can only be compiled as Win32 DLLs"
#endif

#define GL_API_VERSION_MAJOR 0
#define GL_API_VERSION_MINOR 0
#define GL_API_VERSION_PATCH 1
#define GL_VERSION(name)                                                       \
  {                                                                            \
      name##_MAJOR,                                                            \
      name##_MINOR,                                                            \
      name##_PATCH,                                                            \
  }

#ifdef __cplusplus
#define GL_ENTRY_FUNC                                                          \
  extern "C" __declspec(dllexport) gl_plugin_t *gl_plugin_entry
#else
#define GL_ENTRY_FUNC __declspec(dllexport) gl_plugin_t *gl_plugin_entry
#endif

struct gl_lua;
typedef struct lua_State lua_State;

typedef struct gl_version {
  uint8_t major;
  uint8_t minor;
  uint8_t patch;
} gl_version_t;

typedef struct gl_host_info {
  gl_version_t host_version;
} gl_host_info_t;

typedef struct gl_module_info {
  const char *id;
} gl_module_info_t;

typedef struct gl_author_info {
  const char *name;
  const char *email;
} gl_author_info_t;

typedef struct gl_plugin_info {
  const char *name;
  const char *description;
  gl_version_t plugin_version;
  gl_version_t target_api_version;
  const gl_author_info_t *authors;
  const char **dependencies;
  const uintptr_t *detours;
  const char **provided_extensions;
} gl_plugin_info_t;

struct gl_plugin_host;

typedef struct gl_plugin {
  const gl_plugin_info_t *(*get_plugin_info)(void);
  bool (*init)(const struct gl_plugin_host *host);
  void (*deinit)(void);

  const void *(*get_extension)(const char *name, gl_version_t version,
                               const gl_plugin_info_t *requester, void *params);
} gl_plugin_t;

typedef gl_plugin_t *(*gl_plugin_entry_t)(const gl_host_info_t *host_info);

typedef struct gl_plugin_host {
  void *host_data;

  void *(*get_object_at_address)(const struct gl_plugin_host *host,
                                 uintptr_t address);
  bool (*detour)(const struct gl_plugin_host *host, uintptr_t function_addr,
                 void **function, void *detour);
  const void *(*get_extension)(const struct gl_plugin_host *host,
                               const char *name, gl_version_t version,
                               void *params);
  const char *(*get_config_string)(const struct gl_plugin_host *host,
                                   const char *name, const char *default_value);
  unsigned (*get_config_int)(const struct gl_plugin_host *host,
                             const char *name, unsigned default_value);
  bool (*set_config_string)(const struct gl_plugin_host *host, const char *name,
                            const char *value);
} gl_plugin_host_t;

#endif /* GLMODS_GL_PLUGIN_H */