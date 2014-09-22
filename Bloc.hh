//
// Bloc.hh for Bloc in /home/nerevarine/Documents/bomberman-2015-tolsa_c
//
// Made by nerevarine
// Login   <nerevarine@scarlett>
//
// Started on Mon May 28 20:32:34 2012 nerevarine
// Last update Fri Jun  1 14:13:50 2012 camille tolsa
//

#ifndef _BLOC_HH_
#define _BLOC_HH_

#include	"Game.hpp"
#include	"Clock.hpp"
#include	"Color.hpp"
#include	"GameClock.hpp"
#include	"Image.hpp"
#include	"Input.hpp"
#include	"Model.hpp"
#include	"Window.hpp"
#include	"BombermanCommon.hh"

class		Bloc
{
protected:
  Vector3f	position;
  e_type	type;

public:
  Bloc();
  Bloc(int x, int y);
  ~Bloc();

  Vector3f		getPos() const;
  int			getX() const;
  int			getY() const;
  e_type		getType() const;
  bool			getB() const;

  void			setB(bool);
  virtual void		initialize() = 0;
  virtual void		update() = 0;
  virtual void		draw() = 0;
  virtual void		draw(gdl::Image &) = 0;
  virtual void		unload() = 0;
};

#endif /* !_BLOC_HH_ */
