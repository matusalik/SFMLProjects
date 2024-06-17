#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<iostream>
#include"Direction.h"
class Enemy 
{
public:
	virtual sf::Sprite getSprite() = 0;
	virtual Direction getDirection() = 0;
	virtual void move() = 0;
	virtual bool enemyHit() = 0;
};

