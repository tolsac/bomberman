//
// MyGame.cpp for  in /home/tolsa_c//bomberman-2015-tolsa_c
//
// Made by camille tolsa
// Login   <tolsa_c@epitech.net>
//
// Started on  Tue May 29 05:08:21 2012 camille tolsa
// Last update Sun Jun  3 23:05:48 2012 mathieu barnetche
//

#include <cmath>
#include "./MyGame.hh"

#define IAMARGE 0

MyGame::MyGame()
{
  this->dequeKeys.push_back(gdl::Keys::Up);
  this->dequeKeys.push_back(gdl::Keys::Right);
  this->dequeKeys.push_back(gdl::Keys::Down);
  this->dequeKeys.push_back(gdl::Keys::Left);
  this->dequeKeys.push_back(gdl::Keys::Space);
  this->dequeKeys.push_back(gdl::Keys::Z);
  this->dequeKeys.push_back(gdl::Keys::D);
  this->dequeKeys.push_back(gdl::Keys::S);
  this->dequeKeys.push_back(gdl::Keys::Q);
  this->dequeKeys.push_back(gdl::Keys::Tab);
  this->pause = false;
  this->nbPlayers = 0;
  this->nbIAs = 0;
  this->map.generateMap();
  this->p.setText("PAUSE");
  this->p.setSize(100);
  this->p.setPosition(300, 400);
  this->muse.playMusic(0);
}

MyGame::~MyGame()
{
}

void			MyGame::launchMenu()
{
  Menu          mainMenu("./textures/mainmenu.jpg");

  mainMenu.initMenu();
  this->lstMenu.push_back(mainMenu);
}

void			MyGame::subMenuNewGame()
{
}

void			MyGame::subMenuLoadGame()
{
}

void			MyGame::subMenuOptions()
{
}

void			MyGame::subMenuExit()
{
}

void			MyGame::launchGame()
{
  Player		p(1, 1, ((this->map.getX()+this->map.getY())/2)/20);
  Player		p2(1, 14, ((this->map.getX()+this->map.getY())/2)/20);
  IA			ia(9, 10, ((this->map.getX()+this->map.getY())/2)/20);
  IA			ia2(13, 13, ((this->map.getX()+this->map.getY())/2)/20);
  IA			ia3(11, 11, ((this->map.getX()+this->map.getY())/2)/20);
  IA			ia4(9, 14, ((this->map.getX()+this->map.getY())/2)/20);
  IA			ia5(5, 4, ((this->map.getX()+this->map.getY())/2)/20);
  IA			ia6(7, 8, ((this->map.getX()+this->map.getY())/2)/20);
  IA			ia7(7, 2, ((this->map.getX()+this->map.getY())/2)/20);
  IA			ia8(11, 3, ((this->map.getX()+this->map.getY())/2)/20);
  IA			ia9(9, 8, ((this->map.getX()+this->map.getY())/2)/20);
  IA			ia10(3, 12, ((this->map.getX()+this->map.getY())/2)/20);
  IA			ia11(13, 14, ((this->map.getX()+this->map.getY())/2)/20);

  //  this->nbPlayers = 2;
  this->nbIAs = 4;
  this->cam.initialize();
  ia.initialize();
  ia2.initialize();
  ia3.initialize();
  ia4.initialize();
  ia5.initialize();
  ia6.initialize();
  ia7.initialize();
  ia8.initialize();
  ia9.initialize();
  ia10.initialize();
  ia11.initialize();

  p.initialize();
  p2.initialize();
  p.setCommand(gdl::Keys::Up, gdl::Keys::Down, gdl::Keys::Left, gdl::Keys::Right, gdl::Keys::Space);
  p2.setCommand(gdl::Keys::W, gdl::Keys::S, gdl::Keys::A, gdl::Keys::D, gdl::Keys::Tab);
  this->lstPlayersHuman.push_back(p);
  this->lstPlayersHuman[0].setId(this->lstPlayersHuman.size() - 1);
  if (this->nbPlayers == 2)
    {
      this->lstPlayersHuman.push_back(p2);
      this->lstPlayersHuman[1].setId(this->lstPlayersHuman.size() - 1);
    }  
  this->lstPlayersIA.push_front(ia);
  this->lstPlayersIA[0].setId(this->lstPlayersIA.size() + 1);
  this->lstPlayersIA.push_front(ia2);
  this->lstPlayersIA[0].setId(this->lstPlayersIA.size() + 1);
  this->lstPlayersIA.push_front(ia3);
  this->lstPlayersIA[0].setId(this->lstPlayersIA.size() + 1);
  this->lstPlayersIA.push_front(ia4);
  this->lstPlayersIA[0].setId(this->lstPlayersIA.size() + 1);
  this->lstPlayersIA.push_front(ia5);
  this->lstPlayersIA[0].setId(this->lstPlayersIA.size() + 1);
  this->lstPlayersIA.push_front(ia6);
  this->lstPlayersIA[0].setId(this->lstPlayersIA.size() + 1);
  this->lstPlayersIA.push_front(ia7);
  this->lstPlayersIA[0].setId(this->lstPlayersIA.size() + 1);
  this->lstPlayersIA.push_front(ia8);
  this->lstPlayersIA[0].setId(this->lstPlayersIA.size() + 1);
  this->lstPlayersIA.push_front(ia9);
  this->lstPlayersIA[0].setId(this->lstPlayersIA.size() + 1);
  this->lstPlayersIA.push_front(ia10);
  this->lstPlayersIA[0].setId(this->lstPlayersIA.size() + 1);
  this->lstPlayersIA.push_front(ia11);
  this->lstPlayersIA[0].setId(this->lstPlayersIA.size() + 1);
  this->muse.stopMusic(0);
  this->muse.playMusic(1);
}

