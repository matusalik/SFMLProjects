#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

class Game
{
private:
	//Enum game state
	enum GameState {
		MAIN_MENU,
		HELP_PANEL
	}state;

	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Game objects
	
	//Buttons
	sf::RectangleShape playButton;
	sf::RectangleShape helpButton;
	sf::RectangleShape exitButton;

	//Text boxes
	sf::RectangleShape nickTextBox;
	bool isNickTextBoxClicked = false;

	//Text and fonts
	sf::Text MainMenuTitle;
	sf::Text MainMenuNick;
	sf::Text Nick;
	sf::Text playButtonText;
	sf::Text helpButtonText;
	sf::Text exitButtonText;
	std::string NickStr = "";
	sf::Vector2i MainMenuTitlePos;
	sf::Font MainMenuFont;
	int mainMenuCharacterSize = 40;
	int mainMenuHowOftenResizeCounter = 0;
	bool charSizeState = true;


	//Mouse
	sf::Vector2i mousePosWindow;

	//Private functions
	void initVariables();
	void initWindow();
	void initEnemies();
	void initButton();
	void initText();
	void initFont();
	void initTextBoxes();
	void initEnum();
	void updateMousePosWindow();
	void updateMainMenuCharSize();
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

