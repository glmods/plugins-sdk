#ifndef GLMODS_GL_LUA_FUNCTION
#define GLMODS_GL_LUA_FUNCTION(name, rettype, ...)
#endif

GLMODS_GL_LUA_FUNCTION(lua_newthread, lua_State *, lua_State *L)
GLMODS_GL_LUA_FUNCTION(lua_closethread, int, lua_State *L, lua_State *from)
GLMODS_GL_LUA_FUNCTION(lua_version, lua_Number, lua_State *L)
GLMODS_GL_LUA_FUNCTION(lua_absindex, int, lua_State *L, int idx)
GLMODS_GL_LUA_FUNCTION(lua_gettop, int, lua_State *L)
GLMODS_GL_LUA_FUNCTION(lua_settop, void, lua_State *L, int idx)
GLMODS_GL_LUA_FUNCTION(lua_pushvalue, void, lua_State *L, int idx)
GLMODS_GL_LUA_FUNCTION(lua_rotate, void, lua_State *L, int idx, int n)
GLMODS_GL_LUA_FUNCTION(lua_copy, void, lua_State *L, int fromidx, int toidx)
GLMODS_GL_LUA_FUNCTION(lua_checkstack, int, lua_State *L, int n)
GLMODS_GL_LUA_FUNCTION(lua_xmove, void, lua_State *from, lua_State *to, int n)
GLMODS_GL_LUA_FUNCTION(lua_isnumber, int, lua_State *L, int idx)
GLMODS_GL_LUA_FUNCTION(lua_isstring, int, lua_State *L, int idx)
GLMODS_GL_LUA_FUNCTION(lua_iscfunction, int, lua_State *L, int idx)
GLMODS_GL_LUA_FUNCTION(lua_isinteger, int, lua_State *L, int idx)
GLMODS_GL_LUA_FUNCTION(lua_isuserdata, int, lua_State *L, int idx)
GLMODS_GL_LUA_FUNCTION(lua_type, int, lua_State *L, int idx)
GLMODS_GL_LUA_FUNCTION(lua_typename, const char *, lua_State *L, int tp)
GLMODS_GL_LUA_FUNCTION(lua_tonumberx, lua_Number, lua_State *L, int idx,
                       int *isnum)
GLMODS_GL_LUA_FUNCTION(lua_tointegerx, lua_Integer, lua_State *L, int idx,
                       int *isnum)
GLMODS_GL_LUA_FUNCTION(lua_toboolean, int, lua_State *L, int idx)
GLMODS_GL_LUA_FUNCTION(lua_tolstring, const char *, lua_State *L, int idx,
                       size_t *len)
GLMODS_GL_LUA_FUNCTION(lua_rawlen, lua_Unsigned, lua_State *L, int idx)
GLMODS_GL_LUA_FUNCTION(lua_tocfunction, lua_CFunction, lua_State *L, int idx)
GLMODS_GL_LUA_FUNCTION(lua_touserdata, void *, lua_State *L, int idx)
GLMODS_GL_LUA_FUNCTION(lua_tothread, lua_State *, lua_State *L, int idx)
GLMODS_GL_LUA_FUNCTION(lua_topointer, const void *, lua_State *L, int idx)
GLMODS_GL_LUA_FUNCTION(lua_arith, void, lua_State *L, int op)
GLMODS_GL_LUA_FUNCTION(lua_rawequal, int, lua_State *L, int idx1, int idx2)
GLMODS_GL_LUA_FUNCTION(lua_compare, int, lua_State *L, int idx1, int idx2,
                       int op)
GLMODS_GL_LUA_FUNCTION(lua_pushnil, void, lua_State *L)
GLMODS_GL_LUA_FUNCTION(lua_pushnumber, void, lua_State *L, lua_Number n)
GLMODS_GL_LUA_FUNCTION(lua_pushinteger, void, lua_State *L, lua_Integer n)
GLMODS_GL_LUA_FUNCTION(lua_pushlstring, const char *, lua_State *L,
                       const char *s, size_t len)
GLMODS_GL_LUA_FUNCTION(lua_pushstring, const char *, lua_State *L,
                       const char *s)
GLMODS_GL_LUA_FUNCTION(lua_pushvfstring, const char *, lua_State *L,
                       const char *fmt, va_list argp)
GLMODS_GL_LUA_FUNCTION(lua_pushfstring, const char *, lua_State *L,
                       const char *fmt, ...)
GLMODS_GL_LUA_FUNCTION(lua_pushcclosure, void, lua_State *L, lua_CFunction fn,
                       int n)