void			MyGame::getKeys()
{
  int			i = -1;
  int			size = this->dequeKeys.size() / ((this->nbPlayers == 2) ? 1 : 2);

  if (input_.isKeyDown(gdl::Keys::Pause))
    this->pauseMenu();
  while (++i < size && this->pause == false)
    {
      if (this->input_.isKeyDown(dequeKeys[i]))
	{
	  if (dequeKeys[i] != this->lstPlayersHuman[(i > 4 ? 1 : 0)].getCommand().getBomb())
	    this->move((e_direction) (i % 5), this->lstPlayersHuman[(i > 4 ? 1 : 0)]);
	  else
	    this->drop(this->lstPlayersHuman[(i > 4 ? 1 : 0)]);
	}
    }
  if (input_.isKeyDown(gdl::Keys::F5))
    this->save();
  if (input_.isKeyDown(gdl::Keys::F9))
    {
      this->load("save/save.bomb");
    }
}

void			MyGame::move(e_direction d, Bomberman &p)
{
  if (d == LEFT)
    {
      p.setAngle(270);
      if (this->map.getAt((p.getYf() - BLOCKSIZE) / BLOCKSIZE,
			  (p.getXf()) / BLOCKSIZE) == NULL)
	p.setPos(p.getPos().x, p.getPos().y - p.getSpeed(), -(BLOCKSIZE / 2));
      else if (this->map.getAt((p.getYf() - BLOCKSIZE) / BLOCKSIZE,
			       (p.getXf()) / BLOCKSIZE)->getType() == BONUS)
	{
	  dynamic_cast<Bonus*>(this->map.getAt((p.getYf() - BLOCKSIZE) / BLOCKSIZE, (p.getXf()) / BLOCKSIZE))->doBonus(p);
	  if (dynamic_cast<Bonus*>(this->map.getAt((p.getYf() - BLOCKSIZE) / BLOCKSIZE, (p.getXf()) / BLOCKSIZE))->getBonus() == BOMBNB)
	    this->muse.playMusic(4);
	  if (dynamic_cast<Bonus*>(this->map.getAt((p.getYf() - BLOCKSIZE) / BLOCKSIZE, (p.getXf()) / BLOCKSIZE))->getBonus() == PORTEE)
	    this->muse.playMusic(3);
	  this->map.setAt(NULL, (p.getYf() - BLOCKSIZE) / BLOCKSIZE, (p.getXf()) / BLOCKSIZE);
	}
      else if (p.getYf() > (this->map.getAt((p.getYf() - BLOCKSIZE) / BLOCKSIZE,
					    (p.getXf()) / BLOCKSIZE)->getY()
			    + BLOCKSIZE + MARGE))
	p.setPos(p.getPos().x, p.getPos().y - p.getSpeed(), -(BLOCKSIZE / 2));
    }
  else if (d == UP)
    {
      p.setAngle(180);
      if (this->map.getAt((p.getYf()) / BLOCKSIZE,
			  (p.getXf() - BLOCKSIZE) / BLOCKSIZE) == NULL)
	p.setPos(p.getPos().x - p.getSpeed(), p.getPos().y, -(BLOCKSIZE / 2));
      else if (this->map.getAt((p.getYf()) / BLOCKSIZE,
			       (p.getXf() - BLOCKSIZE) / BLOCKSIZE)->getType() == BONUS)
	{
	  dynamic_cast<Bonus*>(this->map.getAt((p.getYf()) / BLOCKSIZE,
					       (p.getXf() - BLOCKSIZE) / BLOCKSIZE))->doBonus(p);
	  if (dynamic_cast<Bonus*>(this->map.getAt(p.getYf() / BLOCKSIZE, (p.getXf() - BLOCKSIZE) / BLOCKSIZE))->getBonus() == BOMBNB)
	    this->muse.playMusic(4);
	  if (dynamic_cast<Bonus*>(this->map.getAt(p.getYf() / BLOCKSIZE, (p.getXf() - BLOCKSIZE) / BLOCKSIZE))->getBonus() == PORTEE)
	    this->muse.playMusic(3);
	  this->map.setAt(NULL, (p.getYf()) / BLOCKSIZE,
			  (p.getXf() - BLOCKSIZE) / BLOCKSIZE);
	}
      else if (p.getXf() > (this->map.getAt((p.getYf()) / BLOCKSIZE,
					    (p.getXf() - BLOCKSIZE) / BLOCKSIZE)->getX() + BLOCKSIZE + MARGE))
	p.setPos(p.getPos().x - p.getSpeed(), p.getPos().y, -(BLOCKSIZE / 2));
    }
  else if (d == RIGHT)
    {
      p.setAngle(90);
      if (this->map.getAt((p.getYf() + BLOCKSIZE) / BLOCKSIZE,
			  (p.getXf()) / BLOCKSIZE) == NULL)
	p.setPos(p.getPos().x, p.getPos().y + p.getSpeed(), -(BLOCKSIZE / 2));
      else if (this->map.getAt((p.getYf() + BLOCKSIZE) / BLOCKSIZE,
			       (p.getXf()) / BLOCKSIZE)->getType() == BONUS)
	{
	  dynamic_cast<Bonus*>(this->map.getAt((p.getYf() + BLOCKSIZE) / BLOCKSIZE,
					       (p.getXf()) / BLOCKSIZE))->doBonus(p);
	  if (dynamic_cast<Bonus*>(this->map.getAt((p.getYf() + BLOCKSIZE) / BLOCKSIZE, (p.getXf()) / BLOCKSIZE))->getBonus() == BOMBNB)
	    this->muse.playMusic(4);
	  if (dynamic_cast<Bonus*>(this->map.getAt((p.getYf() + BLOCKSIZE) / BLOCKSIZE, (p.getXf()) / BLOCKSIZE))->getBonus() == PORTEE)
	    this->muse.playMusic(3);
	  this->map.setAt(NULL, (p.getYf() + BLOCKSIZE) / BLOCKSIZE,
			  (p.getXf()) / BLOCKSIZE);
	}
      else if (p.getYf() < (this->map.getAt((p.getYf() + BLOCKSIZE) / BLOCKSIZE,
					    (p.getXf()) / BLOCKSIZE)->getY() - MARGE))
	p.setPos(p.getPos().x, p.getPos().y + p.getSpeed(), -(BLOCKSIZE / 2));
    }
  else if (d == DOWN)
    {
      p.setAngle(0);
      if (this->map.getAt((p.getYf()) / BLOCKSIZE,
			  (p.getXf() + BLOCKSIZE) / BLOCKSIZE) == NULL)
	p.setPos(p.getPos().x + p.getSpeed(), p.getPos().y, -(BLOCKSIZE / 2));
      else if (this->map.getAt((p.getYf()) / BLOCKSIZE,
			       (p.getXf() + BLOCKSIZE) / BLOCKSIZE)->getType() == BONUS)
	{
	  dynamic_cast<Bonus*>(this->map.getAt((p.getYf()) / BLOCKSIZE,
					       (p.getXf() + BLOCKSIZE) / BLOCKSIZE))->doBonus(p);
	  if (dynamic_cast<Bonus*>(this->map.getAt(p.getYf() / BLOCKSIZE, (p.getXf() + BLOCKSIZE) / BLOCKSIZE))->getBonus() == BOMBNB)
	    this->muse.playMusic(4);
	  if (dynamic_cast<Bonus*>(this->map.getAt(p.getYf() / BLOCKSIZE, (p.getXf() + BLOCKSIZE) / BLOCKSIZE))->getBonus() == PORTEE)
	    this->muse.playMusic(3);
	  this->map.setAt(NULL, (p.getYf()) / BLOCKSIZE,
			  (p.getXf() + BLOCKSIZE) / BLOCKSIZE);
	}
      else if (p.getXf() < (this->map.getAt((p.getYf()) / BLOCKSIZE,
					    (p.getXf() + BLOCKSIZE) / BLOCKSIZE)->getX() - MARGE))
	p.setPos(p.getPos().x + p.getSpeed(), p.getPos().y, -(BLOCKSIZE / 2));
    }
  p.update();
}

