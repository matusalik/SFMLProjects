#pragma once
#include"Panel.h"
#include"GameState.h"
class GamePlay : public Panel
{
private:
	//Game State
	GameState state;

	//Mose Position
	sf::Vector2i mousePosWindow;

public:
	void draw(sf::RenderWindow*& window);
	void update(sf::RenderWindow* window);
	void pollEvents(sf::RenderWindow*& window);
	GameState returnGameState();
	void setState(GameState sentState);
	void updateMousePosWindow(sf::RenderWindow* window);
	GamePlay();
};

