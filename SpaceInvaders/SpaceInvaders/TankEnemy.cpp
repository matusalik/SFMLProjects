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

}
void TankEnemy::initTexture() {
	switch (this->direction) {
	case Direction::NORTH:
		if (!this->TankEnemyTexture.loadFromFile("sprites/TankEnemySprite.png")) {
			std::cout << "Couldn't load TankEnemyTexture!" << std::endl;
		}
		break;
	case Direction::EAST:
		if (!this->TankEnemyTexture.loadFromFile("sprites/TankEnemySprite.png")) {
			std::cout << "Couldn't load TankEnemyTexture!" << std::endl;
		}
		break;
	case Direction::SOUTH:
		if (!this->TankEnemyTexture.loadFromFile("sprites/TankEnemySprite.png")) {
			std::cout << "Couldn't load TankEnemyTexture!" << std::endl;
		}
		break;
	case Direction::WEST:
		if (!this->TankEnemyTexture.loadFromFile("sprites/TankEnemySprite.png")) {
			std::cout << "Couldn't load TankEnemyTexture!" << std::endl;
		}
		break;
	}
}
void TankEnemy::initSprite(const float& x, const float& y) {
	this->TankEnemySprite.setTexture(this->TankEnemyTexture);
	this->TankEnemySprite.setPosition(x, y);
}
void TankEnemy::initVariables() {
	this->health = 2;
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
	this->TankEnemySprite.setPosition(this->x, this->y);
}
sf::Sprite TankEnemy::getSprite() {
	return this->TankEnemySprite;
}
Direction TankEnemy::getDirection() {
	return this->direction;
}