GLMODS_GL_LUA_FUNCTION(lua_pushboolean, void, lua_State *L, int b)
GLMODS_GL_LUA_FUNCTION(lua_pushlightuserdata, void, lua_State *L, void *p)
GLMODS_GL_LUA_FUNCTION(lua_pushthread, int, lua_State *L)
GLMODS_GL_LUA_FUNCTION(lua_getglobal, int, lua_State *L, const char *name)
GLMODS_GL_LUA_FUNCTION(lua_gettable, int, lua_State *L, int idx)
GLMODS_GL_LUA_FUNCTION(lua_getfield, int, lua_State *L, int idx, const char *k)
GLMODS_GL_LUA_FUNCTION(lua_geti, int, lua_State *L, int idx, lua_Integer n)
GLMODS_GL_LUA_FUNCTION(lua_rawget, int, lua_State *L, int idx)
GLMODS_GL_LUA_FUNCTION(lua_rawgeti, int, lua_State *L, int idx, lua_Integer n)
GLMODS_GL_LUA_FUNCTION(lua_rawgetp, int, lua_State *L, int idx, const void *p)
GLMODS_GL_LUA_FUNCTION(lua_createtable, void, lua_State *L, int narr, int nrec)
GLMODS_GL_LUA_FUNCTION(lua_newuserdatauv, void *, lua_State *L, size_t sz,
                       int nuvalue)
GLMODS_GL_LUA_FUNCTION(lua_getmetatable, int, lua_State *L, int objindex)
GLMODS_GL_LUA_FUNCTION(lua_getiuservalue, int, lua_State *L, int idx, int n)
GLMODS_GL_LUA_FUNCTION(lua_setglobal, void, lua_State *L, const char *name)
GLMODS_GL_LUA_FUNCTION(lua_settable, void, lua_State *L, int idx)
GLMODS_GL_LUA_FUNCTION(lua_setfield, void, lua_State *L, int idx, const char *k)
GLMODS_GL_LUA_FUNCTION(lua_seti, void, lua_State *L, int idx, lua_Integer n)
GLMODS_GL_LUA_FUNCTION(lua_rawset, void, lua_State *L, int idx)
GLMODS_GL_LUA_FUNCTION(lua_rawseti, void, lua_State *L, int idx, lua_Integer n)
GLMODS_GL_LUA_FUNCTION(lua_rawsetp, void, lua_State *L, int idx, const void *p)
GLMODS_GL_LUA_FUNCTION(lua_setmetatable, int, lua_State *L, int objindex)
GLMODS_GL_LUA_FUNCTION(lua_setiuservalue, int, lua_State *L, int idx, int n)
GLMODS_GL_LUA_FUNCTION(lua_callk, void, lua_State *L, int nargs, int nresults,
                       lua_KContext ctx, lua_KFunction k)
GLMODS_GL_LUA_FUNCTION(lua_pcallk, int, lua_State *L, int nargs, int nresults,
                       int errfunc, lua_KContext ctx, lua_KFunction k)
GLMODS_GL_LUA_FUNCTION(lua_load, int, lua_State *L, lua_Reader reader, void *dt,
                       const char *chunkname, const char *mode)
GLMODS_GL_LUA_FUNCTION(lua_dump, int, lua_State *L, lua_Writer writer,
                       void *data, int strip)
GLMODS_GL_LUA_FUNCTION(lua_yieldk, int, lua_State *L, int nresults,
                       lua_KContext ctx, lua_KFunction k)
GLMODS_GL_LUA_FUNCTION(lua_resume, int, lua_State *L, lua_State *from, int narg,
                       int *nres)
GLMODS_GL_LUA_FUNCTION(lua_status, int, lua_State *L)
GLMODS_GL_LUA_FUNCTION(lua_isyieldable, int, lua_State *L)
GLMODS_GL_LUA_FUNCTION(lua_warning, void, lua_State *L, const char *msg,
                       int tocont)
GLMODS_GL_LUA_FUNCTION(lua_error, int, lua_State *L)
GLMODS_GL_LUA_FUNCTION(lua_next, int, lua_State *L, int idx)
GLMODS_GL_LUA_FUNCTION(lua_concat, void, lua_State *L, int n)
GLMODS_GL_LUA_FUNCTION(lua_len, void, lua_State *L, int idx)
GLMODS_GL_LUA_FUNCTION(lua_stringtonumber, size_t, lua_State *L, const char *s)
GLMODS_GL_LUA_FUNCTION(lua_toclose, void, lua_State *L, int idx)
GLMODS_GL_LUA_FUNCTION(lua_closeslot, void, lua_State *L, int idx)
GLMODS_GL_LUA_FUNCTION(luaL_checkversion_, void, lua_State *L, lua_Number ver,
                       size_t sz)