void			MyGame::findFocus(IA& cpu)
{
  int			min;
  int			i = 1;
  bool			N = true, K = false;

  if (this->lstPlayersHuman.size() > 1 &&
      ((sqrt(pow((this->lstPlayersHuman[0].getXf()) - (cpu.getXf()), 2) +
	     pow((this->lstPlayersHuman[0].getYf()) - (cpu.getYf()), 2))) >
       sqrt(pow((this->lstPlayersHuman[1].getXf()) - (cpu.getXf()), 2) +
	    pow((this->lstPlayersHuman[1].getYf()) - (cpu.getYf()), 2))))
    min = 1;
  else
    min = 0;

  while (i <= 4 && N)
    {
      if (this->map.getAt((cpu.getYf() + IAMARGE - i * BLOCKSIZE) / BLOCKSIZE, cpu.getXf() / BLOCKSIZE) != NULL && this->map.getAt((cpu.getYf() + IAMARGE - i * BLOCKSIZE) / BLOCKSIZE, cpu.getXf() /BLOCKSIZE)->getType() == BOMB)
      	{
	  N = false;
	  K = true;
	  if (this->map.getAt(cpu.getYf() / BLOCKSIZE, (cpu.getXf() - IAMARGE + BLOCKSIZE) / BLOCKSIZE) == NULL || this->map.getAt(cpu.getYf() / BLOCKSIZE, (cpu.getXf() - IAMARGE + BLOCKSIZE) / BLOCKSIZE)->getType() == BONUS)
	    move(DOWN, cpu);
	  else if (this->map.getAt(cpu.getYf() / BLOCKSIZE, (cpu.getXf() + IAMARGE - BLOCKSIZE) / BLOCKSIZE) == NULL || this->map.getAt(cpu.getYf() / BLOCKSIZE, (cpu.getXf() + IAMARGE) / BLOCKSIZE - 1)->getType() == BONUS)
	    move(UP, cpu);
	  else
	    move(RIGHT, cpu);
	}
      i++;
    }
  N = true;
  i = 1;
  while (i <= 4 && N)
    {
      if (this->map.getAt((cpu.getYf() - IAMARGE + i * BLOCKSIZE) / BLOCKSIZE, cpu.getXf() / BLOCKSIZE) != NULL && this->map.getAt((cpu.getYf() - IAMARGE + i * BLOCKSIZE) / BLOCKSIZE, cpu.getXf() / BLOCKSIZE)->getType() == BOMB)
	{
	  N = false;
	  K = true;
	  if (this->map.getAt(cpu.getYf() / BLOCKSIZE, (cpu.getXf() - IAMARGE + BLOCKSIZE) / BLOCKSIZE) == NULL || this->map.getAt(cpu.getYf() / BLOCKSIZE, (cpu.getXf() - IAMARGE + BLOCKSIZE) / BLOCKSIZE)->getType() == BONUS)
	    move(DOWN, cpu);
	  else if (this->map.getAt(cpu.getYf() / BLOCKSIZE, (cpu.getXf() + IAMARGE - BLOCKSIZE) / BLOCKSIZE) == NULL || this->map.getAt(cpu.getYf() / BLOCKSIZE, (cpu.getXf() + IAMARGE - BLOCKSIZE) / BLOCKSIZE)->getType() == BONUS)
	    move(UP, cpu);
	  else
	    move(LEFT, cpu);
	}
      i++;
    }

  N = true;
  i = 1;
  while (i <= 4 && N)
    {
      if (this->map.getAt(cpu.getYf() / BLOCKSIZE, (cpu.getXf() + IAMARGE - i * BLOCKSIZE) / BLOCKSIZE) != NULL && this->map.getAt(cpu.getYf() / BLOCKSIZE, (cpu.getXf() - IAMARGE - i * BLOCKSIZE) / BLOCKSIZE)->getType() == BOMB)
	{
	  N = false;
	  K = true;
	  if (this->map.getAt((cpu.getYf() - IAMARGE + BLOCKSIZE) / BLOCKSIZE, cpu.getXf() / BLOCKSIZE) == NULL || this->map.getAt((cpu.getYf() - IAMARGE + BLOCKSIZE) / BLOCKSIZE, cpu.getXf() / BLOCKSIZE)->getType() == BONUS)
	    move(RIGHT, cpu);
	  else if (this->map.getAt((cpu.getYf() + IAMARGE - BLOCKSIZE) / BLOCKSIZE, cpu.getXf() / BLOCKSIZE) == NULL || this->map.getAt((cpu.getYf() + IAMARGE - BLOCKSIZE) / BLOCKSIZE, cpu.getXf() / BLOCKSIZE)->getType() == BONUS)
	    move(LEFT, cpu);
	  else
	    move(DOWN, cpu);
	}
      i++;
    }

  N = true;
  i = 1;
  while (i <= 4 && N)
    {
      if (this->map.getAt(cpu.getYf() / BLOCKSIZE, (cpu.getXf() - IAMARGE + i * BLOCKSIZE) / BLOCKSIZE) != NULL && this->map.getAt(cpu.getYf() / BLOCKSIZE, (cpu.getXf() - IAMARGE + i * BLOCKSIZE) / BLOCKSIZE)->getType() == BOMB)
	{
	  N = false;
	  K = true;
	  if (this->map.getAt((cpu.getYf() - IAMARGE + BLOCKSIZE) / BLOCKSIZE, cpu.getXf() / BLOCKSIZE) == NULL || this->map.getAt((cpu.getYf() - IAMARGE + BLOCKSIZE) / BLOCKSIZE, cpu.getXf() / BLOCKSIZE)->getType() == BONUS)
	    move(RIGHT, cpu);
	  else if (this->map.getAt((cpu.getYf() + IAMARGE - BLOCKSIZE) / BLOCKSIZE, cpu.getXf() / BLOCKSIZE) == NULL || this->map.getAt((cpu.getYf() + IAMARGE - BLOCKSIZE) / BLOCKSIZE, cpu.getXf() / BLOCKSIZE)->getType() == BONUS)
	    move(LEFT, cpu);
	  else
	    move(UP, cpu);
	}
      i++;
    }

  if (K == false)
    {
      if (abs(cpu.getXf() - this->lstPlayersHuman[min].getXf()) != 0 &&
	  abs(cpu.getYf() - this->lstPlayersHuman[min].getYf()) != 0)
	{
	  if (abs(cpu.getXf() - this->lstPlayersHuman[min].getXf()) <
	      abs(cpu.getYf() - this->lstPlayersHuman[min].getYf()))
	    {
	      if (cpu.getYf() > this->lstPlayersHuman[min].getYf())
		{
		  if (this->map.getAt((cpu.getYf() - BLOCKSIZE + IAMARGE) / BLOCKSIZE,
				      (cpu.getXf()) / BLOCKSIZE) != NULL &&
		      this->map.getAt((cpu.getYf() - BLOCKSIZE + IAMARGE) / BLOCKSIZE,
				      (cpu.getXf()) / BLOCKSIZE)->getType() != BONUS)
		    if (cpu.getXf() > this->lstPlayersHuman[min].getXf())
		    move(UP, cpu);
		  else
		    move(DOWN, cpu);
		  else
		    move(LEFT, cpu);
		}
	      else
		{
		  if (this->map.getAt((cpu.getYf() + BLOCKSIZE - IAMARGE) / BLOCKSIZE,
				      (cpu.getXf()) / BLOCKSIZE) != NULL &&
		      this->map.getAt((cpu.getYf() + BLOCKSIZE - IAMARGE) / BLOCKSIZE,
				      (cpu.getXf()) / BLOCKSIZE)->getType() != BONUS)
		    if (cpu.getXf() > this->lstPlayersHuman[min].getXf())
		      move(UP, cpu);
		    else
		      move(DOWN, cpu);
		  else
		    move(RIGHT, cpu);
		}
	    }
	  else
	    {
	      if (cpu.getXf() > this->lstPlayersHuman[min].getXf())
		{
		  if (this->map.getAt((cpu.getYf()) / BLOCKSIZE,
				      (cpu.getXf() - BLOCKSIZE + IAMARGE) / BLOCKSIZE) != NULL &&
		      this->map.getAt((cpu.getYf()) / BLOCKSIZE,
				      (cpu.getXf() - BLOCKSIZE + IAMARGE) / BLOCKSIZE)->getType() != BONUS)
		    if (cpu.getYf() > this->lstPlayersHuman[min].getYf())
		    move(LEFT, cpu);
		  else
		    move(RIGHT, cpu);
		  else
		    move(UP, cpu);
		}
	      else
		{
		  if (this->map.getAt((cpu.getYf()) / BLOCKSIZE,
				      (cpu.getXf() + BLOCKSIZE - IAMARGE) / BLOCKSIZE) != NULL &&
		      this->map.getAt((cpu.getYf()) / BLOCKSIZE,
				      (cpu.getXf() + BLOCKSIZE - IAMARGE) / BLOCKSIZE)->getType() != BONUS)
		    if (cpu.getYf() > this->lstPlayersHuman[min].getYf())
		    move(LEFT, cpu);
		  else
		    move(RIGHT, cpu);
		  else
		    move(DOWN, cpu);
		}
	    }
	}
    }
  if ((abs(cpu.getXf() - this->lstPlayersHuman[min].getXf()) < 300) &&
      (abs(cpu.getYf() - this->lstPlayersHuman[min].getYf()) < 300))
    this->drop(cpu);
}

