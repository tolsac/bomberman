//
// Camera.cpp for Camera in /home/clariv_e//Projets/C++/Bomberman/bomberman-2015-tolsa_c
//
// Made by erick clarivet
// Login   <clariv_e@epitech.net>
//
// Started on  Tue May 29 04:27:07 2012 erick clarivet
// Last update Sun Jun  3 22:06:30 2012 mathieu barnetche
//

#include	"Camera.hh"

Camera::Camera() : position(0, 0, 800), view(0.0f, 0.0f, -1.0f)
{
}

Camera::~Camera()
{
}

void			Camera::initialize()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70.0f, 800.0f/600.0f, 1.0f, 10000.0f);
  gluLookAt(position.x + view.x,
	    position.y + view.y,
	    position.z + view.z,
            view.x, view.y, view.z,
            1.0f, 0.0f, 0.0f);
  glRotatef(90, 0, 0, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
}

void			Camera::update(gdl::GameClock const & gameClock,
				       gdl::Input & input)
{
  glLoadIdentity();
  gluLookAt(view.x + position.x,
	    view.y + position.y,
            view.z + position.z,
            view.x, view.y, view.z,
            1.0f, 0.0f, 0.0f);
  (void) gameClock;
  (void) input;
}

void			Camera::setPointView(const Vector3f& pos)
{
  this->view.x = pos.x;
  this->view.y = pos.y;
  this->view.z = pos.z;
}

void			Camera::setPos(Vector3f const &v)
{
  this->position = v;
}

void			Camera::setPos(float x, float y, float z)
{
  this->position.x = x;
  this->position.y = y;
  this->position.z = z;
}

Vector3f		Camera::getPointView() const
{
  return (this->view);
}

Vector3f		Camera::getPos() const
{
  return (this->position);
}

std::istream&		operator>>(std::istream& is, Camera &c)
{
  Vector3f		v;

  is >> v;
  c.setPos(v);
  is >> v;
  c.setPointView(v);
  return (is);
}

std::ostream&		operator<<(std::ostream& os, const Camera &c)
{
  os << c.getPos();
  os << c.getPointView();
  return (os);
}
