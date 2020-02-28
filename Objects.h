#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

class Objects
{
public:
	Objects() = delete;
	static void set_blank(Game& g);
	static void space_ship(Game& g);
	static void pulsar(Game& g);
	static void crocodile(Game& g);
	static void diehard(Game& g);
	static void cross(Game& g);
	static void space_ship(sf::RenderWindow& window, Game& g);
	static void crocodile(sf::RenderWindow& window, Game& g);
	static void diehard(sf::RenderWindow& window, Game& g);
	static void square(sf::RenderWindow& window, Game& g);
	static void dot(sf::RenderWindow& window, Game& g);
	static void trigger(sf::RenderWindow& window, Game& g);
	static void circle(sf::RenderWindow& window, Game& g);
};

