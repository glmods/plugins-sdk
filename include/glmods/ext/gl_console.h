#ifndef GLMODS_EXT_GL_CONSOLE_H
#define GLMODS_EXT_GL_CONSOLE_H

#include <stdarg.h>

#define GL_CONSOLE_PLUGIN "console"
#define GL_EXT_CONSOLE "console"
#define GL_EXT_CONSOLE_MAJOR 0
#define GL_EXT_CONSOLE_MINOR 0
#define GL_EXT_CONSOLE_PATCH 1

typedef struct gl_console {
  void *data;
  void (*deinit)(const struct gl_console *console);
  void (*print)(const struct gl_console *console, const char *msg);
  void (*set_cursor_color)(const struct gl_console *console, int color);
  int (*get_cursor_color)(const struct gl_console *console);
  void (*set_text_color)(const struct gl_console *console, int color);
  int (*get_text_color)(const struct gl_console *console);
  void (*execute_command)(const struct gl_console *console, const char *cmd);
} gl_console_t;

#endif /* GLMODS_EXT_GL_CONSOLE_H */