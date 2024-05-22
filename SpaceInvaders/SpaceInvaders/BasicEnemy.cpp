#include "BasicEnemy.h"
BasicEnemy::BasicEnemy(const Direction& direction, const int& x, const int& y) {
	this->x = x;
	this->y = y;
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
void BasicEnemy::setPos(const int& x, const int& y) {
	this->BasicEnemySprite.setPosition(x, y);
}
sf::Sprite BasicEnemy::getSprite() {
	return this->BasicEnemySprite;
}
Direction BasicEnemy::getDirection() {
	return this->direction;
}