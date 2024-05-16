#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include"Panel.h"
#include"Leaderboard.h"
class MainMenu : public Panel
{
private:
	//Sprite
	sf::Sprite mainMenuBackgroundSprite;
	sf::Sprite settingsButtonSprite;
	sf::Sprite leaderboardsButtonSprite;

	//Textures
	sf::Texture mainMenuBackgroundTexture;
	sf::Texture settingsButtonTexture;
	sf::Texture settingsButtonTextureOutline;
	sf::Texture leaderboardsButtonTexture;
	sf::Texture leaderboardsButtonTextureOutline;

	//Leaderboard
	Leaderboard leaderBoard;

	//Game State Enum
	GameState state;

	//Variables
	bool isGuestChecked = false;
	int mainMenuCharacterSize;
	int mainMenuHowOftenResizeCounter;
	bool charSizeState;

	//Events
	sf::Event ev;

	//Private functions
	void initEnum();
	void initSprites();
	void initTextures();
	void initButton();
	void initText();
	void initFont();
	void initTextBoxes();
	void initVariables();
	void updateMousePosWindow(sf::RenderWindow* window);

	//Buttons
	sf::RectangleShape playButton;
	sf::RectangleShape helpButton;
	sf::RectangleShape exitButton;
	sf::RectangleShape guestCheckBox;
	sf::RectangleShape settingsButon;
	sf::RectangleShape leaderboardButton;

	//Text boxes
	sf::RectangleShape nickTextBox;
	bool isNickTextBoxClicked;

	//Text and fonts
	sf::Text MainMenuTitle;
	sf::Text MainMenuNick;
	sf::Text Nick;
	sf::Text playButtonText;
	sf::Text helpButtonText;
	sf::Text exitButtonText;
	sf::Text playAsAGuest;
	sf::Text tick;
	std::string NickStr;
	sf::Vector2i MainMenuTitlePos;
	sf::Font MainMenuFont;

	//Mose Position
	sf::Vector2i mousePosWindow;
public:
	//Public functions
	void updateMainMenuCharSize();
	void draw(sf::RenderWindow*& window);
	void pollEvents(sf::RenderWindow*& window);
	void update(sf::RenderWindow* window);
	GameState returnGameState();
	void setState(GameState sentState);

	//Constructors dectructors
	MainMenu();
	~MainMenu();
};

