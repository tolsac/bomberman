//
// MyMap.cpp for  in /home/tolsa_c//bomberman-2015-tolsa_c
//
// Made by camille tolsa
// Login   <tolsa_c@epitech.net>
//
// Started on  Tue May 29 04:46:14 2012 camille tolsa
// Last update Sun Jun  3 22:07:39 2012 mathieu barnetche
//

#include "MyMap.hh"

MyMap::MyMap()
{
  initialize();
}

MyMap::~MyMap()
{
}

int			MyMap::getX() const
{
  return (this->x);
}

int			MyMap::getY() const
{
  return (this->y);
}

Bloc***			MyMap::getMap() const
{
  return (this->map);
}

void			MyMap::setX(int x)
{
  this->x = x;
}

void			MyMap::setY(int y)
{
  this->y = y;
}

void			MyMap::setMap(Bloc ***m)
{
  this->map = m;
}

void			MyMap::initialize()
{
  this->Wall_ = gdl::Image::load("textures/pierre2.jpg");
  this->Explosion_ = gdl::Image::load("textures/explosion.jpg");
  this->Box_ = gdl::Image::load("textures/pierre.jpg");
  this->Ground1_ = gdl::Image::load("textures/ground.jpg");
  this->Ground2_ = gdl::Image::load("textures/ground2.jpg");
  this->BonusBombNb_ = gdl::Image::load("textures/BombeSup.jpg");
  this->BonusSpeedAdd_ = gdl::Image::load("textures/Speed2.jpg");
  this->BonusPortee_ = gdl::Image::load("textures/flamme1.jpg");
  this->mapsFile.push_back("map/map1");
  this->mapsFile.push_back("map/map2");
  this->mapsFile.push_back("map/map3");
  this->mapsFile.push_back("map/map4");
  this->mapsFile.push_back("map/map5");
}

void			MyMap::initialize(int const& _x, int const& _y)
{
  initialize();
  this->x = _x;
  this->y = _y;
}

void			MyMap::initialize(std::string const& path)
{
  initialize();
  loadMap(path);
}

void			MyMap::loadMap(std::string const &path)
{
  int			i = -1;
  int			j = 0;
  std::ifstream		f;
  char			c;

  f.open(path.c_str());
  f >> this->x;
  f >> this->y;
  std::cout << "Map size: " << this->x << "x" << this->y << std::endl;
  this->map = new Bloc**[this->y];
  while (++i < this->y)
    this->map[i] = new Bloc*[this->x];
  i = -1;
  while (++i < this->y)
    {
      j = -1;
      c = f.get();
      while (++j < this->x)
	{
	  c = f.get();
	  std::cout << c;
	  if (c == C_WALL)
	    this->map[i][j] = new Wall(i, j);
	  else if (c == C_BOX)
	    this->map[i][j] = new Box(i, j);
	  else if (c == C_GROUND)
	    this->map[i][j] = NULL;
	}
      std::cout << std::endl;
    }
  f.close();
  std::cout << "Loading Map: DONE !" << std::endl;
}

void			MyMap::generateMap()
{
  int                   i = -1;
  int                   j = -1;
  int                   o;
  Vector2d              place;

  //Random
  this->x = 0;
  this->y = 0;
  while (this->x <= 15)// 15 && )
    this->x = (rand() % 120);
  while (this->y <= 15)
    this->y = (rand() % 120);
  std::cout << x << ":" << y << std::endl;
  //Allocatoion
  this->map = new Bloc**[this->y];
  while (++i < this->y)
    this->map[i] = new Bloc*[this->x];
  i = -1;
  j = -1;
  //Sol
  while (++i < this->y)
    {
      j = -1;
      while (++j < this->x)
        this->map[i][j] = NULL;
    }
  //Contours
  i = -1;
  while (++i < this->x)
    this->map[0][i] = new Wall(0, i);
  i = -1;
  while (++i < this->y)
    this->map[i][0] = new Wall(i, 0);
  i = -1;
  while (++i < this->x)
    this->map[this->y - 1][i] = new Wall(this->y - 1, i);
  i = -1;
  while (++i < this->y)
    this->map[i][this->x - 1] = new Wall(i, this->x - 1);
  i = 0; //y
  j = 0; //x
  //Blocs
  //return;
  while (++i < this->y - 1)
    {
      j = 0;
      if (i % 2 == 0)
	while (++j < this->x - 1)
	  {
	    o = (rand() % 3);
	    if (o == 1)
	      this->map[i][j] = new Wall(i, j);
	    else if (o == 2)
	      this->map[i][j] = new Box(i, j);
	    else
	      {
		place.x = j;
		place.y = i;
	      }
	  }
    }
}

