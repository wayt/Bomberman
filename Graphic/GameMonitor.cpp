/*
** GameMonitor.cpp for  in /home/vaga/Projects/tek2/bomberman
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Mon May 06 18:45:22 2013 fabien casters
** Last update Tue May 28 16:49:19 2013 maxime ginters
*/

#include <iostream>
#include "GameMonitor.h"
#include "Client.h"
#include "Text.hpp"
#include "ModelFactory.h"

GameMonitor::GameMonitor(Client *cli, uint32 width, uint32 height) :
    _client(cli), _width(width), _height(height), _cam(),
    _keyVector(gdl::Keys::Count, false)
{
}

void GameMonitor::initialize(void)
{
    window_.create();
    _cam.initialize();
    sModelFactory->init("models.cfg");
}

void GameMonitor::update(void)
{
    std::map<uint64, ClientObjectPtr> map;
    _client->GetObjectMap(map);
    std::map<uint64, ClientObjectPtr>::iterator iter;
    for(iter = map.begin(); iter != map.end(); ++iter)
        iter->second->GetGraphicObject().update(gameClock_);
    ClientObjectPtr obj = _client->GetPlayer();
    if (obj.get())
        obj->GetGraphicObject().update(gameClock_);

    _cam.update(_client->GetPlayer());
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
    glColor3ub(0x99, 0x6F, 0x3A);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, _height, 0.0f);
    glVertex3f(_width, _height, 0.0f);
    glVertex3f(_width, 0.0f, 0.0f);
    glEnd();

    std::map<uint64, ClientObjectPtr> map;
    _client->GetObjectMap(map);
    std::map<uint64, ClientObjectPtr>::iterator iter;
    for(iter = map.begin(); iter != map.end(); ++iter)
        iter->second->GetGraphicObject().draw();
    ClientObjectPtr obj = _client->GetPlayer();
    if (obj.get())
        obj->GetGraphicObject().draw();

    //glClear(GL_DEPTH_BUFFER_BIT);


    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 100, 0);
    glVertex3f(300, 100, 0);
    glVertex3f(300, 0, 0);
    glEnd();



    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);


    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glPushAttrib(GL_COLOR_BUFFER_BIT | GL_CURRENT_BIT   | GL_ENABLE_BIT  |
            GL_TEXTURE_BIT      | GL_TRANSFORM_BIT | GL_VIEWPORT_BIT);

    glDisable(GL_ALPHA_TEST);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);

    glColor3f(0, 0, 0);

    std::list<std::string> messages;
    _client->GetChatBox().GetMessageList(messages);
    uint8 i = 1;
    static uint32 font_size = 12;

    for (std::list<std::string>::const_reverse_iterator itr = messages.rbegin(); itr != messages.rend(); ++itr)
    {
        gdl::Text prompt;
        prompt.setText(*itr);
        prompt.setPosition(10, (window_.getHeight() - (2 * font_size)) - (i * font_size));
        prompt.setSize(font_size);
        //prompt.setFont("Assets/SIXTY.TTF");
        prompt.draw();
        ++i;

    }
    // Drawing text
    if (_client->GetChatBox().IsOpen())
    {
        std::stringstream ss;
        ss << _client->GetPlayer()->GetName();
        ss << " : ";
        ss << _client->GetChatBox().GetInputString();

        gdl::Text prompt;
        prompt.setText(ss.str());
        prompt.setPosition(10, window_.getHeight() - (2 * font_size));
        prompt.setSize(font_size);
        //prompt.setFont("Assets/SIXTY.TTF");
        prompt.draw();
    }

    // After drawing the text
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glPopAttrib();


    window_.display();

    usleep(25000);

}

void GameMonitor::unload(void)
{
}

void GameMonitor::getKeyVector(std::vector<bool>& vec) const
{
    vec = _keyVector;
}
