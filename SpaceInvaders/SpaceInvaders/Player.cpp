#include "Player.h"
Player::Player() {
	this->score = 0;
}
std::string Player::getNick() {
	return this->nick;
}
int Player::getScore() {
	return this->score;
}
void Player::setNick(std::string sentNick) {
	this->nick = sentNick;
}
void Player::setScore(int sentScore) {
	this->score = sentScore;
}