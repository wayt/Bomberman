/*
** MovementPlayer.h for Server in /home/fest/Epitech/Bomberman/Server
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed May 15 13:31:19 2013 maxime ginters
** Last update Wed May 29 18:24:23 2013 vincent leroy
*/

#ifndef MOVEMENTPLAYER_H_
# define MOVEMENTPLAYER_H_

#include "MotionMaster.hpp"

class MovementPlayer : public AMovement
{
public:
    MovementPlayer(GameObject* obj);

    void Initialize();
    void Update(uint32 const diff);
    void Finish();
    void Abort(MovementTypes newType);

private:
    void CollisionManager(float x, float y, float angle, float dist, float &dx, float &dy) const;
    bool AlreadyInWall(const GameObject* obj) const;
};

#endif /* !MOVEMENTPLAYER_H_ */
