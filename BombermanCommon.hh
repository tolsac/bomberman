//
// bombermanCommon.hh for bomberman in /home/nerevarine/Documents/bomberman-2015-tolsa_c
//
// Made by nerevarine
// Login   <nerevarine@scarlett>
//
// Started on Mon May 28 20:05:37 2012 nerevarine
// Last update Sun Jun  3 19:58:53 2012 nerevarine
//

#ifndef _BOMBERMANCOMMON_HH_
#define _BOMBERMANCOMMON_HH_

#include <iostream>
#include <sstream>
#include <fstream>
#include <deque>
#include <string>
#include <cstdlib>
#include <ctime>

//GDL
#include "./lib/include/Clock.hpp"
#include "./lib/include/GameClock.hpp"
#include "./lib/include/Game.hpp"
#include "./lib/include/Input.hpp"
#include "./lib/include/Model.hpp"
#include "./lib/include/Image.hpp"
#include "./lib/include/Window.hpp"
#include "./lib/include/Color.hpp"
#include "./lib/include/Assert.hpp"
#include "./lib/include/Text.hpp"

#include <GL/gl.h>
#include <GL/glu.h>

#include <sys/types.h>
#include <dirent.h>

#include "./Vector3f.hh"
#include "./Vector2d.hh"

#define	BLOCKSIZE	150.0f
#define MARGE		50
#define NB_BOMB		2
#define PORTEE_BOMB	2

enum		e_direction
  {
    UP,
    RIGHT,
    DOWN,
    LEFT,
    SPACE
  };

enum		e_type
  {
    PLAYER,
    CPU,
    WALL,
    BOX,
    BOMB,
    BONUS,
    GROUND,
    BURN
  };

enum		e_bonus
  {
    SPEEDADD,
    PORTEE,
    BOMBNB
  };

#endif /* !BOMBERMANCOMMON_HH */
