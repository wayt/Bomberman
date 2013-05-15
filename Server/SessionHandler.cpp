/*
** SessionHandler.cpp for Server in /home/fest/Epitech/Bomberman/Server
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri May 10 15:42:46 2013 maxime ginters
** Last update Wed May 15 17:54:13 2013 fabien casters
*/

#include "Session.h"
#include "Map.h"
#include "Server.h"

void Session::HandleLoginPlayer(Packet& recvData)
{
    std::string name;
    recvData >> name;

    std::cout << "Player name : " << name << std::endl;
    // Check nick availability

    _status = STATUS_AUTHED;
    Map* map = _server->GetMap();
    _player = new Player(map->MakeNewGuid(), name, this);

    Packet data(SMSG_LOGIN_RESPONSE, 9);
    data << uint8(LOGIN_RESPONSE_OK);
    data << uint64(_player->GetGUID());
    SendPacket(data);
}

void Session::HandleEnterGame(Packet& recvData)
{
    (void)recvData;

    uint32 width, height;

    Map* map = _server->GetMap();
    map->GetWidthAndHeight(width, height);

    Packet data(SMSG_ADD_TO_MAP, 24);
    data << uint32(width * MAP_PRECISION);
    data << uint32(height * MAP_PRECISION);
    data << uint32(_player->GetModelId());
    _player->UpdatePosition(150.0f, 150.0f, 0.0f, 0.0f);
    _player->WritePosition(data);

    SendPacket(data);

    map->AddObject(_player);
}
