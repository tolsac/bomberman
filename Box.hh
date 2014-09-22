//
// Box.hh for Box in /home/nerevarine/Documents/bomberman-2015-tolsa_c
//
// Made by nerevarine
// Login   <nerevarine@scarlett>
//
// Started on Mon May 28 20:47:59 2012 nerevarine
// Last update Tue May 29 17:42:57 2012 nerevarine
//

#ifndef _BOX_HH_
#define _BOX_HH_

#include "./BombermanCommon.hh"
#include "./Bloc.hh"

class		Box : public Bloc
{
 public:
  Box();
  Box(int, int);
  ~Box();

  virtual void		initialize(); // x
  virtual void		update();
  virtual void		draw();
  virtual void		draw(gdl::Image&);
  virtual void		unload();
};

#endif /* !_BOX_HH_ */
