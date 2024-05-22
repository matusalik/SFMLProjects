#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<iostream>
#include"Direction.h"
class Enemy 
{
public:
	virtual void setPos(const int& x, const int& y) = 0;
	virtual sf::Sprite getSprite() = 0;
	virtual Direction getDirection() = 0;
};

