#include "LeaderboardPanel.h"

LeaderboardPanel::LeaderboardPanel() {
	this->initEnum();
}
void LeaderboardPanel::initEnum() {
	this->state = GameState::LEADERBOARD;
}
void LeaderboardPanel::initButtons(){

}
void LeaderboardPanel::initText() {

}
void LeaderboardPanel::initFont() {

}
void LeaderboardPanel::draw(sf::RenderWindow*& window) {

}
void LeaderboardPanel::pollEvents(sf::RenderWindow*& window) {
	while (window->pollEvent(this->ev)) {
		switch (this->ev.type) {
		case sf::Event::Closed:
			window->close();
			break;
		}
	}
}
void LeaderboardPanel::update(sf::RenderWindow* window) {

}
GameState LeaderboardPanel::returnGameState() {
	return this->state;
}
void LeaderboardPanel::setState(GameState sentState) {

}
void LeaderboardPanel::updateMousePosWindow(sf::RenderWindow* window) {
	this->mousePosWindow = sf::Mouse::getPosition(*window);
}
