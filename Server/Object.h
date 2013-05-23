/*
** Object.h for Server in /home/fest/Epitech/Bomberman/Server
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue May 21 17:55:11 2013 maxime ginters
** Last update Thu May 23 19:01:33 2013 maxime ginters
*/

#ifndef OBJECT_H_
# define OBJECT_H_

#include "MapObject.h"

class ObjectAI;
struct lua_State;

class Object : public MapObject
{
public:
    Object(uint64 guid, uint32 modelId, std::string const& name);
    virtual ~Object();

    ObjectAI* GetAI();

    bool InitializeAI(std::string const& filename);
    bool ReloadAI();

    virtual void Update(uint32 const diff);

    void Despawn();

    static void RegisterLua(lua_State* state);
private:
    ObjectAI* _AI;
};

#endif /* !OBJECT_H_ */
