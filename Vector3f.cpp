//
// Vector3f.cpp for Vector3f in /home/nerevarine/Documents/bomberman-2015-tolsa_c
//
// Made by nerevarine
// Login   <nerevarine@scarlett>
//
// Started on Tue May 29 14:55:05 2012 nerevarine
// Last update Sun Jun  3 01:28:35 2012 nerevarine
//

#include "./Vector3f.hh"

Vector3f::Vector3f()
{
}

Vector3f::Vector3f(float x, float y, float z) : x(x), y(y), z(z)
{
}

std::istream&           operator>>(std::istream& is, Vector3f &p)
{
  is >> p.x;
  is >> p.y;
  is >> p.z;
  return (is);
}

std::ostream&           operator<<(std::ostream& os, const Vector3f &p)
{
  os << p.x << std::endl;
  os << p.y << std::endl;
  os << p.z << std::endl;
  return (os);
}
