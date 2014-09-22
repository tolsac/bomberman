//
// MyMusic.hh for MyMusic in /home/clariv_e//Projets/C++/Bomberman/collisions
// 
// Made by erick clarivet
// Login   <clariv_e@epitech.net>
// 
// Started on  Sun Jun  3 02:33:09 2012 erick clarivet
// Last update Sun Jun  3 07:52:21 2012 erick clarivet
//

#ifndef	__MYMUSIC_HH__
#define	__MYMUSIC_HH__

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <deque>

class	MyMusic
{
  sf::Music	music1;
  sf::Music	music2;
  sf::Music	music3;
  sf::Music	music4;
  sf::Music	music5;
  sf::Music	music6;
public:
  MyMusic();
  ~MyMusic();

  void				  playMusic(const int& i);
  void				  pauseMusic(const int& i);
  void				  stopMusic(const int& i);

  void				  update();
  sf::Music&			  getMusic(const int& i);
};

#endif
