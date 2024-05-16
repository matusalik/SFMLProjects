#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include"GameState.h"
class Panel
{
public:
	virtual void draw(sf::RenderWindow*& window) = 0;
	virtual void update(sf::RenderWindow* window) = 0;
	virtual void pollEvents(sf::RenderWindow*& window) = 0;
	virtual GameState returnGameState() = 0;
	virtual void setState(GameState sentState) = 0;
};

