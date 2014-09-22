//
// Bloc.cpp for Bloc in /home/clariv_e//Projets/C++/Bomberman/bomberman-2015-tolsa_c
//
// Made by erick clarivet
// Login   <clariv_e@epitech.net>
//
// Started on  Tue May 29 04:58:12 2012 erick clarivet
// Last update Fri Jun  1 14:13:19 2012 camille tolsa
//

#include	"Bloc.hh"

Bloc::Bloc() : position(0.0f, 0.0f, 0.0f)
{
}

Bloc::Bloc(int x, int y)
  : position((x * BLOCKSIZE),
	     (y * BLOCKSIZE), 0.0f)
{
}

Bloc::~Bloc()
{
}

int		Bloc::getX() const
{
  return (this->position.x);
}

int		Bloc::getY() const
{
  return (this->position.y);
}

e_type		Bloc::getType() const
{
  return (this->type);
}

Vector3f	Bloc::getPos() const
{
  return (this->position);
}
