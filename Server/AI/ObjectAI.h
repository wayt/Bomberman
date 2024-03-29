/*
** ObjectAI.h for AI in /home/fest/Epitech/Bomberman/Server/AI
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue May 21 17:36:35 2013 maxime ginters
** Last update Fri Jun 07 00:11:54 2013 maxime ginters
*/

#ifndef OBJECTAI_H_
# define OBJECTAI_H_

#include "luabind.h"

#include <iostream>
#include <string>
#include "Shared.h"

#define LUA_RUNTIME_ERROR(a) sLog->error("LUA ERROR: %s", lua_tostring(a, -1))

class Object;
class MapObject;

class ObjectAI
{
public:
    explicit ObjectAI(Object* obj, std::string const& file);
    virtual ~ObjectAI();

    bool Initialize();
    bool ReloadLua();

    void UpdateAI(uint32 const diff);
    void HandleHit(MapObject* obj);
    void HandleCross(MapObject* by);
    void HandleRespawn();
    void HandlePathGenerated();
    void HandleFailToCreatePath();
    void HandleFinishMovePoint();
    void HandleBombBoum();

private:
    Object* _me;
    std::string _file;
    lua_State* _luastate;
};

#endif /* !OBJECTAI_H_ */