void			MyMap::generateMap(int const& x, int const& y)
{
  (void)x;
  (void)y;
}

void			MyMap::drawBonus(Bloc *bonus)
{
  if (dynamic_cast<Bonus*>(bonus)->getBonus() == SPEEDADD)
    dynamic_cast<Bonus*>(bonus)->draw(this->BonusSpeedAdd_);
  if (dynamic_cast<Bonus*>(bonus)->getBonus() == PORTEE)
    dynamic_cast<Bonus*>(bonus)->draw(this->BonusPortee_);
  if (dynamic_cast<Bonus*>(bonus)->getBonus() == BOMBNB)
    dynamic_cast<Bonus*>(bonus)->draw(this->BonusBombNb_);
}

void			MyMap::draw()
{
  int			i = -1;
  int			j = -1;
  Ground		ground;

  while (++i < this->y)
    {
      j = -1;
      while (++j < this->x)
	{

	  if (this->map[i][j] != NULL && this->map[i][j]->getType() == BONUS)
	    drawBonus(this->map[i][j]);
	  if (this->map[i][j] != NULL && this->map[i][j]->getType() != BONUS &&
	      this->map[i][j]->getType() != BURN)
	    {
	      if (this->map[i][j]->getType() == WALL)
		this->map[i][j]->draw(this->Wall_);
	      else if (this->map[i][j]->getType() == BOX)
		this->map[i][j]->draw(this->Box_);
	      else if (this->map[i][j]->getType() == BOMB)
	      	{
		  this->map[i][j]->update();
		  this->map[i][j]->draw();
		}
	    }
	  if ((j % 2 == 0 && i % 2 == 1) || (j % 2  == 1 && i % 2 == 0))
	    ground.draw(this->Ground2_, i, j);
	  else
	    ground.draw(this->Ground1_, i, j);
	  if (this->map[i][j] != NULL && this->map[i][j]->getType() == BURN)
            {
              this->map[i][j]->update();
              if (dynamic_cast<Burn*>(this->map[i][j])->getFire() == false)
                this->map[i][j]->draw(this->Explosion_);
              else
                {
		  bool		b = dynamic_cast<Burn*>(this->map[i][j])->getB();

		  delete (this->map[i][j]);
		  if (b == true)
		    {
		      int	random = (rand() % 2);
		      if (random == 0)
			{
			  random = (rand() % 3);
			  this->map[i][j] = new Bonus(i, j, (e_bonus)random);
			}
		      else
			this->map[i][j] = NULL;
		    }
		  else
		    this->map[i][j] = NULL;
                }
            }
	}
    }
}

Bloc			*MyMap::getAt(int x_, int y_) const
{
  // if (y_ < 0 || this->y < y_ || x_ < 0 || this->x < x_)
  //   return (NULL);
  if (this->x <= x_)
    x_ = x_ - 1;
  if (this->y <= y_)
    y_ = y_ - 1;
  if (x_ <= 0)
    x_ = 0;
  if (y_ <= 0)
    y_ = 0;
  return (this->map[y_][x_]);
}

void			MyMap::setAt(Bloc* b, int const& x, int const& y)
{
  if (this->map[y][x] != NULL)
    delete (this->map[y][x]);
  this->map[y][x] = b;
}

std::deque<Vector2d>            MyMap::getPlace() const
{
  return (this->lstPlace);
}

