#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>
#include <sched.h>
#include <stdlib.h>
#include <sys/param.h>
#include <time.h>
#include <uv.h>

static uv_loop_t* loop = NULL;

int
open_el(lua_State* L)
{
  if (loop != NULL)
  {
    lua_pushinteger(L, -1);
    return 1;
  }
  loop = malloc(sizeof(uv_loop_t));
  if (uv_loop_init(loop) != 0)
  {
    free(loop);
    loop = NULL;
    lua_pushinteger(L, -2); // Error during init
    return 1;
  }
  lua_pushinteger(L, 1);
  return 1;
}

int
close_el(lua_State* L)
{
  if (loop == NULL)
  {
    lua_pushnumber(L, -1);
    return 1;
  }
  if (uv_loop_close(loop) != 0)
  {
    lua_pushinteger(L, -2); // Error during close
    return 1;
  }
  free(loop);
  lua_pushnumber(L, 1);
  return 1;
}

static const struct luaL_Reg uv[] = {
    {"open_el", open_el},
    {"close_el", close_el},
    {NULL, NULL},
};

int
luaopen_lasyncio_uv(lua_State* L)
{
  luaL_newlib(L, uv);
  return 1;
}
