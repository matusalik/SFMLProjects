#include "Bullet.h"
Bullet::Bullet(const Direction& sentDirection) {
	switch (sentDirection) {
	case Direction::NORTH:
		this->x = 395;
		this->y = 330;
		break;
	case Direction::EAST:
		this->x = 450;
		this->y = 395;
		break;
	case Direction::SOUTH:
		this->x = 395;
		this->y = 450;
		break;
	case Direction::WEST:
		this->x = 330;
		this->y = 395;
	}
	this->direction = sentDirection;
	this->initTexture();
	this->initSprite(this->x, this->y);
}
void Bullet::initTexture() {
	if (this->direction == Direction::NORTH || this->direction == Direction::SOUTH) {
		if (!this->bulletTexture.loadFromFile("sprites/bulletSpriteVert.png")) {
			std::cout << "Couldn't load bulletVertTexture!" << std::endl;
		} 
	}
	else if (this->direction == Direction::WEST || this->direction == Direction::EAST) {
		if (!this->bulletTexture.loadFromFile("sprites/bulletSpriteHor.png")) {
			std::cout << "Couldn't load bulletHorTexture!" << std::endl;
		}
	}
}
void Bullet::initSprite(const float& x, const float& y) {
	//this->bulletSprite.setColor(sf::Color::Green);
	this->bulletSprite.setTexture(this->bulletTexture);
	this->bulletSprite.setPosition(x, y);
}
sf::Sprite Bullet::getSprite() {
	return this->bulletSprite;
}
void Bullet::move() {
	switch (this->direction) {
	case Direction::NORTH:
		this->y = y - 2;
		break;
	case Direction::EAST:
		this->x = x + 2;
		break;
	case Direction::SOUTH:
		this->y = y + 2;
		break;
	case Direction::WEST:
		this->x = x - 2;
		break;
	}
	this->bulletSprite.setPosition(this->x, this->y);
}