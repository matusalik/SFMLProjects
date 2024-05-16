#pragma once
#include"Panel.h"
class LeaderboardPanel : public Panel
{
private:
	//Game State Enum
	GameState state;

	//Mouse Position
	sf::Vector2i mousePosWindow;

	//Event
	sf::Event ev;

	//Private functions
	void initEnum();
	void initButtons();
	void initText();
	void initFont();

public:
	void draw(sf::RenderWindow*& window);
	void pollEvents(sf::RenderWindow*& window);
	void update(sf::RenderWindow* window);
	GameState returnGameState();
	void setState(GameState sentState);
	void updateMousePosWindow(sf::RenderWindow* window);
	LeaderboardPanel();
};

