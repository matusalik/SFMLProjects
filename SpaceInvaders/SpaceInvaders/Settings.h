#pragma once
#include<iostream>
#include"Panel.h"
#include"GameDifficulty.h"
class Settings : public Panel
{
private:
	//Sprites
	sf::Sprite settingsBackgroundSprite;

	//Textures
	sf::Texture settingsBackgroundTexture;

	//Game State Enum
	GameState state;

	//Game difficulty enum
	GameDifficulty difficulty;

	//Mouse Position
	sf::Vector2i mousePosWindow;

	//Event
	sf::Event ev;

	//Buttons
	sf::RectangleShape easyCheckBox;
	sf::RectangleShape normalCheckBox;
	sf::RectangleShape hardCheckBox;
	sf::RectangleShape exitButton;

	//Texts and fonts
	sf::Text gameDifficultyText;
	sf::Text easyCheckboxText;
	sf::Text normalCheckboxText;
	sf::Text hardCheckboxText;
	sf::Text exitButtonText;
	sf::Text tickEasy;
	sf::Text tickNormal;
	sf::Text tickHard;
	sf::Font settingsFont;

	//Private functions
	void initEnum();
	void initSprites();
	void initTextures();
	void initButtons();
	void initText();
	void initFont();


public:
	void draw(sf::RenderWindow*& window);
	void pollEvents(sf::RenderWindow*& window);
	void update(sf::RenderWindow* window);
	GameState returnGameState();
	virtual GameDifficulty getDifficulty();
	void setState(GameState sentState);
	void updateMousePosWindow(sf::RenderWindow* window);
	Settings();
};

