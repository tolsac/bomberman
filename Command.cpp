//
// command.cpp for command in /home/clariv_e//Projets/C++/Bomberman/bomberman
//
// Made by erick clarivet
// Login   <clariv_e@epitech.net>
//
// Started on  Tue May 22 18:58:57 2012 erick clarivet
// Last update Sun Jun  3 01:31:36 2012 nerevarine
//

#include	"./Command.hh"

Command::Command()
{
  this->up_ = gdl::Keys::Up;
  this->down_ = gdl::Keys::Down;
  this->left_ = gdl::Keys::Left;
  this->right_ = gdl::Keys::Right;
  this->bomb_ = gdl::Keys::Space;
}

Command::Command(gdl::Keys::Key up, gdl::Keys::Key down, gdl::Keys::Key left, gdl::Keys::Key right, gdl::Keys::Key bomb)
{
  this->up_ = up;
  this->down_ = down;
  this->left_ = left;
  this->right_ = right;
  this->bomb_ = bomb;
}

Command&		Command::operator=(const Command& command)
{
  this->up_ = command.up_;
  this->down_ = command.down_;
  this->left_ = command.left_;
  this->right_ = command.right_;
  this->bomb_ = command.bomb_;
  return (*this);
}

gdl::Keys::Key		Command::getUp() const
{
  return this->up_;
}

gdl::Keys::Key		Command::getDown() const
{
  return this->down_;
}

gdl::Keys::Key		Command::getLeft() const
{
  return this->left_;
}

gdl::Keys::Key		Command::getRight() const
{
  return this->right_;
}

gdl::Keys::Key		Command::getBomb() const
{
  return this->bomb_;
}

void			Command::setUp(gdl::Keys::Key u)
{
  this->up_ = u;
}

void			Command::setDown(gdl::Keys::Key d)
{
  this->down_ = d;
}

void			Command::setLeft(gdl::Keys::Key l)
{
  this->left_ = l;
}

void			Command::setRight(gdl::Keys::Key r)
{
  this->right_ = r;
}

void			Command::setBomb(gdl::Keys::Key b)
{
  this->bomb_ = b;
}


std::istream&		operator>>(std::istream &is, Command &c)
{
  int			intTmp;

  is >> intTmp;
  c.setUp((gdl::Keys::Key) intTmp);
  is >> intTmp;
  c.setDown((gdl::Keys::Key) intTmp);
  is >> intTmp;
  c.setLeft((gdl::Keys::Key) intTmp);
  is >> intTmp;
  c.setRight((gdl::Keys::Key) intTmp);
  is >> intTmp;
  c.setBomb((gdl::Keys::Key) intTmp);
  return (is);
}

std::ostream&		operator<<(std::ostream &os, const Command &c)
{
  os << c.getUp() << std::endl;;
  os << c.getDown() << std::endl;
  os << c.getLeft() << std::endl;
  os << c.getRight() << std::endl;
  os << c.getBomb() << std::endl;
  return(os);
}
