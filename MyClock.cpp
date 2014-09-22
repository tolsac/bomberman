//
// MyClock.cpp for  in /home/tolsa_c//svncapue/bomberman-2015-tolsa_c
//
// Made by camille tolsa
// Login   <tolsa_c@epitech.net>
//
// Started on  Tue May 29 07:43:22 2012 camille tolsa
// Last update Sun Jun  3 16:16:19 2012 nerevarine
//

#include "MyClock.hh"

MyClock::MyClock()
{
}

MyClock::MyClock(int const& x, int const& y, int _id) : bombX(x), bombY(y)
{
  this->cl.play();
  this->id = _id;
  this->fire = false;
}

MyClock::~MyClock()
{
}

void			MyClock::init()
{
  this->cl.play();
}

bool			MyClock::update()
{
  this->cl.update();
  if (this->cl.getTotalElapsedTime() > 3.0f || this->fire == true)
    return (true);
  return (false);
}

void			MyClock::setId(int _id)
{
  this->id = _id;
}

int			MyClock::getId() const
{
  return (this->id);
}

std::istream&		operator>>(std::istream &is, MyClock &c)
{
  is >> c.id;
  is >> c.bombX;
  is >> c.bombY;
  is >> c.fire;
  c.init();
  return (is);
}

std::ostream&		operator<<(std::ostream &os, const MyClock &c)
{
  os << c.id << std::endl;
  os << c.bombX << std::endl;
  os << c.bombY << std::endl;
  os << c.fire << std::endl;
  return (os);
}
