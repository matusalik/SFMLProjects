#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include"Panel.h"
class HelpPanel : public Panel
{
private:
	//Variables
	std::string helpString;

	//Sprite
	sf::Sprite helpPanelBackgroundSprite;

	//Textures
	sf::Texture helpPanelBackgroundTexture;

	//Fonts
	sf::Font helpPanelFont;

	//Events
	sf::Event ev;

	//Game State Enum
	GameState state;

	//Buttons
	sf::RectangleShape exitButton;

	//Text
	sf::Text exitText;
	sf::Text helpText;

	//Private Functions
	void initVariables();
	void initEnum();
	void initTextures();
	void initSprites();
	void initButtons();
	void initText();
	void initFonts();
	void updateMousePosWindow(sf::RenderWindow* window);

	//Mose Position
	sf::Vector2i mousePosWindow;


public:
	HelpPanel();
	~HelpPanel();
	void draw(sf::RenderWindow*& window);
	void update(sf::RenderWindow* window);
	void pollEvents(sf::RenderWindow*& window);
	void setState(GameState sentState);
	GameState returnGameState();
};

