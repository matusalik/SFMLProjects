#pragma once
#include"Direction.h"
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<iostream>
class Bullet
{
private:
	//Variables
	Direction direction;
	float x;
	float y;

	//Sprite
	sf::Sprite bulletSprite;

	//Texture
	sf::Texture bulletTexture;

	//Private Functions
	void initSprite(const float& x, const float& y);
	void initTexture();
public:
	Bullet(const Direction& sentDirection);
	sf::Sprite getSprite();
	void move();
};

