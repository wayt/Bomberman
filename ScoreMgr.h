/*
** ScoreMgr.h for Bomberman in /home/fest/Epitech/Bomberman
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Jun 03 17:58:56 2013 maxime ginters
** Last update Fri Jun 07 19:21:45 2013 maxime ginters
*/

#ifndef SCOREMGR_H_
# define SCOREMGR_H_

#include <map>
#include "Shared.h"
#include "Packet.hpp"

class GameObject;

struct Score
{
    std::string name;
    uint32 died;
    uint32 killed;
    uint32 bomb;
    uint32 wall;
};

class ScoreMgr
{
public:
    ScoreMgr();

    void AddPlayer(GameObject* obj);
    void AddPlayer(uint64 guid, Score* sc);
    void RemovePlayer(uint64 guid);
    Score const* GetScore(uint64 guid) const;
    Score* GetScore(uint64 guid);
    std::map<uint64, Score*>::const_iterator ScoreBegin() const;
    std::map<uint64, Score*>::const_iterator ScoreEnd() const;

    void WriteScores(Packet& data, uint64 guid = 0) const;
    void ReadScores(Packet& data);

    void SaveScore() const;

private:
    std::map<uint64, Score*> _scores;
};

#endif /* !SCOREMGR_H_ */
