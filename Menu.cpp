//
// Menu.cpp for  in /home/tolsa_c//svncapue/save
// 
// Made by camille tolsa
// Login   <tolsa_c@epitech.net>
// 
// Started on  Wed May 30 10:00:10 2012 camille tolsa
// Last update Sun Jun  3 23:08:12 2012 mathieu barnetche
//

#include "Menu.hh"
#include "BombermanCommon.hh"

Menu::Menu(std::string const& path)
{
  this->img = gdl::Image::load(path);
  this->which = 0;
}

int		Menu::checkwd()
{
  DIR*		root;
  struct dirent *ent;
  
  root = opendir("./save");
  fic.setPosition(200, 400);
  fic.setText("No files");
  if (root != NULL)
    {
      while ((ent = readdir(root)) != NULL)
  	{
	  if (ent->d_name[0] != '.') 
	    fic.setText(ent->d_name);
  	}    
    }
  closedir(root);
  return (0);
}

void		Menu::initialize()
{
  int		i = -1;
  
  while (++i < 7)
    this->string[i].setSize(40);
  
  this->string[0].setText("New game");
  this->string[0].setPosition(200, 400);
  this->string[1].setText("Load game");
  this->string[1].setPosition(200, 450);
  this->string[2].setText("Exit");
  this->string[2].setPosition(200, 500);
  this->string[3].setText("Random");
  this->string[3].setPosition(200, 400);
  this->string[4].setText("");
  this->string[4].setPosition(200, 450);
  this->string[5].setText("");
  this->string[5].setPosition(200, 500);
  this->string[6].setText("Files :");
  this->string[6].setPosition(200, 350);

  this->string[7].setText(" 1 Player");
  this->string[7].setPosition(200, 400);
  this->string[8].setText("2 Players");
  this->string[8].setPosition(200, 450);
  
  this->string[0].setSize(60);
  this->string[1].setSize(40);
  this->string[2].setSize(40);
  this->string[3].setSize(60);
  this->string[4].setSize(40);
  this->string[5].setSize(40);
  this->string[6].setSize(60);
  this->string[7].setSize(60);
  this->string[8].setSize(40);
  this->choice = 0;
  this->initMenu();
}

int		Menu::updateMain(gdl::Input & input_)
{
  if (input_.isKeyDown(gdl::Keys::Up))
    {
      ((choice > 0 ? choice-- && usleep(300000) : 0));
      this->string[choice].setSize(60);
      if (choice == 0)
	{
	  this->string[1].setSize(40);
	  this->string[2].setSize(40);
	}
      else if (choice == 1)
	{
	  this->string[2].setSize(40);
	  this->string[0].setSize(40);
	}
      else
	{
	  this->string[1].setSize(40);
	  this->string[0].setSize(40);
	}
    }
  else if (input_.isKeyDown(gdl::Keys::Down))
    {
      ((choice < 2 ? choice++ && usleep(300000) : 0));
      this->string[choice].setSize(60);
      if (choice == 0)
	{
	  this->string[1].setSize(40);
	  this->string[2].setSize(40);
	}
      else if (choice == 1)
	{
	  this->string[2].setSize(40);
	  this->string[0].setSize(40);
	}
      else
	{
	  this->string[1].setSize(40);
	  this->string[0].setSize(40);
	}
    }
  else if (input_.isKeyDown(gdl::Keys::Return))
    {
      usleep(300000);
      this->string[0].setSize(60);
      this->string[1].setSize(40);
      this->string[2].setSize(40);
      this->which = choice + 1;
      this->choice = 0;
      if (this->which == 3)
	exit(0);
    }
  return (0);
}

int		Menu::updateNew(gdl::Input & input_)
{
  if (input_.isKeyDown(gdl::Keys::Up))
    {
      ((choice > 3 ? choice-- && usleep(200000) : 0));
      this->string[choice].setSize(60);
      if (choice == 3)
	{
	  this->string[5].setSize(40);
	  this->string[4].setSize(40);
	}
      else if (choice == 4)
	{
	  this->string[3].setSize(40);
	  this->string[5].setSize(40);
	}
      else
	{
	  this->string[3].setSize(40);
	  this->string[4].setSize(40);
	}
    }
  else if (input_.isKeyDown(gdl::Keys::Down))
    {
      ((choice < 5 ? choice++ && usleep(200000) : 0));
      this->string[choice].setSize(60);
      if (choice == 3)
	{
	  this->string[5].setSize(40);
	  this->string[4].setSize(40);
	}
      else if (choice == 4)
	{
	  this->string[3].setSize(40);
	  this->string[5].setSize(40);
	}
      else
	{
	  this->string[3].setSize(40);
	  this->string[4].setSize(40);
	}
    }
  else if (input_.isKeyDown(gdl::Keys::Return))
    {
      this->string[3].setSize(60);
      this->string[4].setSize(40);
      this->string[5].setSize(40);
      usleep(200000);
      this->choice = 0;
      this->which = 3;
    }
  return (0);
}

int		Menu::updateLoad(gdl::Input & input_)
{
  this->checkwd();
  if (input_.isKeyDown(gdl::Keys::Up))
    {
      ((choice > 3 ? choice-- && usleep(200000) : 0));
      this->string[6].setSize(60);
      this->fic.setSize(40);
    }
  else if (input_.isKeyDown(gdl::Keys::Down))
    {
      ((choice < 5 ? choice++ && usleep(200000) : 0));
      this->string[6].setSize(40);
      this->fic.setSize(60);
    }
  else if (input_.isKeyDown(gdl::Keys::Return))
    {
      this->string[6].setSize(60);
      this->fic.setSize(40);
      usleep(200000);
    }
  return (0);
}

