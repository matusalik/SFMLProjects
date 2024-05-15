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

	//Private Functions
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
	GameState returnGameState();
};

