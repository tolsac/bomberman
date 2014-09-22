//
// Box.cpp for Box in /home/clariv_e//Projets/C++/Bomberman/bomberman-2015-tolsa_c
//
// Made by erick clarivet
// Login   <clariv_e@epitech.net>
//
// Started on  Tue May 29 04:34:24 2012 erick clarivet
// Last update Fri Jun  1 14:12:38 2012 camille tolsa
//

#include	"Box.hh"

Box::Box() : Bloc()
{
  this->type = BOX;
}

Box::Box(int x, int y) : Bloc(x, y)
{
  this->type = BOX;
}

Box::~Box()
{
}

void	Box::initialize()
{
}

void	Box::update()
{
}

void	Box::draw()
{
}

void	Box::draw(gdl::Image& texture)
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

void	Box::unload()
{
}
