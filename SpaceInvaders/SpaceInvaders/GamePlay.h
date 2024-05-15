#pragma once
#include"Panel.h"
#include"GameState.h"
class GamePlay : public Panel
{
private:
	//Game State
	GameState state;
public:
	virtual void draw(sf::RenderWindow*& window);
	virtual void update(sf::RenderWindow* window);
	virtual void pollEvents(sf::RenderWindow*& window);
	virtual GameState returnGameState();
	GamePlay();
};