void			MyGame::drop(Bomberman &p)
{
  unsigned int		i = -1;

  while (++i < this->lstTimer.size())
    {
      if (this->lstTimer[i].bombY == (int)(p.getYf() / BLOCKSIZE) &&
	  this->lstTimer[i].bombX == (int)(p.getXf() / BLOCKSIZE))
	return;
    }
  Bomb *b = new Bomb((p.getXf()) / BLOCKSIZE, (p.getYf()) / BLOCKSIZE, p.getId(), 2);
  MyClock	Clock((p.getXf())/ BLOCKSIZE, (p.getYf())/ BLOCKSIZE, p.getId());

  if (p.getStockBomb() > 0)
    {
      p.setStockBomb(p.getStockBomb() - 1);
      this->lstTimer.push_front(Clock);
      this->map.setAt(b, (p.getYf()) / BLOCKSIZE, (p.getXf()) / BLOCKSIZE);
    }
}

void			MyGame::initialize()
{
  unsigned int          i = -1;

  this->window_.create();
  this->cam.initialize();
  this->gameClock_.play();
  this->launchMenu();

  while (++i < this->lstMenu.size())
    this->lstMenu[i].initialize();
}

void			MyGame::update()
{
  unsigned int          i = -1;
  int                   ret;
  std::string		s;

  this->gameClock_.update();
  this->cam.update(gameClock_, input_);
  if (this->lstMenu.size() == 0)
    this->getKeys();

  while (++i < this->lstPlayersIA.size())
    {
      if (this->lstPlayersIA[i].getActiv() == true)
	this->findFocus(this->lstPlayersIA[i]);
    }
  i = -1;
  while (++i < this->lstTimer.size())
    {
      if (this->lstTimer[i].update())
	this->explose(this->lstTimer[i].bombX, this->lstTimer[i].bombY);
    }
  i = -1;
  while (++i < this->lstMenu.size())
    {
      ret = this->lstMenu[i].update(input_);
      if (ret == 1)
	{
	  while (!this->lstMenu.empty())
	    this->lstMenu.pop_front();
	  this->nbPlayers = 2;
	  this->launchGame();
	}
      else if (ret == 2)
	{
	  while (!this->lstMenu.empty())
	    {
	      s = this->lstMenu[0].filename;
	      this->lstMenu.pop_front();
	    }
	  this->load(s);
	}
      else if (ret == 3)
	{
	  while (!this->lstMenu.empty())
	    this->lstMenu.pop_front();
	  this->nbPlayers = 1;
	  this->launchGame();
	}
      else if (ret == 4)
	{
	  while (!this->lstMenu.empty())
	    this->lstMenu.pop_front();
	  this->nbPlayers = 2;
	  this->launchGame();
	}
    }
  if (this->nbPlayers == 1)
    this->cam.setPointView(this->lstPlayersHuman.front().getPos());
  else if (this->nbPlayers == 2)
    {
      float		x;

      if (abs((this->lstPlayersHuman[0].getPos().x - this->lstPlayersHuman[1].getPos().x) / 2) > abs((this->lstPlayersHuman[0].getPos().y - this->lstPlayersHuman[1].getPos().y) / 2))
	x = abs((this->lstPlayersHuman[0].getPos().x - this->lstPlayersHuman[1].getPos().x) / 2);
      else
	x = abs((this->lstPlayersHuman[0].getPos().y - this->lstPlayersHuman[1].getPos().y) / 2);
      Vector3f	mid((this->lstPlayersHuman[0].getPos().x + this->lstPlayersHuman[1].getPos().x) / 2, (this->lstPlayersHuman[0].getPos().y + this->lstPlayersHuman[1].getPos().y) / 2, x * 1.1f);
      this->cam.setPointView(mid);
    }
}

