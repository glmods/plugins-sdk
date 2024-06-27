#ifndef GLMODS_EXT_GL_LUA_H
#define GLMODS_EXT_GL_LUA_H

#include <stdarg.h>

#include "../gl_plugin.h"

#ifndef GLMODS_NO_LUA_MACROS
#define LUAI_MAXSTACK 1000000
#define LUA_REGISTRYINDEX (-LUAI_MAXSTACK - 1000)
#define lua_upvalueindex(i) (LUA_REGISTRYINDEX - (i))

#define LUA_OK 0
#define LUA_YIELD 1
#define LUA_ERRRUN 2
#define LUA_ERRSYNTAX 3
#define LUA_ERRMEM 4
#define LUA_ERRERR 5

typedef struct lua_State lua_State;

#define LUA_TNONE (-1)

#define LUA_TNIL 0
#define LUA_TBOOLEAN 1
#define LUA_TLIGHTUSERDATA 2
#define LUA_TNUMBER 3
#define LUA_TSTRING 4
#define LUA_TTABLE 5
#define LUA_TFUNCTION 6
#define LUA_TUSERDATA 7
#define LUA_TTHREAD 8
#define LUA_NUMTYPES 9

#define LUA_MINSTACK 20

#define LUA_RIDX_MAINTHREAD 1
#define LUA_RIDX_GLOBALS 2
#define LUA_RIDX_LAST LUA_RIDX_GLOBALS

typedef double lua_Number;

typedef long long lua_Integer;

typedef unsigned long long lua_Unsigned;

typedef intptr_t lua_KContext;

typedef const char *(*lua_Reader)(lua_State *L, void *ud, size_t *sz);

typedef int (*lua_Writer)(lua_State *L, const void *p, size_t sz, void *ud);

typedef int (*lua_CFunction)(lua_State *L);

typedef int (*lua_KFunction)(lua_State *L, int status, lua_KContext ctx);

#define LUA_OPADD 0
#define LUA_OPSUB 1
#define LUA_OPMUL 2
#define LUA_OPMOD 3
#define LUA_OPPOW 4
#define LUA_OPDIV 5
#define LUA_OPIDIV 6
#define LUA_OPBAND 7
#define LUA_OPBOR 8
#define LUA_OPBXOR 9
#define LUA_OPSHL 10
#define LUA_OPSHR 11
#define LUA_OPUNM 12
#define LUA_OPBNOT 13

#define LUA_OPEQ 0
#define LUA_OPLT 1
#define LUA_OPLE 2

#define LUA_NOREF (-2)
#define LUA_REFNIL (-1)

#define LUA_NUMTAGS LUA_NUMTYPES

#define lua_call(L, n, r) lua_callk(L, (n), (r), 0, NULL)
#define lua_pcall(L, n, r, f) lua_pcallk(L, (n), (r), (f), 0, NULL)
#define lua_yield(L, n) lua_yieldk(L, (n), 0, NULL)
#define lua_getextraspace(L) ((void *)((char *)(L) - LUA_EXTRASPACE))
#define lua_tonumber(L, i) lua_tonumberx(L, (i), NULL)
#define lua_tointeger(L, i) lua_tointegerx(L, (i), NULL)
#define lua_pop(L, n) lua_settop(L, -(n) - 1)
#define lua_newtable(L) lua_createtable(L, 0, 0)
#define lua_register(L, n, f) (lua_pushcfunction(L, (f)), lua_setglobal(L, (n)))
#define lua_pushcfunction(L, f) lua_pushcclosure(L, (f), 0)
#define lua_isfunction(L, n) (lua_type(L, (n)) == LUA_TFUNCTION)
#define lua_istable(L, n) (lua_type(L, (n)) == LUA_TTABLE)
#define lua_islightuserdata(L, n) (lua_type(L, (n)) == LUA_TLIGHTUSERDATA)
#define lua_isnil(L, n) (lua_type(L, (n)) == LUA_TNIL)
#define lua_isboolean(L, n) (lua_type(L, (n)) == LUA_TBOOLEAN)
#define lua_isthread(L, n) (lua_type(L, (n)) == LUA_TTHREAD)
#define lua_isnone(L, n) (lua_type(L, (n)) == LUA_TNONE)
#define lua_isnoneornil(L, n) (lua_type(L, (n)) <= 0)
#define lua_pushliteral(L, s) lua_pushstring(L, "" s)
#define lua_pushglobaltable(L)                                                 \
  ((void)lua_rawgeti(L, LUA_REGISTRYINDEX, LUA_RIDX_GLOBALS))
