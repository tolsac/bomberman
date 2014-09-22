//
// Bomberman.hh for Bomberman in /home/nerevarine/Documents/bomberman-2015-tolsa_c
//
// Made by nerevarine
// Login   <nerevarine@scarlett>
//
// Started on Mon May 28 21:19:21 2012 nerevarine
// Last update Sun Jun  3 16:33:12 2012 nerevarine
//

#ifndef _BOMBERMAN_HH_
#define _BOMBERMAN_HH_

#include "./BombermanCommon.hh"

class			Bomberman
{
 protected:
  Vector3f		position;
  int			angle;
  int			portee;
  float 		speed;
  gdl::Color		color_;
  gdl::Clock		timer_;
  gdl::Model		model_;
  int			id;
  int			stockbomb;

 public:
  Bomberman();
  Bomberman(int x, int y, int R, int G, int B, int s);
  ~Bomberman();

  Vector3f		getPos() const;
  float			getXf() const;
  float			getYf() const;
  int			getAngle() const;
  float 		getSpeed() const;
  int	 		getPortee() const;
  int			getId() const;
  virtual int		getStockBomb() const;

  virtual void		setStockBomb(int);
  void			setId(int);
  void			setPos(Vector3f const&);
  void			setPos(float const& x, float const& y, float const& z);
  void			setAngle(int const &a);
  void			setSpeed(float const&);
  void	 		setPortee(const int& portee);

  virtual void		initialize() = 0;
  virtual void 		update() = 0;
  virtual void 		draw() = 0;
  virtual void		unload() = 0;
};

#endif /* !_BOMBERMAN_HH_ */
