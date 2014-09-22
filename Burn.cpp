//
// Wall.cpp for Wall in /home/clariv_e//Projets/C++/Bomberman/bomberman-2015-tolsa_c
//
// Made by erick clarivet
// Login   <clariv_e@epitech.net>
//
// Started on  Tue May 29 04:51:58 2012 erick clarivet
// Last update Sun Jun  3 22:05:42 2012 mathieu barnetche
//

#include	"Burn.hh"

Burn::Burn() : Bloc()
{
  this->type = BURN;
  this->timer_.play();
  this->fire = false;
  this->b_ = false;
}

Burn::Burn(int x, int y) : Bloc(x, y)
{
  this->type = BURN;
  this->timer_.play();
  this->fire = false;
  this->b_ = false;
}

Burn::Burn(int x, int y, bool b) : Bloc(x, y)
{
  this->type = BURN;
  this->timer_.play();
  this->fire = false;
  this->b_ = b;

}

void	Burn::initialize()
{
}

void	Burn::update(gdl::GameClock const& clock,
		    gdl::Input &input)
{
  (void)clock;
  (void)input;
}

void	Burn::update()
{
  this->timer_.update();
  if (this->timer_.getTotalElapsedTime() > 1.0f)
    this->fire = true;
}

void	Burn::draw()
{
}

void	Burn::draw(gdl::Image& texture)
{
  texture.bind();
  glPushMatrix();
  glTranslatef(this->position.x, this->position.y, 0.0f);

  glBegin(GL_QUADS);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(-(BLOCKSIZE / 2), (BLOCKSIZE / 2), (BLOCKSIZE / 2));
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(-(BLOCKSIZE / 2), -(BLOCKSIZE / 2), (BLOCKSIZE / 2));
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f((BLOCKSIZE / 2), -(BLOCKSIZE / 2), (BLOCKSIZE / 2));
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f((BLOCKSIZE / 2), (BLOCKSIZE / 2), (BLOCKSIZE / 2));

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f((BLOCKSIZE / 2), (BLOCKSIZE / 2), -(BLOCKSIZE / 2));
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f((BLOCKSIZE / 2), -(BLOCKSIZE / 2), -(BLOCKSIZE / 2));
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(-(BLOCKSIZE / 2), -(BLOCKSIZE / 2), -(BLOCKSIZE / 2));
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(-(BLOCKSIZE / 2), (BLOCKSIZE / 2), -(BLOCKSIZE / 2));

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f((BLOCKSIZE / 2), (BLOCKSIZE / 2), (BLOCKSIZE / 2));
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f((BLOCKSIZE / 2), -(BLOCKSIZE / 2), (BLOCKSIZE / 2));
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f((BLOCKSIZE / 2), -(BLOCKSIZE / 2), -(BLOCKSIZE / 2));
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f((BLOCKSIZE / 2), (BLOCKSIZE / 2), -(BLOCKSIZE / 2));

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(-(BLOCKSIZE / 2), (BLOCKSIZE / 2), (BLOCKSIZE / 2));
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(-(BLOCKSIZE / 2), (BLOCKSIZE / 2), -(BLOCKSIZE / 2));
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(-(BLOCKSIZE / 2), -(BLOCKSIZE / 2), -(BLOCKSIZE / 2));
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(-(BLOCKSIZE / 2), -(BLOCKSIZE / 2), (BLOCKSIZE / 2));

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(-(BLOCKSIZE / 2), -(BLOCKSIZE / 2), (BLOCKSIZE / 2));
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(-(BLOCKSIZE / 2), -(BLOCKSIZE / 2), -(BLOCKSIZE / 2));
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f((BLOCKSIZE / 2), -(BLOCKSIZE / 2), -(BLOCKSIZE / 2));
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f((BLOCKSIZE / 2), -(BLOCKSIZE / 2), (BLOCKSIZE / 2));

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(-(BLOCKSIZE / 2), (BLOCKSIZE / 2), (BLOCKSIZE / 2));
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f((BLOCKSIZE / 2), (BLOCKSIZE / 2), (BLOCKSIZE / 2));
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f((BLOCKSIZE / 2), (BLOCKSIZE / 2), -(BLOCKSIZE / 2));
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(-(BLOCKSIZE / 2), (BLOCKSIZE / 2), -(BLOCKSIZE / 2));
  glDisable(GL_BLEND);

  glEnd();

  glPopMatrix();
}

gdl::Clock&           Burn::getClock()
{
  return this->timer_;
}

void	Burn::unload()
{
}

bool			Burn::getFire() const
{
  return this->fire;
}

bool			Burn::getB() const
{
  return  this->b_;
}
