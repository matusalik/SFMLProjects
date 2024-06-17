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
	int counter;
	int textureSwitch;

	//Sprite
	sf::Sprite BasicEnemySprite;

	//Teture
	sf::Texture BasicEnemyTexture1;
	sf::Texture BasicEnemyTexture2;
	
	//Private Functions
	void initSprite(const float& x, const float& y);
	void initTexture();
	void initVariables();
public:
	BasicEnemy(const Direction& sentDirection);
	sf::Sprite getSprite();
	Direction getDirection();
	void move();
	bool enemyHit();
};

