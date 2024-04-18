#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

/*
	Class that acts as the game engine
	Wrapper Class
*/
class Game
{
private:
	//Variables
	

	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Game objects
	sf::RectangleShape enemy;
	sf::RectangleShape button;
	sf::Text text;
	sf::Font font;

	//Private functions
	void initVariables();
	void initWindow();
	void initEnemies();
	void initButton();
	void initText();
	void initFont();
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

