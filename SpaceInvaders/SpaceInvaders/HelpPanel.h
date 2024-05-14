#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
class HelpPanel
{
private:
	//Buttons
	sf::RectangleShape button1;

	//Private Functions
	void initButtons();

	//Variables
	int a = 3;
public:
	HelpPanel();
	~HelpPanel();
	void draw(sf::RenderWindow*& window);
	void update();
};

