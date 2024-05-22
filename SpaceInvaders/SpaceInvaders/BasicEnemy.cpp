#include "BasicEnemy.h"
BasicEnemy::BasicEnemy(const Direction& direction) {
	switch (direction) {
	case Direction::NORTH:
		this->x = 365.f;
		this->y = 0.f;
		break;
	case Direction::EAST:
		this->x = 730.f;
		this->y = 365.f;
		break;
	case Direction::SOUTH:
		this->x = 365;
		this->y = 730;
		break;
	case Direction::WEST:
		this->x = 0.f;
		this->y = 365.f;
		break;
	}
	this->direction = direction;
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
void BasicEnemy::initSprite(const int& x, const int& y) {
	this->BasicEnemySprite.setTexture(this->BasicEnemyTexture);
	this->BasicEnemySprite.setPosition(x, y);
}
void BasicEnemy::move() {
	switch (this->direction) {
	case Direction::NORTH:
		this->y = y + 5.f;
		break;
	case Direction::EAST:
		this->x = x - 5.f;
		break;
	case Direction::SOUTH:
		this->y = y - 5;;
		break;
	case Direction::WEST:
		this->x = x + 5.f;
		break;
	}
}
sf::Sprite BasicEnemy::getSprite() {
	return this->BasicEnemySprite;
}
Direction BasicEnemy::getDirection() {
	return this->direction;
}