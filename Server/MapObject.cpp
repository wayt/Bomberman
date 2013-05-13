/*
** MapObject.cpp for Server in /home/fest/Epitech/Bomberman/Server
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon May 13 17:37:58 2013 maxime ginters
** Last update Mon May 13 18:39:01 2013 maxime ginters
*/

#include "MapObject.h"
#include "Map.h"

Position::Position() :
    _posX(0.0f), _posY(0.0f),
    _posZ(0.0f), _orr(0.0f)
{}


float Position::GetPositionX() const
{
    return _posX;
}

float Position::GetPositionY() const
{
    return _posY;
}

float Position::GetPositionZ() const
{
    return _posZ;
}

float Position::GetOrientation() const
{
    return _orr;
}

void Position::GetPosition(float& x, float& y) const
{
    x = _posX;
    y = _posY;
}

void Position::GetPosition(float& x, float& y, float& z) const
{
    x = _posX;
    y = _posY;
    z = _posZ;
}

void Position::GetPosition(float& x, float& y, float& z, float& o) const
{
    x = _posX;
    y = _posY;
    z = _posZ;
    o = _orr;
}

Position const* Position::GetPosition() const
{
    return this;
}

void Position::UpdatePosition(float x, float y, float z, float o)
{
    _posX = x;
    _posY = y;
    _posZ = z;
    _orr = o;
}

MapObject::MapObject(uint32 modelId, std::string const& name) : Position(),
    _modelId(modelId), _isInWorld(false), _currGrid(NULL), _name(name)
{}

void MapObject::SetInWorld(bool in_world)
{
    _isInWorld = in_world;
}

bool MapObject::IsInWorld() const
{
    return _isInWorld;
}

uint32 MapObject::GetModelId() const
{
    return _modelId;
}

std::string const& MapObject::GetName() const
{
    return _name;
}

void MapObject::SetGrid(MapGrid* grid)
{
    if (_currGrid)
        _currGrid->RemoveObject(this);
    _currGrid = grid;
}

void MapObject::SetMap(Map* map)
{
    _map = map;
}
