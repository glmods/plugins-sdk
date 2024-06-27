#ifndef GLMODS_EXT_GL_COMMANDS_H
#define GLMODS_EXT_GL_COMMANDS_H

#define GL_COMMANDS_PLUGIN "commands"
#define GL_EXT_COMMANDS "commands"
#define GL_EXT_COMMANDS_MAJOR 0
#define GL_EXT_COMMANDS_MINOR 0
#define GL_EXT_COMMANDS_PATCH 1

typedef void(__fastcall *gl_command_cb_t)(int unk, const char *command);

struct gl_commands;

typedef struct gl_commands_params {
  void *userdata;
  void (*setup_commands)(const struct gl_commands *commands, void *userdata);
} gl_commands_params_t;

typedef struct gl_commands {
  void *data;
  void (*deinit)(const struct gl_commands *commands);
  bool (*register_command)(const struct gl_commands *commands, const char *name,
                           const char *help, gl_command_cb_t callback);
} gl_commands_t;

#endif /* GLMODS_EXT_GL_COMMANDS_H */