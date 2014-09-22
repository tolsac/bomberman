//
// MyMap.hh for MyMap in /home/nerevarine/Documents/bomberman-2015-tolsa_c
//
// Made by nerevarine
// Login   <nerevarine@scarlett>
//
// Started on Mon May 28 21:57:52 2012 nerevarine
// Last update Sun Jun  3 15:58:29 2012 nerevarine
//

#ifndef _MYMAP_HH_
#define _MYMAP_HH_

#include "./BombermanCommon.hh"
#include "./Bloc.hh"
#include "./Wall.hh"
#include "./Box.hh"
#include "./Ground.hh"
#include "./Bonus.hh"
#include "./Burn.hh"
#include "./Bomb.hh"

#define C_WALL		'W'
#define C_BOX		'B'
#define C_GROUND	'.'
#define C_BOMB		'X'
#define C_BONUS_P	'P'
#define C_BONUS_S	'S'
#define C_BONUS_B	'O'

class MyMap
{
private:
  int				x;
  int				y;
  Bloc				***map;
  gdl::Image			Wall_;
  gdl::Image			Box_;
  gdl::Image			Ground1_;
  gdl::Image			Ground2_;
  gdl::Image			BonusBombNb_;
  gdl::Image			BonusSpeedAdd_;
  gdl::Image			BonusPortee_;
  gdl::Image			Explosion_;
  std::deque<std::string>	mapsFile;
  std::deque<Vector2d>          lstPlace;

public:
  MyMap();
  ~MyMap();

  int			getX() const;
  int			getY() const;
  Bloc			***getMap() const;

  void			setX(int x);
  void			setY(int y);
  void			setMap(Bloc ***m);

  void			loadMap(std::string const&);
  void			setAt(Bloc*, int const&, int const&);
  Bloc			*getAt(int, int) const;
  void			initialize();
  void			initialize(int const&, int const&);
  void			initialize(std::string const&);
  bool                  checkArea(Vector2d a[8]);
  bool                  getArea(int, int);


  //GAME
  void			generateMap();
  void			generateMap(int const &, int const &);
  std::deque<Vector2d>  getPlace() const;
  void			drawBonus(Bloc *bonus);
  void			draw();
};

std::istream&           operator>>(std::istream& is, MyMap &m);
std::ostream&           operator<<(std::ostream& os, const MyMap &m);

#endif /* !_MYMAP_HH_ */
