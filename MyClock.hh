//
// MyClock.hh for MyClock in /home/nerevarine/Documents/bomberman-2015-tolsa_c
//
// Made by nerevarine
// Login   <nerevarine@scarlett>
//
// Started on Mon May 28 22:55:08 2012 nerevarine
// Last update Sun Jun  3 16:06:02 2012 nerevarine
//

#ifndef _MYCLOCK_HH_
#define _MYCLOCK_HH_

#include "./BombermanCommon.hh"

class			MyClock
{
public:
  gdl::Clock		cl;
  int			id;
  int			bombX;
  int			bombY;
  bool			fire;

public:
  MyClock();
  MyClock(int const&, int const&, int);
  ~MyClock();

  void			setId(int);

  int			getId() const;

  void			init();
  bool			update();
  // float			getElapsedTime() const;
};

std::istream&		operator>>(std::istream &is, MyClock &c);
std::ostream&		operator<<(std::ostream &os, const MyClock &c);

#endif /* !_MYCLOCK_HH_ */