void			MyGame::draw()
{
  unsigned int		i = -1;

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
  glClearDepth(1.0f);
  if (this->pause == true)
    this->p.draw();
  if (this->lstMenu.size() == 0)
    {
      this->map.draw();
      while (++i < this->nbPlayers)
	if (lstPlayersHuman[i].isAlive() == true)
	  this->lstPlayersHuman[i].draw();
      i = -1;
      while (++i < this->lstPlayersIA.size())
	if (lstPlayersIA[i].getActiv() == true)
	  this->lstPlayersIA[i].draw();
    }
  i = -1;
  while (++i < this->lstMenu.size())
    this->lstMenu[i].draw();
  this->window_.display();
}

void			MyGame::unload()
{
}

void                    MyGame::pauseMenu()
{
  Menu          mainMenu("./textures/menuselect1.jpg");
  unsigned int  i = -1;

  this->pause = (!this->pause);
  usleep(50000);
  if (pause == true)
    {
      while (++i < this->lstTimer.size())
	this->lstTimer[i].cl.pause();
    }
  else
    {
      while (++i < this->lstTimer.size())
	this->lstTimer[i].cl.play();
      i = -1;
      while (++i < this->lstMenu.size())
	this->lstMenu.pop_front();
    }
}

void			MyGame::explose(int x, int y)
{
  unsigned int		i = -1;
  unsigned int		j = -1;
  unsigned int		k = -1;
  bool			ok = true;

  while (++i < this->lstTimer.size() -1 && ok == true)
    if (this->lstTimer[i].bombX == x &&
	this->lstTimer[i].bombY == y)
      ok = false;
  ok = true;
  while (++j < this->lstPlayersHuman.size() && ok == true)
    {
      if (this->lstTimer[i].getId() == this->lstPlayersHuman[j].getId())
	{
	  ok = false;
	  this->lstPlayersHuman[j].setStockBomb(this->lstPlayersHuman[j].getStockBomb() + 1);
	}
    }
  if (ok == false)
    {
      this->lstTimer.pop_back();
      this->deflag(y, x, this->lstPlayersHuman[j-1].getPortee());
    }
  else
    {
      while (++k < this->lstPlayersIA.size() && ok == true)
	{
	  if (this->lstTimer[i].getId() == this->lstPlayersIA[k].getId())
	    {
	      ok = false;
	      this->lstPlayersIA[k].setStockBomb(this->lstPlayersIA[k].getStockBomb() + 1);
	    }
	}
      this->lstTimer.pop_back();
      this->deflag(y, x, this->lstPlayersIA[(int) j - 1].getPortee());
    }

}

