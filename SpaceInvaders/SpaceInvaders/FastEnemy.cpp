#include "FastEnemy.h"
FastEnemy::FastEnemy(const Direction& sentDirection) {
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
void FastEnemy::initTexture() {
	if (!this->FastEnemyTexture1.loadFromFile("sprites/FastEnemySprite1.png")) {
		std::cout << "Couldn't load FastEnemyTexture!" << std::endl;
	}
	if (!this->FastEnemyTexture2.loadFromFile("sprites/FastEnemySprite2.png")) {
		std::cout << "Couldn't load FastEnemyTexture!" << std::endl;
	}
}
void FastEnemy::initSprite(const float& x, const float& y) {
	this->FastEnemySprite.setTexture(this->FastEnemyTexture1);
	this->FastEnemySprite.setPosition(x, y);
}
void FastEnemy::initVariables() {
	this->health = 1;
	this->textureSwitch = false;
	this->counter = 0;
}
void FastEnemy::move() {
	switch (this->direction) {
	case Direction::NORTH:
		this->y = y + 2.5;
		break;
	case Direction::EAST:
		this->x = x - 2.5;
		break;
	case Direction::SOUTH:
		this->y = y - 2.5;
		break;
	case Direction::WEST:
		this->x = x + 2.5;
		break;
	}
	this->FastEnemySprite.setPosition(this->x, this->y);
	this->counter++;
	this->FastEnemySprite.setPosition(this->x, this->y);
	if (this->counter % 15 == 0) {
		if (this->textureSwitch) {
			this->FastEnemySprite.setTexture(this->FastEnemyTexture1);
			this->textureSwitch = false;
		}
		else {
			this->FastEnemySprite.setTexture(this->FastEnemyTexture2);
			this->textureSwitch = true;
		}
	}
}
sf::Sprite FastEnemy::getSprite() {
	return this->FastEnemySprite;
}
Direction FastEnemy::getDirection() {
	return this->direction;
}
bool FastEnemy::enemyHit() {
	this->health--;
	if (this->health == 0) {
		return true;
	}
	else {
		return false;
	}
}