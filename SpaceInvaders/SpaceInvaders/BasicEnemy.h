#pragma once
#include"Enemy.h"
class BasicEnemy : public Enemy
{
private:
	//Variables
	Direction direction;
	int x;
	int y;

	//Sprite
	sf::Sprite BasicEnemySprite;

	//Teture
	sf::Texture BasicEnemyTexture;
	
	//Private Functions
	void initSprite(const int& x, const int& y);
	void initTexture();
public:
	BasicEnemy(const Direction& direction);
	sf::Sprite getSprite();
	Direction getDirection();
	void move();
};

