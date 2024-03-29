/*
** Player.cpp for Server in /home/fest/Epitech/Bomberman/Server
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue May 14 14:49:16 2013 maxime ginters
** Last update Thu Jun 06 15:09:42 2013 maxime ginters
*/

#include "Player.h"
#include "Session.h"
#include "Map.h"

Player::Player(uint64 guid, std::string const& name, Session* sess) :
    MapObject(guid, MODELID_PLAYER, TYPEID_PLAYER, name),
    _session(sess)
{}

void Player::SetGrid(MapGrid* grid)
{
    MapGrid* oldGrid = _currGrid;
    MapObject::SetGrid(grid);

    if (_map && grid)
    {
        uint8 flags = _map->BuildGridUpdaterFlags(oldGrid, _currGrid);
        _map->GridUpdater(this, GRIDUPDATE_ACTIVE, flags);
    }
    if (oldGrid)
    {
        Packet data(SMSG_GRID_CHANGE_NOTIFY, 16);
        WritePosition(data);
        SendPacket(data);
    }
}

Session* Player::GetSession()
{
    return _session;
}

void Player::SendPacket(Packet const& data)
{
    _session->SendPacket(data);
}

void Player::HandleLogout()
{
    if (_map)
        _map->RemoveObject(this);
}

bool Player::HandleHit(MapObject* obj)
{
    if (!MapObject::HandleHit(obj))
        return false;

    Kill(obj);
    return true;
}

void Player::Update(uint32 const diff)
{
    MapObject::Update(diff);
}

void Player::HandleRespawn()
{
    MapObject::HandleRespawn();
}
