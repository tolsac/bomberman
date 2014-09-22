//
// Player.cpp for  in /home/barnet_m//Tek2/bomberman/bomberman-2015-tolsa_c
//
// Made by mathieu barnetche
// Login   <barnet_m@epitech.net>
//
// Started on  Tue May 29 11:06:58 2012 mathieu barnetche
// Last update Sun Jun  3 17:06:19 2012 nerevarine
//


#include "./Player.hh"

Player::Player() : Bomberman(0, 0, 0, 0, 255, 1)
{
}

Player::Player(int x, int y, int s) : Bomberman(x, y, 0, 0, 255, s)
{
  this->alive = true;
}

Player::~Player()
{
}

void		Player::setCommand(gdl::Keys::Key up, gdl::Keys::Key down, gdl::Keys::Key left, gdl::Keys::Key right, gdl::Keys::Key bomb)
{
  this->cmd.setUp(up);
  this->cmd.setDown(down);
  this->cmd.setLeft(left);
  this->cmd.setRight(right);
  this->cmd.setBomb(bomb);
}

void		Player::setCommand(Command const &com)
{
  this->cmd = com;
}

Command		Player::getCommand() const
{
  return (this->cmd);
}

void		Player::update()
{
  this->timer_.update();
  this->model_.update(this->timer_);
  this->model_.play("Take 002");
  this->model_.set_anim_speed("Take 002", 1.5);
}

void		Player::unload()
{
}

void		Player::initialize()
{
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

void		Player::draw()
{
  glPushMatrix();

  glTranslatef(position.x, position.y, position.z);
  glRotatef(90.f, 2.0f, 0.0f, 0.0f);
  glRotatef(90.f, 0.0f, 1.0f, 0.0f);
  glRotatef(angle, 0.0f, 1.0f, 0.0f);
  glScalef(0.25f,
	   0.25f,
	   0.25f);
  this->model_.draw();
  glPopMatrix();
}

int                   Player::getStockBomb() const
{
  return this->stockbomb;
}

void                 Player::setStockBomb(int stock)
{
  this->stockbomb = stock;
}

void			Player::kill()
{
  this->alive = false;
}

bool			Player::isAlive() const
{
  return this->alive;
}

std::istream		&operator>>(std::istream& is, Player &p)
{
  Vector3f		v;
  int			intTMP;
  float			floatTMP;
  Command		c;

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
  is >> c;
  p.setCommand(c);
  return (is);

}

std::ostream		&operator<<(std::ostream& os, const Player &p)
{
  os << p.getPos();
  os << p.getAngle() << std::endl;
  os << p.getPortee() << std::endl;
  os << p.getSpeed() << std::endl;
  os << p.getId() << std::endl;
  os << p.getStockBomb() << std::endl;
  os << p.getCommand();
  return (os);
}
