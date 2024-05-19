#pragma once
#include<iostream>
#include"Panel.h"
#include"Leaderboard.h"
class LeaderboardPanel : public Panel
{
private:
	//Game State Enum
	GameState state;

	//Mouse Position
	sf::Vector2i mousePosWindow;

	//Event
	sf::Event ev;

	//Buttons
	sf::RectangleShape exitButton;

	//Text
	sf::Text exitText;

	//Textures
	sf::Texture leaderboardPanelBackgroundTexture;

	//Fonts
	sf::Font leaderboardPanelFont;

	//Sprite
	sf::Sprite leaderboardPanelBackgroundSprite;

	//Private functions
	void checkLeaderboard(sf::RenderWindow*& window);
	void initEnum();
	void initButtons();
	void initText();
	void initFont();
	void initTextures();
	void initSprites();

public:
	void draw(sf::RenderWindow*& window);
	void pollEvents(sf::RenderWindow*& window);
	void update(sf::RenderWindow* window);
	GameState returnGameState();
	void setState(GameState sentState);
	void updateMousePosWindow(sf::RenderWindow* window);
	LeaderboardPanel();
};

