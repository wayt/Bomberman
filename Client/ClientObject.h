/*
** ClientObject.h for Client in /home/fest/Epitech/Bomberman/Client
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed May 15 15:33:34 2013 maxime ginters
** Last update Fri May 24 18:05:46 2013 maxime ginters
*/

#ifndef CLIENTOBJECT_H_
# define CLIENTOBJECT_H_

#include "GraphicObject.h"
#include "Position.h"
#include "MotionMaster.hpp"

typedef SharedPtr<ClientObject> ClientObjectPtr;

class ClientObject : public Position
{
public:
    ClientObject(uint64 guid, uint32 modelid, std::string const& name);
    virtual ~ClientObject();

    uint64 GetGUID() const;
    uint32 GetModelId() const;
    GraphicObject &GetGraphicObject();
    std::string const& GetName() const;

    void Update(uint32 const diff);

private:
    uint64 _guid;
    uint32 _modelId;
    std::string _name;
    GraphicObject _graphicObject;
    MotionMaster* _motionMaster;
};

#endif /* !CLIENTOBJECT_H_ */
