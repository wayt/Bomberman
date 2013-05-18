/*
** Bomb.h for Server in /home/fest/Epitech/Bomberman/Server
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sat May 18 13:40:51 2013 maxime ginters
** Last update Sat May 18 13:54:21 2013 maxime ginters
*/

#ifndef BOMB_H_
# define BOMB_H_

#include "MapObject.h"

class Bomb : public MapObject
{
public:
    explicit Bomb(uint64 guid, MapObject* owner, uint32 mstimer);

    void Update(uint32 const diff);

    void HandleBoum();
private:
    uint32 _timer;
    bool _bommed;
};

#endif /* !BOMB_H_ */
