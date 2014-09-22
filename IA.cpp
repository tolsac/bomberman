//
// IA.cpp for  in /home/barnet_m//Tek2/bomberman/bomberman-2015-tolsa_c
//
// Made by mathieu barnetche
// Login   <barnet_m@epitech.net>
//
// Started on  Tue May 29 11:06:58 2012 mathieu barnetche
// Last update Sun Jun  3 22:08:02 2012 mathieu barnetche
//


//VERSION DE IA.CPP UNIQUEMENT POUR COMPILER :°)

#include "IA.hh"

IA::IA()
{
  this->position.z = -150;
}

IA::IA(int x, int y, int s) : Bomberman(x, y, 255, 0, 0, s)
{
}

IA::~IA()
{
}

void		IA::update()
{
  this->timer_.update();
  this->model_.update(this->timer_);
  this->model_.play("Take 002");
  this->model_.set_anim_speed("Take 002", 1.5);
}

void		IA::findFocus(std::deque<Player> lst)
{
  (void)lst;
}

void		IA::unload()
{
}

void		IA::draw()
{
  glPushMatrix();

  glTranslatef(position.x, position.y, position.z);
  glRotatef(90.f, 2.0f, 0.0f, 0.0f);
  glRotatef(90.f, 0.0f, 1.0f, 0.0f);
  glRotatef(angle, 0.0f, 1.0f, 0.0f);
  glScalef(0.25f,   // homothétie sur l'axe X
	   0.25f,   // homothétie sur l'axe Y
	   0.25f);  // homothetie sur l'axe Z
  this->model_.draw();
  glPopMatrix();
}

void		IA::initialize()
{
  gdl::Color color(0, 0, 0, 255);

  this->model_ = gdl::Model::load("lib/assets/marvin.fbx");
  this->model_.infos();
  this->stockbomb = NB_BOMB;
  gdl::Model::cut_animation(this->model_,
                            "Take 001",
                            35,
                            54,
                            "Take 002");
  this->model_.set_default_model_color(this->color_);

}

void		IA::setStockBomb(int b)
{
  this->stockbomb = b;
}

int		IA::getStockBomb() const
{
  return (this->stockbomb);
}

bool		IA::getActiv() const
{
  return (this->activ);
}

void		IA::setActiv(bool b)
{
  this->activ = b;
}

std::istream		&operator>>(std::istream& is, IA &p)
{
  Vector3f		v;
  int			intTMP;
  float			floatTMP;

  is >> v;
  p.setPos(v);
  is >> intTMP;
  p.setAngle(intTMP);
  is >> intTMP;
  p.setPortee(intTMP);
  is >> floatTMP;
  p.setSpeed(floatTMP);
  is >> intTMP;
  p.setId(intTMP);
  is >> intTMP;
  p.setStockBomb(intTMP);
  return (is);
}

std::ostream		&operator<<(std::ostream& os, const IA &p)
{
  os << p.getPos();
  os << p.getAngle() << std::endl;
  os << p.getPortee() << std::endl;
  os << p.getSpeed() << std::endl;
  os << p.getId() << std::endl;
  os << p.getStockBomb() << std::endl;
  return (os);
}

