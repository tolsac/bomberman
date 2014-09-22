//
// Ground.hh for Ground in /home/nerevarine/Documents/bomberman-2015-tolsa_c
//
// Made by nerevarine
// Login   <nerevarine@scarlett>
//
// Started on Mon May 28 20:45:38 2012 nerevarine
// Last update Tue May 29 18:30:18 2012 nerevarine
//

#ifndef _GROUND_HH_
#define _GROUND_HH_

#include "./BombermanCommon.hh"
#include "./Bloc.hh"

class		Ground : public Bloc
{
 public:
  Ground();
  Ground(int, int);
  ~Ground();

  virtual void		initialize();
  virtual void		update();
  virtual void		draw();
  virtual void		draw(gdl::Image& texture);
  void			draw(gdl::Image& texture, int x, int y);
  virtual void		unload();
};

#endif /* !_GROUND_HH_ */