int		Menu::updatePlayer(gdl::Input & input_)
{
   if (input_.isKeyDown(gdl::Keys::Up))
    {
      ((choice > 0 ? choice-- && usleep(200000) : 0));
      this->string[7].setSize(60);
      this->string[8].setSize(40);
      this->nbPlay = 3;
    }
  else if (input_.isKeyDown(gdl::Keys::Down))
    {
      ((choice < 2 ? choice++ && usleep(200000) : 0));
      this->string[7].setSize(40);
      this->string[8].setSize(60);
      this->nbPlay = 4;
    }
  else if (input_.isKeyDown(gdl::Keys::Return))
    {
      usleep(200000);
      return (this->nbPlay);
    }
   return (0);
}

int		Menu::update(gdl::Input & input_)
{
  int		ret;
  
  if (input_.isKeyDown(gdl::Keys::Back) && this->which != 0)
    this->which = 0;
  if (this->which == 0)
    ret = updateMain(input_);
  else if (this->which == 1)
    ret = updateNew(input_);
  else if (this->which == 2)
    ret = updateLoad(input_);
  else if (this->which == 3)
    ret = updatePlayer(input_);
  return (ret);
}

void		Menu::initCurseur()
{			// y x
  Vector2d	a(2000, -1700);     //bqs droit
  Vector2d	b(2000, -1000); // haut droit
  Vector2d	c(2500, -1000); //hqut gquche
  Vector2d	d(2500, -1700); // bqs gquche
  
  init(a, b, c, d);
}
void		Menu::initMenu()
{
  // Vector2d	a(-1550, -1800);
  // Vector2d	b(-1550, 2900);
  // Vector2d	c(2600, 2900);
  // Vector2d	d(2600, -1800);

  Vector2d	a(800, 600);
  Vector2d	b(800, 0);
  Vector2d	c(0, 0);
  Vector2d	d(0, 600);
  
  init(a, b, c, d);
}

void		Menu::init(Vector2d a, 
			   Vector2d b, 
			   Vector2d c, 
			   Vector2d d)
{
  this->a = a;
  this->b = b;
  this->c = c;
  this->d = d;
}

void		Menu::draw()
{
  if (this->which == 0)
    drawMain();
  else if (this->which == 1)
    drawNew();
  else if (this->which == 2)
    drawLoad();
  else if (this->which == 3)
    drawPlayer();
}

void		Menu::drawNew()
{
  this->img.bind();
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, 600, 800, 0, 0, 1);
  glDisable(GL_DEPTH_TEST);
  
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glBegin(GL_QUADS);
  glTexCoord2d(0, 0);           // Y ---- X
  glVertex2f(a.y, a.x); //bas droit
  glVertex2f(b.y, b.x); // haut droit                                                           
  glTexCoord2d(1, 1);
  glVertex2f(c.y, c.x); //haut gauche
  glTexCoord2d(1, 0);
  glVertex2f(d.y, d.x); //bas gauche                                                         
  glEnd();

  // Draw de ton element
  this->string[3].draw();
  this->string[4].draw();
  this->string[5].draw();
  glLoadIdentity();
  glDepthFunc(GL_LEQUAL);
  glMatrixMode(GL_PROJECTION);
  glMatrixMode(GL_MODELVIEW);

}

void		Menu::drawLoad()
{
  this->img.bind();
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, 600, 800, 0, 0, 1);
  glDisable(GL_DEPTH_TEST);
  
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glBegin(GL_QUADS);
  glTexCoord2d(0, 0);           // Y ---- X
  glVertex2f(a.y, a.x); //bas droit
  glVertex2f(b.y, b.x); // haut droit                                                           
  glTexCoord2d(1, 1);
  glVertex2f(c.y, c.x); //haut gauche
  glTexCoord2d(1, 0);
  glVertex2f(d.y, d.x); //bas gauche                                                         
  glEnd();

  this->fic.draw();
  this->string[6].draw();
  //glLoadIdentity();
  glMatrixMode(GL_PROJECTION);
  //glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);  
}

void		Menu::drawMain()
{
  this->img.bind();

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, 600, 800, 0, 0, 1);
  glDisable(GL_DEPTH_TEST);
  
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glBegin(GL_QUADS);
  glTexCoord2d(0, 0);           // Y ---- X
  glVertex2f(a.y, a.x); //bas droit
  glVertex2f(b.y, b.x); // haut droit                                                           
  glTexCoord2d(1, 1);
  glVertex2f(c.y, c.x); //haut gauche
  glTexCoord2d(1, 0);
  glVertex2f(d.y, d.x); //bas gauche                                                         
  glEnd();

  // Draw de ton element
  this->string[0].draw();
  this->string[1].draw();
  this->string[2].draw();

  //glLoadIdentity();
  glMatrixMode(GL_PROJECTION);
  //glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);  
}

void		Menu::drawPlayer()
{
  this->img.bind();

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, 600, 800, 0, 0, 1);
  glDisable(GL_DEPTH_TEST);
  
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glBegin(GL_QUADS);
  glTexCoord2d(0, 0);           // Y ---- X
  glVertex2f(a.y, a.x); //bas droit
  glVertex2f(b.y, b.x); // haut droit                                                           
  glTexCoord2d(1, 1);
  glVertex2f(c.y, c.x); //haut gauche
  glTexCoord2d(1, 0);
  glVertex2f(d.y, d.x); //bas gauche                                                         
  glEnd();

  // Draw de ton element
  this->string[7].draw();
  this->string[8].draw();

  //glLoadIdentity();
  glMatrixMode(GL_PROJECTION);
  //glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);  
}