GLMODS_GL_LUA_FUNCTION(luaL_getmetafield, int, lua_State *L, int obj,
                       const char *e)
GLMODS_GL_LUA_FUNCTION(luaL_callmeta, int, lua_State *L, int obj, const char *e)
GLMODS_GL_LUA_FUNCTION(luaL_tolstring, const char *, lua_State *L, int idx,
                       size_t *len)
GLMODS_GL_LUA_FUNCTION(luaL_argerror, int, lua_State *L, int arg,
                       const char *extramsg)
GLMODS_GL_LUA_FUNCTION(luaL_typeerror, int, lua_State *L, int arg,
                       const char *tname)
GLMODS_GL_LUA_FUNCTION(luaL_checklstring, const char *, lua_State *L, int arg,
                       size_t *l)
GLMODS_GL_LUA_FUNCTION(luaL_optlstring, const char *, lua_State *L, int arg,
                       const char *def, size_t *l)
GLMODS_GL_LUA_FUNCTION(luaL_checknumber, lua_Number, lua_State *L, int arg)
GLMODS_GL_LUA_FUNCTION(luaL_optnumber, lua_Number, lua_State *L, int arg,
                       lua_Number def)
GLMODS_GL_LUA_FUNCTION(luaL_checkinteger, lua_Integer, lua_State *L, int arg)
GLMODS_GL_LUA_FUNCTION(luaL_optinteger, lua_Integer, lua_State *L, int arg,
                       lua_Integer def)
GLMODS_GL_LUA_FUNCTION(luaL_checkstack, void, lua_State *L, int sz,
                       const char *msg)
GLMODS_GL_LUA_FUNCTION(luaL_checktype, void, lua_State *L, int arg, int t)
GLMODS_GL_LUA_FUNCTION(luaL_checkany, void, lua_State *L, int arg)
GLMODS_GL_LUA_FUNCTION(luaL_newmetatable, int, lua_State *L, const char *tname)
GLMODS_GL_LUA_FUNCTION(luaL_setmetatable, void, lua_State *L, const char *tname)
GLMODS_GL_LUA_FUNCTION(luaL_testudata, void *, lua_State *L, int ud,
                       const char *tname)
GLMODS_GL_LUA_FUNCTION(luaL_checkudata, void *, lua_State *L, int ud,
                       const char *tname)
GLMODS_GL_LUA_FUNCTION(luaL_where, void, lua_State *L, int lvl)
GLMODS_GL_LUA_FUNCTION(luaL_error, int, lua_State *L, const char *fmt, ...)
GLMODS_GL_LUA_FUNCTION(luaL_checkoption, int, lua_State *L, int arg,
                       const char *def, const char *const lst[])
GLMODS_GL_LUA_FUNCTION(luaL_fileresult, int, lua_State *L, int stat,
                       const char *fname)
GLMODS_GL_LUA_FUNCTION(luaL_execresult, int, lua_State *L, int stat)
GLMODS_GL_LUA_FUNCTION(luaL_ref, int, lua_State *L, int t)
GLMODS_GL_LUA_FUNCTION(luaL_unref, void, lua_State *L, int t, int ref)
GLMODS_GL_LUA_FUNCTION(luaL_loadfilex, int, lua_State *L, const char *filename,
                       const char *mode)
GLMODS_GL_LUA_FUNCTION(luaL_loadbufferx, int, lua_State *L, const char *buff,
                       size_t sz, const char *name, const char *mode)
GLMODS_GL_LUA_FUNCTION(luaL_loadstring, int, lua_State *L, const char *s)
GLMODS_GL_LUA_FUNCTION(luaL_newstate, lua_State *, void)
GLMODS_GL_LUA_FUNCTION(luaL_len, lua_Integer, lua_State *L, int idx)
GLMODS_GL_LUA_FUNCTION(luaL_gsub, const char *, lua_State *L, const char *s,
                       const char *p, const char *r)
GLMODS_GL_LUA_FUNCTION(luaL_setfuncs, void, lua_State *L, const luaL_Reg *l,
                       int nup)
GLMODS_GL_LUA_FUNCTION(luaL_getsubtable, int, lua_State *L, int idx,
                       const char *fname)
GLMODS_GL_LUA_FUNCTION(luaL_traceback, void, lua_State *L, lua_State *L1,
                       const char *msg, int level)
GLMODS_GL_LUA_FUNCTION(luaL_requiref, void, lua_State *L, const char *modname,
                       lua_CFunction openf, int glb)

#undef GLMODS_GL_LUA_FUNCTION