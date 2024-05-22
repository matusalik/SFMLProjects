#include "GamePlay.h"
GamePlay::GamePlay() {
	this->initEnum();
	this->initVariables();
	this->initTextures();
	this->initSprites();
	this->initPlayer();
	this->initEnemies();
}
void GamePlay::initPlayer() {
	this->PlayerSprite.setPosition(350.f, 350.f);
}
void GamePlay::initTextures() {
	if (!this->GamePlayBackgroundTexture.loadFromFile("backgrounds/GamePlayBackground.png")) {
		std::cout << "Couldn't load GamePlayBackground!" << std::endl;
	}
	if (!this->PlayerTexture.loadFromFile("sprites/PlayerSprite.png")) {
		std::cout << "Couldn't load PlayerSprite!" << std::endl;
	}
}
void GamePlay::initSprites() {
	this->GamePlayBackgroundSprite.setTexture(this->GamePlayBackgroundTexture);
	this->PlayerSprite.setTexture(this->PlayerTexture);
}
void GamePlay::initEnum() {
	this->state = GameState::GAME_PLAY;
}
void GamePlay::initVariables() {
	this->isPaused = false;
}
void GamePlay::initEnemies() {
	this->enemiesVector.push_back(std::move(e));
}
void GamePlay::draw(sf::RenderWindow*& window) {
	if (!this->isPaused) {
		window->draw(this->GamePlayBackgroundSprite);
		window->draw(this->PlayerSprite);
		for (const auto& i : this->enemiesVector) {
			window->draw(i.get()->getSprite());
		}
	}
	else if (this->isPaused) {
		window->draw(this->GamePlayBackgroundSprite);
	}
}
void GamePlay::update(sf::RenderWindow* window) {
	this->updateMousePosWindow(window);
	if (!this->isPaused) {

	}
}
void GamePlay::pollEvents(sf::RenderWindow*& window) {
	while (window->pollEvent(this->ev)) {
		switch (this->ev.type) {
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			switch (this->ev.key.code) {
			case sf::Keyboard::Escape:
				this->isPaused = !this->isPaused;
				break;
			}
		}
	}
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
