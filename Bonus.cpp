//
// Box.cpp for Box in /home/clariv_e//Projets/C++/Bomberman/bomberman-2015-tolsa_c
//
// Made by erick clarivet
// Login   <clariv_e@epitech.net>
//
// Started on  Tue May 29 04:34:24 2012 erick clarivet
// Last update Sun Jun  3 15:24:06 2012 mathieu barnetche
//

#include	"Bonus.hh"

Bonus::Bonus() : Bloc()
{
}

Bonus::Bonus(int x, int y, e_bonus bonus_) : Bloc(x, y)
{
  this->bonus = bonus_;
  this->type = BONUS;
  this->turn = 0;
}

Bonus::~Bonus()
{
}

void	Bonus::initialize()
{
}

void	Bonus::update()
{
}

void	Bonus::draw()
{
}

void	Bonus::draw(gdl::Image& texture)
{
  texture.bind();
  glPushMatrix();
  glTranslatef(this->position.x, this->position.y, 0.0f);
  glRotatef(turn, 0.0f, 0.0f, 1.0f);
  glBegin(GL_QUADS);
  turn += 0.2;
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(-((BLOCKSIZE - 5) / 3), ((BLOCKSIZE - 5) / 3), ((BLOCKSIZE - 5) / 3));
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(-((BLOCKSIZE - 5) / 3), -((BLOCKSIZE - 5) / 3), ((BLOCKSIZE - 5) / 3));
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(((BLOCKSIZE - 5) / 3), -((BLOCKSIZE - 5) / 3), ((BLOCKSIZE - 5) / 3));
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(((BLOCKSIZE - 5) / 3), ((BLOCKSIZE - 5) / 3), ((BLOCKSIZE - 5) / 3));

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(((BLOCKSIZE - 5) / 3), ((BLOCKSIZE - 5) / 3), -((BLOCKSIZE - 5) / 3));
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(((BLOCKSIZE - 5) / 3), -((BLOCKSIZE - 5) / 3), -((BLOCKSIZE - 5) / 3));
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(-((BLOCKSIZE - 5) / 3), -((BLOCKSIZE - 5) / 3), -((BLOCKSIZE - 5) / 3));
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(-((BLOCKSIZE - 5) / 3), ((BLOCKSIZE - 5) / 3), -((BLOCKSIZE - 5) / 3));

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(((BLOCKSIZE - 5) / 3), ((BLOCKSIZE - 5) / 3), ((BLOCKSIZE - 5) / 3));
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(((BLOCKSIZE - 5) / 3), -((BLOCKSIZE - 5) / 3), ((BLOCKSIZE - 5) / 3));
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(((BLOCKSIZE - 5) / 3), -((BLOCKSIZE - 5) / 3), -((BLOCKSIZE - 5) / 3));
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(((BLOCKSIZE - 5) / 3), ((BLOCKSIZE - 5) / 3), -((BLOCKSIZE - 5) / 3));

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(-((BLOCKSIZE - 5) / 3), ((BLOCKSIZE - 5) / 3), ((BLOCKSIZE - 5) / 3));
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(-((BLOCKSIZE - 5) / 3), ((BLOCKSIZE - 5) / 3), -((BLOCKSIZE - 5) / 3));
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(-((BLOCKSIZE - 5) / 3), -((BLOCKSIZE - 5) / 3), -((BLOCKSIZE - 5) / 3));
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(-((BLOCKSIZE - 5) / 3), -((BLOCKSIZE - 5) / 3), ((BLOCKSIZE - 5) / 3));

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(-((BLOCKSIZE - 5) / 3), -((BLOCKSIZE - 5) / 3), ((BLOCKSIZE - 5) / 3));
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(-((BLOCKSIZE - 5) / 3), -((BLOCKSIZE - 5) / 3), -((BLOCKSIZE - 5) / 3));
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(((BLOCKSIZE - 5) / 3), -((BLOCKSIZE - 5) / 3), -((BLOCKSIZE - 5) / 3));
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(((BLOCKSIZE - 5) / 3), -((BLOCKSIZE - 5) / 3), ((BLOCKSIZE - 5) / 3));

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(-((BLOCKSIZE - 5) / 3), ((BLOCKSIZE - 5) / 3), ((BLOCKSIZE - 5) / 3));
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(((BLOCKSIZE - 5) / 3), ((BLOCKSIZE - 5) / 3), ((BLOCKSIZE - 5) / 3));
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(((BLOCKSIZE - 5) / 3), ((BLOCKSIZE - 5) / 3), -((BLOCKSIZE - 5) / 3));
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(-((BLOCKSIZE - 5) / 3), ((BLOCKSIZE - 5) / 3), -((BLOCKSIZE - 5) / 3));

  glEnd();
  glPopMatrix();
}

void	Bonus::doBonus(Player& bomberman)
{
  if (this->bonus == SPEEDADD)
    bomberman.setSpeed(bomberman.getSpeed() + 1);
  if (this->bonus == PORTEE)
    bomberman.setPortee(bomberman.getPortee() + 1);
  if (this->bonus == BOMBNB)
    bomberman.setStockBomb(bomberman.getStockBomb() + 1);
}

void	Bonus::doBonus(Bomberman& bomberman)
{
  if (this->bonus == SPEEDADD)
    bomberman.setSpeed(bomberman.getSpeed() + 1);
  if (this->bonus == PORTEE)
    bomberman.setPortee(bomberman.getPortee() + 1);
  if (this->bonus == BOMBNB)
    bomberman.setStockBomb(bomberman.getStockBomb() + 1);
}

void	Bonus::doBonus(IA& bomberman)
{
  if (this->bonus == SPEEDADD)
    bomberman.setSpeed(bomberman.getSpeed() + 1);
  if (this->bonus == PORTEE)
    bomberman.setPortee(bomberman.getPortee() + 1);
  if (this->bonus == BOMBNB)
    bomberman.setStockBomb(bomberman.getStockBomb() + 1);
}

void	Bonus::unload()
{
}

e_bonus	Bonus::getBonus() const
{
  return this->bonus;
}
