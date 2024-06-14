#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include"MainMenu.h"
#include"HelpPanel.h"
#include"Panel.h"
#include"GameState.h"
#include"GamePlay.h"
#include"Settings.h"
#include"LeaderboardPanel.h"

class Game
{
private:
	//Player
	Player player;

	//Panels
	Panel* gamePlay;
	Panel* mainMenu;
	Panel* helpPanel;
	Panel* settings;
	Panel* leaderboardPanel;

	//Game Difficulty Enum
	GameDifficulty difficulty;

	//Game State Enum
	GameState state;

	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Mouse
	sf::Vector2i mousePosWindow;

	//Private functions
	void initPanels();
	void initVariables();
	void initWindow();
	void initEnum();
	void updateMousePosWindow();
public:
	//Constructors / Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool running();

	//Functions
	void pollEvents();
	void update();
	void render();
};

