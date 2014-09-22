//
// Bomb.cpp for  in /home/tolsa_c//collisions
//
// Made by camille tolsa
// Login   <tolsa_c@epitech.net>
//
// Started on  Fri Jun  1 14:41:04 2012 camille tolsa
// Last update Sun Jun  3 17:08:54 2012 nerevarine
//

#include "Bomb.hh"

Bomb::Bomb(int _x, int _y)
{
  this->position.x = _x * BLOCKSIZE;
  this->position.y = _y * BLOCKSIZE;
  this->type = BOMB;
  this->bomb = gdl::Model::load("lib/assets/bomb.fbx");
}

Bomb::Bomb(int _x, int _y, int _id, int _portee)
{
  this->position.x = _x * BLOCKSIZE;
  this->position.y = _y * BLOCKSIZE;
  this->id = _id;
  this->portee = _portee;
  this->type = BOMB;
  this->bomb = gdl::Model::load("lib/assets/bomb.fbx");
}

Bomb::~Bomb()
{
}

int		Bomb::getId() const
{
  return (this->id);
}

int		Bomb::getPortee() const
{
  return (this->portee);
}

void		Bomb::setId(int const& _id)
{
  this->id = _id;
}

void		Bomb::setPortee(int const& _portee)
{
  this->portee = _portee;
}

void		Bomb::initialize()
{

}

void		Bomb::update()
{
  //this->bomb.update();
  static bool   what = true;
  static int    it = 0;

  if (what)
    {
      this->gonfle.x = 0.4;
      this->gonfle.y = 0.4;
      this->gonfle.z = 0.4;
    }
  else
    {
      this->gonfle.x = 0.3;
      this->gonfle.y = 0.3;
      this->gonfle.z = 0.3;
    }
  it++;
  if (it == 60)
    {
      what = !what;
      it = 0;
    }
}

void		Bomb::draw()
{
  glPushMatrix();
  glTranslatef(position.x,
               position.y,
               -(BLOCKSIZE/2));
  glRotatef(90.f, 2.0f, 0.0f, 0.0f);
  glRotatef(90.f, 0.0f, 1.0f, 0.0f);
  glScalef(this->gonfle.x, // homothétie sur l'axe X
           this->gonfle.y,// homothétie sur l'axe Y
           this->gonfle.z); // homothetie sur l'axe Z
  this->bomb.draw();
  glPopMatrix();
}

void		Bomb::unload()
{

}
