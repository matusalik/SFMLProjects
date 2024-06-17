#pragma once
#include"Enemy.h"
class FastEnemy : public Enemy
{
private:
	//Variables
	Direction direction;
	float x;
	float y;
	int health;
	int counter;
	int textureSwitch;

	//Sprite
	sf::Sprite FastEnemySprite;

	//Teture
	sf::Texture FastEnemyTexture1;
	sf::Texture FastEnemyTexture2;

	//Private Functions
	void initSprite(const float& x, const float& y);
	void initTexture();
	void initVariables();
public:
	FastEnemy(const Direction& sentDirection);
	sf::Sprite getSprite();
	Direction getDirection();
	void move();
	bool enemyHit();
};

