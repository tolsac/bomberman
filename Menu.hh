//
// Menu.hh for  in /home/tolsa_c//svncapue/save
//
// Made by camille tolsa
// Login   <tolsa_c@epitech.net>
//
// Started on  Wed May 30 07:59:47 2012 camille tolsa
// Last update Sun Jun  3 22:43:39 2012 mathieu barnetche
//

#ifndef __MENU__
#define __MENU__

#include "BombermanCommon.hh"

class		Menu
{
public:
  Menu(std::string const&);
  ~Menu(){}

  void			setPos(int, int, int);
  void			initialize();
  void			init(Vector2d,Vector2d,Vector2d,Vector2d);
  void			initMenu();
  void			initCurseur();
  int			checkwd();
  void			draw();
  void			drawMain();
  void			drawNew();
  void                  drawPlayer();
  void			drawLoad();
  int			update(gdl::Input&);
  int                   updatePlayer(gdl::Input&);
  int			updateMain(gdl::Input&);
  int			updateNew(gdl::Input&);
  int			updateLoad(gdl::Input&);
  void			unload();

  bool			opt_random;
  bool			opt_xy;
  int			opt_x;
  int			opt_y;
  gdl::Text	        fic;
  std::string		filename;
  int			nbPlay;
protected:
  int			which;
  int			choice;
  Vector2d		a;
  Vector2d		b;
  Vector2d		c;
  Vector2d		d;
  gdl::Image		img;
  gdl::Text		string[13];
};

#endif
