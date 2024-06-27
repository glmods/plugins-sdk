#ifndef GLMODS_EXT_GL_LOG_H
#define GLMODS_EXT_GL_LOG_H

#include <stdarg.h>

#define GL_LOGGING_PLUGIN "logging"
#define GL_EXT_LOGGING "logging"
#define GL_EXT_LOGGING_MAJOR 0
#define GL_EXT_LOGGING_MINOR 0
#define GL_EXT_LOGGING_PATCH 1

typedef struct gl_logging {
  void *data;
  void (*deinit)(const struct gl_logging *log);

  void (*trace)(const struct gl_logging *log, const char *fmt, ...);
  void (*vtrace)(const struct gl_logging *log, const char *fmt, va_list vargs);
  void (*strace)(const struct gl_logging *log, const char *msg);

  void (*debug)(const struct gl_logging *log, const char *fmt, ...);
  void (*vdebug)(const struct gl_logging *log, const char *fmt, va_list vargs);
  void (*sdebug)(const struct gl_logging *log, const char *msg);

  void (*info)(const struct gl_logging *log, const char *fmt, ...);
  void (*vinfo)(const struct gl_logging *log, const char *fmt, va_list vargs);
  void (*sinfo)(const struct gl_logging *log, const char *msg);

  void (*warning)(const struct gl_logging *log, const char *fmt, ...);
  void (*vwarning)(const struct gl_logging *log, const char *fmt,
                   va_list vargs);
  void (*swarning)(const struct gl_logging *log, const char *msg);

  void (*error)(const struct gl_logging *log, const char *fmt, ...);
  void (*verror)(const struct gl_logging *log, const char *fmt, va_list vargs);
  void (*serror)(const struct gl_logging *log, const char *msg);

  void (*fatal)(const struct gl_logging *log, const char *fmt, ...);
  void (*vfatal)(const struct gl_logging *log, const char *fmt, va_list vargs);
  void (*sfatal)(const struct gl_logging *log, const char *msg);
} gl_logging_t;

#endif /* GLMODS_EXT_GL_LOG_H */