//
// Bonus.hh for Bonus in /home/clariv_e//Projets/C++/Bomberman/bomberman-2015-tolsa_c
// 
// Made by erick clarivet
// Login   <clariv_e@epitech.net>
// 
// Started on  Wed May 30 20:24:24 2012 erick clarivet
// Last update Sun Jun  3 02:35:35 2012 mathieu barnetche
//

#ifndef		__BONUS_HH__
#define		__BONUS_HH__

#include "./BombermanCommon.hh"
#include "./Bloc.hh"
#include "Player.hh"
#include "./IA.hh"

class           Bonus : public Bloc
{
public:
  Bonus();
  Bonus(int, int, e_bonus);
  ~Bonus();

  e_bonus		getBonus() const;
  void			doBonus(IA& bomberman);
  void			doBonus(Bomberman& bomberman);
  void			doBonus(Player& bomberman);
  virtual void          initialize();
  virtual void          update();
  virtual void          draw();
  virtual void          draw(gdl::Image&);
  virtual void          unload();
private:
  e_bonus		bonus;
  float			turn;
};

#endif
