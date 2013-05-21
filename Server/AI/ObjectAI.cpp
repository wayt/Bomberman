/*
** ObjectAI.cpp for AI in /home/fest/Epitech/Bomberman/Server/AI
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue May 21 17:36:49 2013 maxime ginters
** Last update Tue May 21 18:58:06 2013 maxime ginters
*/

#include "ObjectAI.h"
#include "Object.h"

ObjectAI::ObjectAI(Object* obj, std::string const& file) : _me(obj),
    _file(file), _luastate(NULL)
{}

ObjectAI::~ObjectAI()
{}

bool ObjectAI::Initialize()
{
    _luastate = luaL_newstate();
    if (!_luastate)
        return false;

    try
    {
        luabind::open(_luastate);
        Object::RegisterLua(_luastate);
        luabind::module(_luastate) [
            luabind::class_<Log>("Log")
            .def("print", &Log::print)
            ];
        luabind::globals(_luastate)["Log"] = sLog;

    }
    catch (std::exception const& e)
    {
        sLog->error("Error : %s", e.what());
        return false;
    }

    return ReloadLua();
}

bool ObjectAI::ReloadLua()
{
    if (!_luastate)
    {
        sLog->error("Error : can't reload lua, no luastate");
        return false;
    }
    if (luaL_dofile(_luastate, _file.c_str()) != 0)
    {
        sLog->error("Error : fail to do lua file");
        return false;
    }

    LUA_RUNTIME_PROTECT(
            luabind::call_function<void>(_luastate, "LoadScript", _me)
    );
    return true;
}

void ObjectAI::UpdateAI(uint32 const diff)
{
    if (!_luastate)
        return;

    LUA_RUNTIME_PROTECT(
            luabind::call_function<void>(_luastate, "UpdateAI", _me, diff)
    );
}