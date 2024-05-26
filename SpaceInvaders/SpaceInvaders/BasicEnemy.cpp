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
	
}
void BasicEnemy::initTexture() {
	switch (this->direction) {
	case Direction::NORTH:
		if (!this->BasicEnemyTexture.loadFromFile("sprites/BasicEnemySprite.png")) {
			std::cout << "Couldn't load BasicEnemyTexture!" << std::endl;
		}
		break;
	case Direction::EAST:
		if (!this->BasicEnemyTexture.loadFromFile("sprites/BasicEnemySprite.png")) {
			std::cout << "Couldn't load BasicEnemyTexture!" << std::endl;
		}
		break;
	case Direction::SOUTH:
		if (!this->BasicEnemyTexture.loadFromFile("sprites/BasicEnemySprite.png")) {
			std::cout << "Couldn't load BasicEnemyTexture!" << std::endl;
		}
		break;
	case Direction::WEST:
		if (!this->BasicEnemyTexture.loadFromFile("sprites/BasicEnemySprite.png")) {
			std::cout << "Couldn't load BasicEnemyTexture!" << std::endl;
		}
		break;
	}
}
void BasicEnemy::initSprite(const float& x, const float& y) {
	this->BasicEnemySprite.setTexture(this->BasicEnemyTexture);
	this->BasicEnemySprite.setPosition(x, y);
}
void BasicEnemy::initVariables() {
	this->health = 1;
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
}
sf::Sprite BasicEnemy::getSprite() {
	return this->BasicEnemySprite;
}
Direction BasicEnemy::getDirection() {
	return this->direction;
}