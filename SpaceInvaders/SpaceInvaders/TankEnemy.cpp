#include "TankEnemy.h"
TankEnemy::TankEnemy(const Direction& sentDirection) {
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
void TankEnemy::initTexture() {
	if (!this->TankEnemyTexture1.loadFromFile("sprites/TankEnemySprite1.png")) {
		std::cout << "Couldn't load TankEnemyTexture!" << std::endl;
	}
	if (!this->TankEnemyTexture2.loadFromFile("sprites/TankEnemySprite2.png")) {
		std::cout << "Couldn't load TankEnemyTexture!" << std::endl;
	}
}
void TankEnemy::initSprite(const float& x, const float& y) {
	this->TankEnemySprite.setTexture(this->TankEnemyTexture1);
	this->TankEnemySprite.setPosition(x, y);
}
void TankEnemy::initVariables() {
	this->health = 2;
	this->counter = 0;
	this->textureSwitch = false;
}
void TankEnemy::move() {
	switch (this->direction) {
	case Direction::NORTH:
		this->y = y + 1.5;
		break;
	case Direction::EAST:
		this->x = x - 1.5;
		break;
	case Direction::SOUTH:
		this->y = y - 1.5;
		break;
	case Direction::WEST:
		this->x = x + 1.5;
		break;
	}
	this->counter++;
	this->TankEnemySprite.setPosition(this->x, this->y);
	if (this->counter % 15 == 0) {
		if (this->textureSwitch) {
			this->TankEnemySprite.setTexture(this->TankEnemyTexture1);
			this->textureSwitch = false;
		}
		else {
			this->TankEnemySprite.setTexture(this->TankEnemyTexture2);
			this->textureSwitch = true;
		}
	}
}
sf::Sprite TankEnemy::getSprite() {
	return this->TankEnemySprite;
}
Direction TankEnemy::getDirection() {
	return this->direction;
}
bool TankEnemy::enemyHit() {
	this->health--;
	if (this->health == 0) {
		return true;
	}
	else {
		return false;
	}
}
