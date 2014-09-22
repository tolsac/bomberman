//
// Commande.hh for Commande in /home/nerevarine/Documents/bomberman-2015-tolsa_c
//
// Made by nerevarine
// Login   <nerevarine@scarlett>
//
// Started on Mon May 28 21:29:46 2012 nerevarine
// Last update Sat Jun  2 23:54:44 2012 nerevarine
//

#ifndef _COMMANDE_HH_
#define _COMMANDE_HH_

#include "./BombermanCommon.hh"
#include "Input.hpp"

class			Command
{
private:
  gdl::Keys::Key	up_;
  gdl::Keys::Key	down_;
  gdl::Keys::Key	left_;
  gdl::Keys::Key	right_;
  gdl::Keys::Key	bomb_;

public:
  Command();
  Command(gdl::Keys::Key, gdl::Keys::Key, gdl::Keys::Key, gdl::Keys::Key, gdl::Keys::Key);
  ~Command() {}

  gdl::Keys::Key	getUp() const;
  gdl::Keys::Key	getDown() const;
  gdl::Keys::Key	getLeft() const;
  gdl::Keys::Key	getRight() const;
  gdl::Keys::Key	getBomb() const;

  void			setUp(gdl::Keys::Key u);
  void			setDown(gdl::Keys::Key d);
  void			setLeft(gdl::Keys::Key l);
  void			setRight(gdl::Keys::Key r);
  void			setBomb(gdl::Keys::Key b);

  Command&		operator=(const Command& command);
};

std::istream&		operator>>(std::istream &is, Command &c);
std::ostream&		operator<<(std::ostream &os, const Command &c);

#endif /* !-COMMANDE_HH_ */
