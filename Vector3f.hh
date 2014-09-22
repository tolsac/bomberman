//
// Vector3f.hh for Vector3f in /home/nerevarine/Documents/bomberman-2015-tolsa_c
//
// Made by nerevarine
// Login   <nerevarine@scarlett>
//
// Started on Mon May 28 21:25:28 2012 nerevarine
// Last update Sat Jun  2 20:34:58 2012 nerevarine
//

#ifndef _VECTOR3F_HH_
#define _VECTOR3F_HH_

#include "./BombermanCommon.hh"

struct		Vector3f
{
public:
  float		x;
  float		y;
  float		z;

  Vector3f();
  Vector3f(float x, float y, float z);
};

std::istream&           operator>>(std::istream& is, Vector3f &p);
std::ostream&           operator<<(std::ostream& os, const Vector3f &v);

#endif /* !_VECTOR3F_HH_ */
