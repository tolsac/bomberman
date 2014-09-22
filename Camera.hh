//
// Camera.hh for Camera in /home/clariv_e//Projets/C++/Bomberman/bomberman-2015-tolsa_c
//
// Made by erick clarivet
// Login   <clariv_e@epitech.net>
//
// Started on  Tue May 29 04:21:41 2012 erick clarivet
// Last update Sat Jun  2 22:46:02 2012 nerevarine
//

#ifndef		__CAMERA_HH__
#define		__CAMERA_HH__

#include "./BombermanCommon.hh"

class		Camera
{
private:
  Vector3f position;
  Vector3f view;

public:
  Camera();
  ~Camera();

  void		setPointView(const Vector3f& pos);
  void		setPos(Vector3f const &v);
  void		setPos(float x, float y, float z);

  Vector3f	getPointView() const;
  Vector3f	getPos() const;

  void		initialize();
  void		update(gdl::GameClock const &, gdl::Input &);
};

std::istream&		operator>>(std::istream& is, Camera &c);
std::ostream&		operator<<(std::ostream& os, const Camera &c);

#endif
