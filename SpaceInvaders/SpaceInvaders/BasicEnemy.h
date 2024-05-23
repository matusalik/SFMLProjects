#pragma once
#include"Enemy.h"
class BasicEnemy : public Enemy
{
private:
	//Variables
	Direction direction;
	float x;
	float y;
	int health;

	//Sprite
	sf::Sprite BasicEnemySprite;

	//Teture
	sf::Texture BasicEnemyTexture;
	
	//Private Functions
	void initSprite(const float& x, const float& y);
	void initTexture();
public:
	BasicEnemy(const Direction& sentDirection);
	sf::Sprite getSprite();
	Direction getDirection();
	void move();
};