void			MyGame::deflag(int x, int y, unsigned int portee)
{
  unsigned int		i = 1;
  unsigned int		j = -1;
  bool			N = true;

  this->map.setAt(new Burn(y, x), x, y);
  this->muse.playMusic(2);
  while (++j < this->lstPlayersHuman.size())
    {
      if (N && y == (int)(this->lstPlayersHuman[j].getXf() / BLOCKSIZE) &&
	  (int)(this->lstPlayersHuman[j].getYf() / BLOCKSIZE) == x)
	{
	  if (this->lstPlayersHuman[j].getId() == 0)
	    {
	      this->lstPlayersHuman.pop_front();
	      this->nbPlayers--;
	    }
	  else if (this->lstPlayersHuman[j].getId() == 1)
	    {
	      this->lstPlayersHuman.pop_back();
	      this->nbPlayers--;
	    }
	  if (this->nbPlayers == 0)
	    exit(0);
	}
    }
  j = -1;
  while (++j < this->lstPlayersIA.size())
    {
      if (N && y == (int)(this->lstPlayersIA[j].getXf() / BLOCKSIZE) &&
	  (int)(this->lstPlayersIA[j].getYf() / BLOCKSIZE) == x)
	{
	  this->lstPlayersIA[j].setActiv(false);
	}
    }

  //Nord
  while (i <= portee && N)
    {
      if (this->map.getAt(x, y - i) != NULL)
	{
	  if (this->map.getAt(x, y - i)->getType() == BOMB)
	    {
	      j = -1;
	      while (++j < this->lstTimer.size())
		{
		  if (this->lstTimer[j].bombY == x &&
		      this->lstTimer[j].bombX == y - (int) i)
		    {
		      this->lstTimer[j].fire = true;
		    }
		}
	      this->map.setAt(new Burn(y - (int) i, x), x, y - (int) i);
	    }
	  else
	    {
	      N = false;
	      if (this->map.getAt(x, y - i)->getType() == BOX)
		this->map.setAt(new Burn(y - i, x, true), x, y - i);
	      else if (this->map.getAt(x, y - i)->getType() != WALL)
		this->map.setAt(new Burn(y - i, x), x, y - i);
	    }
	}
      else
	{
	  j = -1;
	  if (this->map.getAt(x, y - i) == NULL)
	    this->map.setAt(new Burn(y - i, x), x, y - i);
	  while (++j < this->lstPlayersHuman.size())
	    {
	      if (N && y - (int) i == (int)(this->lstPlayersHuman[j].getXf() / BLOCKSIZE) &&
		  (int)(this->lstPlayersHuman[j].getYf()/ BLOCKSIZE) == x)
		{
		  if (this->lstPlayersHuman[j].getId() == 0)
		    {
		      this->lstPlayersHuman.pop_front();
		      this->nbPlayers--;
		    }
		  else if (this->lstPlayersHuman[j].getId() == 1)
		    {
		      this->lstPlayersHuman.pop_back();
		      this->nbPlayers--;
		    }
		  if (this->nbPlayers == 0)
		    exit(0);
		}
	    }
	  j = -1;
	  while (++j < this->lstPlayersIA.size())
	    {
	      if (N && y - (int) i == (int)(this->lstPlayersIA[j].getXf() / BLOCKSIZE) &&
		  (int)(this->lstPlayersIA[j].getYf() / BLOCKSIZE) == x)
		{
		  this->lstPlayersIA[j].setActiv(false);
		}
	    }
	  i++;
	}
    }

  //sud
  i = 1;
  j = -1;
  N = true;
  while (i <= portee && N)
    {
      if (this->map.getAt(x, y + i) != NULL)
	{
	  if (this->map.getAt(x, y + i)->getType() == BOMB)
	    {
	      j = -1;
	      while (++j < this->lstTimer.size())
		{
		  if (this->lstTimer[j].bombY == x &&
		      this->lstTimer[j].bombX == y + (int) i)
		    {
		      this->lstTimer[j].fire = true;
		    }
		}
	      this->map.setAt(new Burn(y + i, x), x, y + i);
	    }
	  else
	    {
	      N = false;
	      if (this->map.getAt(x, y + i)->getType() == BOX)
		this->map.setAt(new Burn(y + i, x, true), x, y + i);
	      else if (this->map.getAt(x, y + i)->getType() != WALL)
		this->map.setAt(new Burn(y + i, x), x, y + i);
	    }
	}
      else
	{
	  j = -1;
	  if (this->map.getAt(x, y + i) == NULL)
	    this->map.setAt(new Burn(y + i, x), x, y + i);
	  while (++j < this->lstPlayersHuman.size())
	    {
	      if (N && (y + i) == (int)(this->lstPlayersHuman[j].getXf() / BLOCKSIZE) &&
		  (int)(this->lstPlayersHuman[j].getYf() / BLOCKSIZE) == x)
		{
		  if (this->lstPlayersHuman[j].getId() == 0)
		    {
		      this->lstPlayersHuman.pop_front();
		      this->nbPlayers--;
		    }
		  else if (this->lstPlayersHuman[j].getId() == 1)
		    {
		      this->lstPlayersHuman.pop_back();
		      this->nbPlayers--;
		    }
		  if (this->nbPlayers == 0)
		    exit(0);
		}
	    }
	  j = -1;
	  while (++j < this->lstPlayersIA.size())
	    {
	      if (N && y + (int) i == (int)(this->lstPlayersIA[j].getXf() / BLOCKSIZE) &&
		  (int)(this->lstPlayersIA[j].getYf() / BLOCKSIZE) == x)
		{
		  this->lstPlayersIA[j].setActiv(false);
		}
	    }
	  i++;
	}
    }

  //west
  i = 1;
  j = -1;
  N = true;
  while (i <= portee && N)
    {
      if (this->map.getAt(x - i, y) != NULL)
	{
	  if (this->map.getAt(x - i, y)->getType() == BOMB)
	    {
	      j = -1;
	      while (++j < this->lstTimer.size())
		{
		  if (this->lstTimer[j].bombY == x - (int) i &&
		      this->lstTimer[j].bombX == y)
		    {
		      this->lstTimer[j].fire = true;
		    }
		}
	      this->map.setAt(new Burn(y, x - i), x - i, y);
	    }
	  else
	    {
	      N = false;
	      if (this->map.getAt(x - i, y)->getType() == BOX)
		this->map.setAt(new Burn(y, x - i, true), x - i, y);
	      else if (this->map.getAt(x - i, y)->getType() != WALL)
		this->map.setAt(new Burn(y, x - i), x - i, y);
	    }
	}
      else
	{
	  j = -1;
	  if (this->map.getAt(x - i, y) == NULL)
	    this->map.setAt(new Burn(y, x - i), x - i, y);
	  while (++j < this->lstPlayersHuman.size())
	    {
	      if (N && y == (int)(this->lstPlayersHuman[j].getXf() / BLOCKSIZE) &&
		  (int)(this->lstPlayersHuman[j].getYf() / BLOCKSIZE) == x - (int) i)
		{
		  if (this->lstPlayersHuman[j].getId() == 0)
		    {
		      this->lstPlayersHuman.pop_front();
		      this->nbPlayers--;
		    }
		  else if (this->lstPlayersHuman[j].getId() == 1)
		    {
		      this->lstPlayersHuman.pop_back();
		      this->nbPlayers--;
		    }
		  if (this->nbPlayers == 0)
		    exit(0);
		}
	    }
	  j = -1;
	  while (++j < this->lstPlayersIA.size())
	    {
	      if (N && y == (int)(this->lstPlayersIA[j].getXf() / BLOCKSIZE) &&
		  (int)(this->lstPlayersIA[j].getYf() / BLOCKSIZE) == x - (int) i)
		{
		  this->lstPlayersIA[j].setActiv(false);
		}
	    }
	  i++;
	}
    }

  //est
  i = 1;
  j = -1;
  N = true;
  while (i <= portee && N)
    {
      if (this->map.getAt(x + i, y) != NULL)
	{
	  if (this->map.getAt(x + i, y)->getType() == BOMB)
	    {
	      j = -1;
	      while (++j < this->lstTimer.size())
		{
		  if (this->lstTimer[j].bombY == x + (int) i &&
		      this->lstTimer[j].bombX == y)
		    {
		      this->lstTimer[j].fire = true;
		    }
		}
	      this->map.setAt(new Burn(y, x + i, true), x + i, y);
	    }
	  else
	    {
	      N = false;
	      if (this->map.getAt(x + i, y)->getType() == BOX)
		this->map.setAt(new Burn(y, x + i), x + i, y);
	      else if (this->map.getAt(x + i, y)->getType() != WALL)
		this->map.setAt(new Burn(y, x + i), x + i, y);
	    }
	}
      else
	{
	  j = -1;
	  if (this->map.getAt(x + i, y) == NULL)
	    this->map.setAt(new Burn(y, x + i), x + i, y);
	  while (++j < this->lstPlayersHuman.size())
	    {
	      if (N && y == (int)(this->lstPlayersHuman[j].getXf() / BLOCKSIZE) &&
		  (int)(this->lstPlayersHuman[j].getYf() / BLOCKSIZE) == x + (int) i)
		{
		  if (this->lstPlayersHuman[j].getId() == 0)
		    {
		      this->lstPlayersHuman.pop_front();
		      this->nbPlayers--;
		    }
		  else if (this->lstPlayersHuman[j].getId() == 1)
		    {
		      this->lstPlayersHuman.pop_back();
		      this->nbPlayers--;
		    }
		  if (this->nbPlayers == 0)
		    exit(0);
		}
	    }
	  j = -1;
	  while (++j < this->lstPlayersIA.size())
	    {
	      if (N && y == (int)(this->lstPlayersIA[j].getXf() / BLOCKSIZE) &&
		  (int)(this->lstPlayersIA[j].getYf() / BLOCKSIZE) == x + (int) i)
		{
		  this->lstPlayersIA[j].setActiv(false);
		}
	    }
	  i++;
	}
    }
}

