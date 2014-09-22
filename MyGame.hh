//
// MyGame.hh for MyGame in /home/nerevarine/Documents/NewBomberman
//
// Made by nerevarine
// Login   <nerevarine@scarlett>
//
// Started on Mon May 28 16:50:38 2012 nerevarine
// Last update Sun Jun  3 21:45:21 2012 nerevarine
//

#ifndef _MYGAME_HH_
#define _MYGAME_HH_

#include "./BombermanCommon.hh"
#include "./Bomberman.hh"
#include "./Player.hh"
#include "./IA.hh"
#include "./MyClock.hh"
#include "./MyMap.hh"
#include "./Camera.hh"
#include "./Menu.hh"
#include "./Bonus.hh"
#include "./Bomb.hh"
#include "./MyMusic.hh"

class				MyGame : public gdl::Game
{
private:
  unsigned int			nbPlayers;
  int				nbIAs;
  int				levelIA;
  int				x;
  int				y;
  Camera			cam;
  MyMap				map;
  bool				pause;
  std::string			chosenMap;
  std::deque<gdl::Keys::Key>	dequeKeys;
  std::deque<Player>		lstPlayersHuman;
  std::deque<IA>		lstPlayersIA;
  std::deque<MyClock>		lstTimer;
  std::deque<Menu>		lstMenu;
  MyMusic			muse;
  gdl::Text			p;

public:
  MyGame();
  ~MyGame();

  //MENU FUNCTIONS
  void				launchMenu();
  void				subMenuNewGame();
  void				subMenuLoadGame();
  void				subMenuOptions();
  void				subMenuExit();
  void				launchGame();
  void				pauseMenu();

  //MOVE FUNCTIONS
  void				getKeys();
  void				move(e_direction, Bomberman&);
  void				findFocus(IA &);
  void				drop(Bomberman &);
  void				explose(int x, int y);
  void				deflag(int x, int y, unsigned int portee);

  //SAVE & LOAD
  void				save() const;
  void				load(std::string const &filename);

  //GDL
  void				initialize();
  void				update();
  void				draw();
  void				unload();
};

#endif /* !MYGAME_HH_ */
