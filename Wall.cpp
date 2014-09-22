//
// Wall.cpp for Wall in /home/clariv_e//Projets/C++/Bomberman/bomberman-2015-tolsa_c
//
// Made by erick clarivet
// Login   <clariv_e@epitech.net>
//
// Started on  Tue May 29 04:51:58 2012 erick clarivet
// Last update Sun Jun  3 22:05:01 2012 mathieu barnetche
//

#include	"Wall.hh"

Wall::Wall() : Bloc()
{
  this->type = WALL;
}

Wall::Wall(int x, int y) : Bloc(x, y)
{
  this->type = WALL;
}

void	Wall::initialize()
{
}

void	Wall::update(gdl::GameClock const& clock,
		    gdl::Input &input)
{
  (void)clock;
  (void)input;
}

void	Wall::update()
{
}

void	Wall::draw()
{
}

void	Wall::draw(gdl::Image& texture)
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

  glEnd();
  glPopMatrix();
}

void	Wall::unload()
{
}
