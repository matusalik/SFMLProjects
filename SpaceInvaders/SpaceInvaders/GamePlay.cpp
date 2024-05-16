#include "GamePlay.h"
GamePlay::GamePlay() {

}
void GamePlay::draw(sf::RenderWindow*& window) {

}
void GamePlay::update(sf::RenderWindow* window) {

}
void GamePlay::pollEvents(sf::RenderWindow*& window) {

}
GameState GamePlay::returnGameState() {
	return this->state;
}
void GamePlay::setState(GameState sentState) {
	this->state = sentState;
}
void GamePlay::updateMousePosWindow(sf::RenderWindow* window) {
	this->mousePosWindow = sf::Mouse::getPosition(*window);
}
