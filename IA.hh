//
// IA.hh for IA in /home/nerevarine/Documents/bomberman-2015-tolsa_c
//
// Made by nerevarine
// Login   <nerevarine@scarlett>
//
// Started on Mon May 28 21:52:41 2012 nerevarine
// Last update Sun Jun  3 16:37:06 2012 nerevarine
//

#ifndef _IA_HH_
#define _IA_HH_

#include "./BombermanCommon.hh"
#include "./Bomberman.hh"
#include "./Player.hh"
#include "./Bloc.hh"

class			IA : public Bomberman
{
 private:
  bool			activ;

 public:
  IA();
  IA(int, int, int);
  ~IA();

  bool			getActiv() const;

  void			setActiv(bool);

  virtual void		initialize();
  virtual void		update();
  virtual void		draw();
  virtual void		unload();

  void			findFocus(std::deque<Player>);
  int			getStockBomb() const;
  void			setStockBomb(int);
};

std::istream&		operator>>(std::istream& is, IA &p);
std::ostream&		operator<<(std::ostream& os, const IA &p);

#endif /* !_IA_HH_ */
