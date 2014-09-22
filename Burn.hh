//
// Wall.hh for Wall in /home/nerevarine/Documents/bomberman-2015-tolsa_c
//
// Made by nerevarine
// Login   <nerevarine@scarlett>
//
// Started on Mon May 28 20:45:38 2012 nerevarine
// Last update Sat Jun  2 16:16:17 2012 camille tolsa
//

#ifndef _BURN_HH_
#define _BURN_HH_

#include "./BombermanCommon.hh"
#include "./Bloc.hh"

class		Burn : public Bloc
{
 public:
  Burn();
  Burn(int, int);
  Burn(int, int, bool);
  ~Burn();

  gdl::Clock&		getClock();
  bool			getFire() const;
  bool                  getB() const;

  virtual void		initialize();
  virtual void          update(gdl::GameClock const&, gdl::Input &);
  virtual void          update();
  virtual void		draw();
  virtual void          draw(gdl::Image&);
  virtual void		unload();
private:
  gdl::Clock            timer_;
  bool			fire;
  bool			b_;
};

#endif /* !_WALL_HH_ */