bool                            MyMap::checkArea(Vector2d area[8])
{
  unsigned int		i = 0;
  int			j = 0;

  while (i < this->lstPlace.size())
    {
      j = 0;
      while (j < 8)
        {
          if (this->lstPlace[i].x == area[j].x &&
              this->lstPlace[i].y == area[j].y)
            return true;
          j++;
        }
      i++;
    }
  return false;
}


bool                            MyMap::getArea(int x, int y)
{
  Vector2d              area[8];

  if (x - 1 <= 0 || x + 1 >= this->x)
    return false;
  if (y - 1 <= 0 || y + 1 >= this->y)
    return false;

  area[0].x = 0 + x;
  area[0].y = -1 + y;
  area[1].x = 0 + x;
  area[1].y = 1 + y;
  area[2].x = 0 + x;
  area[2].y = 0 + y;
  area[3].x = -1 + x;
  area[3].y = 0 + y;
  area[4].x = 1 + x;
  area[4].y = 0 + y;
  area[5].x = -1 + x;
  area[5].y = -1 + y;
  area[6].x = 0 + x;
  area[6].y = -1 + y;
  area[7].x = 1 + x;
  area[7].y = -1 + y;
  return true;
}

std::istream&		operator>>(std::istream& is, MyMap &m)
{
  int			intTMP;
  int			i;
  int			j;
  Bloc			***map_;
  char			charTMP;

  is >> intTMP;
  m.setX(intTMP);
  is >> intTMP;
  m.setY(intTMP);
  i = -1;
  map_ = new Bloc**[m.getY()];
  while (++i < m.getY())
    map_[i] = new Bloc*[m.getX()];
  j = -1;
  while (++j < m.getX())
    {
      i = -1;
      while (++i < m.getY())
	{
	  is >> charTMP;
	  if (charTMP == C_WALL)
	    map_[i][j] = new Wall(i, j);
	  else if (charTMP == C_BOX)
	    map_[i][j] = new Box(i, j);
	  else if (charTMP == C_BONUS_P)
	    map_[i][j] = new Bonus(i, j, PORTEE);
	  else if (charTMP == C_BONUS_S)
	    map_[i][j] = new Bonus(i, j, SPEEDADD);
	  else if (charTMP == C_BONUS_B)
	    map_[i][j] = new Bonus(i, j, BOMBNB);
	  else if (charTMP == C_BOMB)
	    map_[i][j] = new Bomb(i, j);
	  else if (charTMP == C_GROUND)
	    map_[i][j] = NULL;
	}
    }
  m.setMap(map_);
  return (is);
}

std::ostream&		operator<<(std::ostream& os, const MyMap &m)
{
  int			i;
  int			j;

  os << m.getX() << std::endl;
  os << m.getY() << std::endl;
  i = -1;
  while (++i < m.getX())
    {
      j = -1;
      while (++j < m.getY())
	{
	  if (m.getAt(i, j) == NULL)
	    os << C_GROUND << std::endl;
	  else if (m.getAt(i, j)->getType() == WALL)
	    os << C_WALL << std::endl;
	  else if (m.getAt(i, j)->getType() == BOX)
	    os << C_BOX << std::endl;
	  else if (m.getAt(i, j)->getType() == BOMB)
	    os << C_BOMB << std::endl;
	  else if (m.getAt(i, j)->getType() == BONUS && dynamic_cast<Bonus*>(m.getAt(i, j))->getBonus() == SPEEDADD)
	    os << C_BONUS_S << std::endl;
	  else if (m.getAt(i, j)->getType() == BONUS && dynamic_cast<Bonus*>(m.getAt(i, j))->getBonus() == PORTEE)
	    os << C_BONUS_P << std::endl;
	  else if (m.getAt(i, j)->getType() == BONUS && dynamic_cast<Bonus*>(m.getAt(i, j))->getBonus() == BOMBNB)
	    os << C_BONUS_B << std::endl;
	}
    }
  return (os);
}
