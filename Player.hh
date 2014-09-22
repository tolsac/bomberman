//
// Player.hh for Player in /home/nerevarine/Documents/bomberman-2015-tolsa_c
//
// Made by nerevarine
// Login   <nerevarine@scarlett>
//
// Started on Mon May 28 21:46:01 2012 nerevarine
// Last update Sun Jun  3 17:02:17 2012 nerevarine
//

#ifndef _PLAYER_HH_
#define _PLAYER_HH_

#include "./BombermanCommon.hh"
#include "./Bomberman.hh"
#include "./Command.hh"

class			Player : public Bomberman
{
 private:
  Command		cmd;
  bool			alive;
 public:
  Player();
  Player(int, int, int);
  ~Player();

  void			kill();
  bool			isAlive() const;
  void			setCommand(Command const&);
  void			setCommand(gdl::Keys::Key, gdl::Keys::Key, gdl::Keys::Key, gdl::Keys::Key, gdl::Keys::Key);
  Command		getCommand() const;

  void			setStockBomb(int);
  int			getStockBomb() const;
  virtual void		initialize();
  virtual void		update();
  virtual void		draw();
  virtual void		unload();
};

std::istream&		operator>>(std::istream& is, Player &p);
std::ostream&		operator<<(std::ostream& os, const Player &p);

#endif /* !PLAYER_HH_ */