#define lua_tostring(L, i) lua_tolstring(L, (i), NULL)
#define lua_insert(L, idx) lua_rotate(L, (idx), 1)
#define lua_remove(L, idx) (lua_rotate(L, (idx), -1), lua_pop(L, 1))
#define lua_replace(L, idx) (lua_copy(L, -1, (idx)), lua_pop(L, 1))
#define lua_newuserdata(L, s) lua_newuserdatauv(L, s, 1)
#define lua_getuservalue(L, idx) lua_getiuservalue(L, idx, 1)
#define lua_setuservalue(L, idx) lua_setiuservalue(L, idx, 1)
#define luaL_checkversion(L)                                                   \
  luaL_checkversion_(L, LUA_VERSION_NUM, LUAL_NUMSIZES)
#define luaL_loadfile(L, f) luaL_loadfilex(L, f, NULL)
#define luaL_newlibtable(L, l)                                                 \
  lua_createtable(L, 0, sizeof(l) / sizeof((l)[0]) - 1)
#define luaL_newlib(L, l)                                                      \
  (luaL_checkversion(L), luaL_newlibtable(L, l), luaL_setfuncs(L, l, 0))
#define luaL_argcheck(L, cond, arg, extramsg)                                  \
  ((void)((cond) || luaL_argerror(L, (arg), (extramsg))))
#define luaL_argexpected(L, cond, arg, tname)                                  \
  ((void)((cond) || luaL_typeerror(L, (arg), (tname))))
#define luaL_checkstring(L, n) (luaL_checklstring(L, (n), NULL))
#define luaL_optstring(L, n, d) (luaL_optlstring(L, (n), (d), NULL))
#define luaL_typename(L, i) lua_typename(L, lua_type(L, (i)))
#define luaL_dofile(L, fn)                                                     \
  (luaL_loadfile(L, fn) || lua_pcall(L, 0, LUA_MULTRET, 0))
#define luaL_dostring(L, s)                                                    \
  (luaL_loadstring(L, s) || lua_pcall(L, 0, LUA_MULTRET, 0))
#define luaL_getmetatable(L, n) (lua_getfield(L, LUA_REGISTRYINDEX, (n)))
#define luaL_opt(L, f, n, d) (lua_isnoneornil(L, (n)) ? (d) : f(L, (n)))
#define luaL_loadbuffer(L, s, sz, n) luaL_loadbufferx(L, s, sz, n, NULL)
#define luaL_intop(op, v1, v2)                                                 \
  ((lua_Integer)((lua_Unsigned)(v1)op(lua_Unsigned)(v2)))
#define luaL_pushfail(L) lua_pushnil(L)

typedef struct luaL_Reg {
  const char *name;
  lua_CFunction func;
} luaL_Reg;
#endif

typedef struct gl_lua_funcs {
#define GLMODS_GL_LUA_FUNCTION(name, rettype, ...)                             \
  rettype (**name)(__VA_ARGS__);
#include "gl_lua_funcs.inc.h"
} gl_lua_funcs_t;

#ifdef GLMODS_DECLARE_LUA_FUNCTIONS
#define GLMODS_GL_LUA_FUNCTION(name, rettype, ...)                             \
  extern rettype (*name)(__VA_ARGS__);
#include "gl_lua_funcs.inc.h"
#endif

#ifdef GLMODS_DEFINE_LUA_FUNCTIONS
#define GLMODS_GL_LUA_FUNCTION(name, rettype, ...) rettype (*name)(__VA_ARGS__);
#include "gl_lua_funcs.inc.h"
#endif

#define GL_LUA_PLUGIN "lua"
#define GL_EXT_LUA "lua"
#define GL_EXT_LUA_MAJOR 0
#define GL_EXT_LUA_MINOR 0
#define GL_EXT_LUA_PATCH 1

typedef struct gl_lua_module {
  const char *name;
  lua_CFunction func;
} gl_lua_module_t;

typedef struct gl_lua_params {
  const gl_lua_module_t *modules;
} gl_lua_params_t;

typedef struct gl_lua {
  void *data;
  void (*deinit)(const struct gl_lua *lua);
  lua_State *(*get_funcs)(const struct gl_lua *lua, gl_lua_funcs_t *funcs);
  bool (*register_modules)(const struct gl_lua *lua);
} gl_lua_t;

#endif /* GLMODS_EXT_GL_LUA_H */