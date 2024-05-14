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
	//Events
	sf::Event ev;
	
	//Game State Enum
	GameState state;

	//Buttons
	sf::RectangleShape button1;

	//Private Functions
	void initButtons();

	//Variables
	

public:
	HelpPanel();
	~HelpPanel();
	void draw(sf::RenderWindow*& window);
	void update(sf::RenderWindow* window);
	void pollEvents(sf::RenderWindow*& window);
	GameState returnGameState();
};

