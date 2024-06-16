#pragma once
#include"Enemy.h"
class TankEnemy : public Enemy
{
private:
	//Variables
	Direction direction;
	float x;
	float y;
	int health;
	int counter;
	bool textureSwitch;

	//Sprite
	sf::Sprite TankEnemySprite;

	//Teture
	sf::Texture TankEnemyTexture1;
	sf::Texture TankEnemyTexture2;

	//Private Functions
	void initSprite(const float& x, const float& y);
	void initTexture();
	void initVariables();
public:
	TankEnemy(const Direction& sentDirection);
	sf::Sprite getSprite();
	Direction getDirection();
	void setSprite();
	void move();
	bool enemyHit();
};

