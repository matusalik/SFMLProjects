#include "BasicEnemy.h"
BasicEnemy::BasicEnemy(const Direction& sentDirection) {
	switch (sentDirection) {
	case Direction::NORTH:
		this->x = 365.f;
		this->y = 0.f;
		std::cout << "North" << std::endl;
		break;
	case Direction::EAST:
		this->x = 730.f;
		this->y = 365.f;
		std::cout << "east" << std::endl;
		break;
	case Direction::SOUTH:
		this->x = 365.f;
		this->y = 730.f;
		std::cout << "south" << std::endl;
		break;
	case Direction::WEST:
		this->x = 0.f;
		this->y = 365.f;
		std::cout << "west" << std::endl;
		break;
	}
	this->direction = sentDirection;
	this->initTexture();
	this->initSprite(this->x, this->y);
	this->initVariables();
}
void BasicEnemy::initTexture() {
	if (!this->BasicEnemyTexture1.loadFromFile("sprites/BasicEnemySprite1.png")) {
		std::cout << "Couldn't load BasicEnemyTexture!" << std::endl;
	}
	if (!this->BasicEnemyTexture2.loadFromFile("sprites/BasicEnemySprite2.png")) {
		std::cout << "Couldn't load BasicEnemyTexture!" << std::endl;
	}
}
void BasicEnemy::initSprite(const float& x, const float& y) {
	this->BasicEnemySprite.setTexture(this->BasicEnemyTexture1);
	this->BasicEnemySprite.setPosition(x, y);
}
void BasicEnemy::initVariables() {
	this->health = 1;
	this->counter = 0;
	this->textureSwitch = false;
}
void BasicEnemy::move() {
	switch (this->direction) {
	case Direction::NORTH:
		this->y = y + 2;
		break;
	case Direction::EAST:
		this->x = x - 2;
		break;
	case Direction::SOUTH:
		this->y = y - 2;
		break;
	case Direction::WEST:
		this->x = x + 2;
		break;
	}
	this->BasicEnemySprite.setPosition(this->x, this->y);
	this->counter++;
	this->BasicEnemySprite.setPosition(this->x, this->y);
	if (this->counter % 15 == 0) {
		if (this->textureSwitch) {
			this->BasicEnemySprite.setTexture(this->BasicEnemyTexture1);
			this->textureSwitch = false;
		}
		else {
			this->BasicEnemySprite.setTexture(this->BasicEnemyTexture2);
			this->textureSwitch = true;
		}
	}
}
sf::Sprite BasicEnemy::getSprite() {
	return this->BasicEnemySprite;
}
Direction BasicEnemy::getDirection() {
	return this->direction;
}
bool BasicEnemy::enemyHit() {
	this->health--;
	std::cout << "HEALTH: " << this->health << std::endl;
	if (this->health == 0) {
		return true;
	}
	else {
		return false;
	}
}