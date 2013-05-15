/*
** Camera.cpp for  in /home/vaga/Projects/tek2/bomberman
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Wed May 15 12:59:41 2013 fabien casters
** Last update Wed May 15 17:53:05 2013 fabien casters
*/

#include "Camera.h"
#include <GL/gl.h>
#include <GL/glu.h>

Camera::Camera() :
    _pos(0, -70.0f, 30.0f), _rot(0.0f, 0.0f, 0.0f)
{

}

void Camera::initialize()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 800.0f / 600.0f, 1.0f, 3000.0f);
    gluLookAt(_pos.x, _pos.y, _pos.z, 20.f, 20.0f, 0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}

void Camera::update(gdl::GameClock const &, gdl::Input &)
{
    // TODO
}
