//
// Bomb.hh for Bomb in /home/nerevarine/Documents/bomberman-2015-tolsa_c
//
// Made by nerevarine
// Login   <nerevarine@scarlett>
//
// Started on Mon May 28 20:55:23 2012 nerevarine
// Last update Sun Jun  3 00:39:45 2012 nerevarine
//

#ifndef _BOMB_HH_
#define _BOMB_HH_

#include "./BombermanCommon.hh"
#include "./Bloc.hh"

class		Bomb : public Bloc
{
private:
  int		id;
  int		portee;
  Vector3f	gonfle;
  gdl::Model	bomb;
public:
  Bomb(int, int);
  Bomb(int, int, int, int);
  ~Bomb();

  int			getId() const;
  int			getPortee() const;

  void			setId(int const &id_);
  void			setPortee(int const& p);

  void		initialize();
  void		update();
  void		draw();
  void		draw(gdl::Image&){}
  void		unload();
};

#endif /* !_BOMB_HH_ */
