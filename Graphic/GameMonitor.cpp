/*
** GameMonitor.cpp for  in /home/vaga/Projects/tek2/bomberman
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Mon May 06 18:45:22 2013 fabien casters
** Last update Fri May 17 14:08:01 2013 maxime ginters
*/

#include <iostream>
#include "GameMonitor.h"
#include "Client.h"

GameMonitor::GameMonitor(Client *cli, uint32 width, uint32 height) :
    _client(cli), _width(width), _height(height), _cam(),
    _keyVector(gdl::Keys::Count, false)
{
}

void GameMonitor::initialize(void)
{
    window_.create();
    _cam.initialize();
}

void GameMonitor::update(void)
{
    _cam.update(gameClock_, input_);
    for (uint32 i = 0; i < gdl::Keys::Count; ++i)
        _keyVector[i] = input_.isKeyDown((gdl::Keys::Key)i);
}

void GameMonitor::draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
    glClearDepth(1.0f);

    glBegin(GL_LINES);
    glColor3ub(255, 0, 0); // Rouge
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 20.0, 0.0);
    glColor3ub(0, 0, 255); // Bleu
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(20.0, 0.0, 0.0);
    glColor3ub(0, 255, 0); // Vert
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 255); // Bleu
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, _height, 0.0f);
    glVertex3f(_width, _height, 0.0f);
    glVertex3f(_width, 0.0f, 0.0f);
    glEnd();

    std::map<uint64, ClientObject *> const &map = _client->GetObjectMap();
    std::map<uint64, ClientObject *>::const_iterator iter;
    for(iter = map.begin(); iter != map.end(); ++iter)
        iter->second->GetModel().draw();
    if (ClientObject* obj = _client->GetPlayer())
        obj->GetModel().draw();

    window_.display();
}

void GameMonitor::unload(void)
{
}

void GameMonitor::getKeyVector(std::vector<bool>& vec) const
{
    vec = _keyVector;
}