void			MyGame::save() const
{
  std::ofstream		saveFile;
  std::ostringstream	saveName;
  time_t		t;
  unsigned int		i;

  t = time(NULL);
  //saveName << t << ".bomb";
  saveName << "save/save.bomb";
  std::cout << "timestamp : " << t << std::endl;
  std::cout << "Sauvegarde dans " << saveName.str() << "." << std::endl;
  saveFile.open(saveName.str().c_str());
  saveFile << this->nbPlayers << std::endl;
  saveFile << this->nbIAs << std::endl;
  saveFile << this->levelIA << std::endl;
  saveFile << this->x << std::endl;
  saveFile << this->y << std::endl;
  saveFile << this->cam;
  saveFile << this->map;
  saveFile << this->pause << std::endl;
  i = -1;
  while (++i < this->lstPlayersHuman.size())
    saveFile << this->lstPlayersHuman[i];
  i = -1;
  while (++i < this->lstPlayersIA.size())
    saveFile << this->lstPlayersIA[i];
  saveFile.close();
  std::cout << "Sauvegarde terminée." << std::endl;
}

void			MyGame::load(std::string const &filename)
{
  std::ifstream		saveFile;
  unsigned int		i;
  Player		p;
  IA			ia;
  MyClock		cl;

  std::cout << "Chargement de " << filename << "." << std::endl;
  saveFile.open(filename.c_str());
  saveFile >> this->nbPlayers;
  saveFile >> this->nbIAs;
  saveFile >> this->levelIA;
  saveFile >> this->x;
  saveFile >> this->y;
  saveFile >> this->cam;
  saveFile >> this->map;
  saveFile >> this->pause;
  i = -1;
  while (++i < this->nbPlayers)
    saveFile >> this->lstPlayersHuman[i];
  i = -1;
  while ( (int) ++i < this->nbIAs)
    saveFile >> this->lstPlayersIA[i];
  saveFile.close();
  std::cout << "Chargememt terminé." << std::endl;
}
