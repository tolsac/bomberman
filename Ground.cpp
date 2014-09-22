//
// Ground.cpp for position in /home/clariv_e//Projets/C++/Bomberman/new/bomberman/bomberman-2015-tolsa_c
//
// Made by erick clarivet
// Login   <clariv_e@epitech.net>
//
// Started on  Tue May 29 15:13:48 2012 erick clarivet
// Last update Thu May 31 19:25:32 2012 nerevarine
//

#include		"Ground.hh"

Ground::Ground() : Bloc(0, 0)
{
}

Ground::Ground(int x, int y) : Bloc(x, y)
{
  this->type = GROUND;
}

Ground::~Ground()
{
}

void		Ground::initialize()
{
}

void		Ground::update()
{
}

void		Ground::draw()
{
}

void		Ground::draw(gdl::Image& texture)
{
  texture.bind();
  glPushMatrix();
  glTranslatef(this->position.x, this->position.y, 0.0f);

  glBegin(GL_QUADS);

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(BLOCKSIZE / 2, (BLOCKSIZE / 2), -(BLOCKSIZE / 2));
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f((BLOCKSIZE / 2), -(BLOCKSIZE / 2), -(BLOCKSIZE / 2));
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(-(BLOCKSIZE / 2), -(BLOCKSIZE / 2), -(BLOCKSIZE / 2));
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(-(BLOCKSIZE / 2), (BLOCKSIZE / 2), -(BLOCKSIZE / 2));

  glEnd();
  glPopMatrix();
}

void			Ground::draw(gdl::Image &texture, int x, int y)
{
  this->position.x = x * BLOCKSIZE;
  this->position.y = y * BLOCKSIZE;
  texture.bind();
  glPushMatrix();
  glTranslatef(position.x, position.y, 0.0f);

  glBegin(GL_QUADS);

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(BLOCKSIZE / 2, (BLOCKSIZE / 2), -(BLOCKSIZE / 2));
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f((BLOCKSIZE / 2), -(BLOCKSIZE / 2), -(BLOCKSIZE / 2));
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(-(BLOCKSIZE / 2), -(BLOCKSIZE / 2), -(BLOCKSIZE / 2));
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(-(BLOCKSIZE / 2), (BLOCKSIZE / 2), -(BLOCKSIZE / 2));

  glEnd();
  glPopMatrix();
}

void                    Ground::unload()
{
}
