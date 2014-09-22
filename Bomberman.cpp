//
// Bomberman.cpp for  in /home/barnet_m//Tek2/bomberman/bomberman-2015-tolsa_c
//
// Made by mathieu barnetche
// Login   <barnet_m@epitech.net>
//
// Started on  Tue May 29 11:17:00 2012 mathieu barnetche
// Last update Sun Jun  3 02:44:26 2012 mathieu barnetche
//

#include "Bomberman.hh"

Bomberman::Bomberman()
{
}

Bomberman::Bomberman(int x, int y, int R, int G, int B, int s)
{
  gdl::Color	color(R, G, B, 255);

  this->position.x = x * BLOCKSIZE;
  this->position.y = y * BLOCKSIZE;
  this->position.z = 0;
  this->color_ = color;
  this->speed = 1.0f + s;
  this->portee = PORTEE_BOMB;
  this->timer_.play();
}

Bomberman::~Bomberman()
{
}

Vector3f              Bomberman::getPos() const
{
  return (this->position);
}

float                   Bomberman::getXf() const
{
  return (this->position.x + (BLOCKSIZE / 2));
}

float                   Bomberman::getYf() const
{
  return (this->position.y + (BLOCKSIZE / 2));
}

int                   Bomberman::getAngle() const
{
  return (this->angle);
}

float                 Bomberman::getSpeed() const
{
  return (this->speed);
}


int                   Bomberman::getPortee() const
{
  return this->portee;
}

void                  Bomberman::setPortee(const int& portee_)
{
  this->portee = portee_;
}

int			Bomberman::getId() const
{
  return (this->id);
}

void		      Bomberman::setId(int i)
{
  this->id = i;
}

void                  Bomberman::setPos(Vector3f const&p)
{
  this->position = p;
}

void                  Bomberman::setPos(float const& x, float const& y, float const& z)
{
  this->position.y = y;
  this->position.x = x;
  this->position.z = z;
}

void                  Bomberman::setAngle(int const &a)
{
  this->angle = a;
}

void                  Bomberman::setSpeed(float const&s)
{
  this->speed = s;
}

int		      Bomberman::getStockBomb() const
{
  return (this->stockbomb);
}

void		      Bomberman::setStockBomb(int s)
{
  this->stockbomb = s;
}
