//
// Wall.hh for Wall in /home/nerevarine/Documents/bomberman-2015-tolsa_c
//
// Made by nerevarine
// Login   <nerevarine@scarlett>
//
// Started on Mon May 28 20:45:38 2012 nerevarine
// Last update Tue May 29 17:30:10 2012 nerevarine
//

#ifndef _WALL_HH_
#define _WALL_HH_

#include "./BombermanCommon.hh"
#include "./Bloc.hh"

class		Wall : public Bloc
{
 public:
  Wall();
  Wall(int, int);
  ~Wall();

  virtual void		initialize();
  virtual void          update(gdl::GameClock const&, gdl::Input &);
  virtual void          update();
  virtual void		draw();
  virtual void          draw(gdl::Image&);
  virtual void		unload();
};

#endif /* !_WALL_HH_ */
