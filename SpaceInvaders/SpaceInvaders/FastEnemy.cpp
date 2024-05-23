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

}
void FastEnemy::initTexture() {
	switch (this->direction) {
	case Direction::NORTH:
		if (!this->FastEnemyTexture.loadFromFile("sprites/FastEnemySprite.png")) {
			std::cout << "Couldn't load FastEnemyTexture!" << std::endl;
		}
		break;
	case Direction::EAST:
		if (!this->FastEnemyTexture.loadFromFile("sprites/FastEnemySprite.png")) {
			std::cout << "Couldn't load FastEnemyTexture!" << std::endl;
		}
		break;
	case Direction::SOUTH:
		if (!this->FastEnemyTexture.loadFromFile("sprites/FastEnemySprite.png")) {
			std::cout << "Couldn't load FastEnemyTexture!" << std::endl;
		}
		break;
	case Direction::WEST:
		if (!this->FastEnemyTexture.loadFromFile("sprites/FastEnemySprite.png")) {
			std::cout << "Couldn't load FastEnemyTexture!" << std::endl;
		}
		break;
	}
}
void FastEnemy::initSprite(const float& x, const float& y) {
	this->FastEnemySprite.setTexture(this->FastEnemyTexture);
	this->FastEnemySprite.setPosition(x, y);
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
}
sf::Sprite FastEnemy::getSprite() {
	return this->FastEnemySprite;
}
Direction FastEnemy::getDirection() {
	return this->direction;
}