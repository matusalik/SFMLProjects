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
	switch (this->difficulty) {
	case GameDifficulty::EASY:
		this->maxEnemies = 3;
		break;
	case GameDifficulty::NORMAL:
		this->maxEnemies = 5;
		break;
	case GameDifficulty::HARD:
		this->maxEnemies = 7;
		break;
	}
}
void GamePlay::initEnemies() {
	std::cout << this->maxEnemies<<std::endl;
	for (int i = 0; i < this->maxEnemies; i++) {
		int temp = rand() % 4;
		if (temp == 0) {
			std::unique_ptr<Enemy> tempE = std::make_unique<BasicEnemy>(Direction::EAST);
			this->enemiesVector.push_back(std::move(tempE));
		}
		else if (temp == 1) {
			std::unique_ptr<Enemy> tempE = std::make_unique<BasicEnemy>(Direction::NORTH);
			this->enemiesVector.push_back(std::move(tempE));
		}
		else if (temp == 2) {
			std::unique_ptr<Enemy> tempE = std::make_unique<BasicEnemy>(Direction::WEST);
			this->enemiesVector.push_back(std::move(tempE));
		}
		else if (temp == 3) {
			std::unique_ptr<Enemy> tempE = std::make_unique<BasicEnemy>(Direction::SOUTH);
			this->enemiesVector.push_back(std::move(tempE));
		}
	}
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
		for (const auto& i : this->enemiesVector) {
			window->draw(i.get()->getSprite());
		}
	}
}
void GamePlay::update(sf::RenderWindow* window) {
	this->updateMousePosWindow(window);
	if (!this->isPaused) {
		for (auto it = this->enemiesVector.begin(); it != this->enemiesVector.end(); ) {
			(*it)->move();
			bool shouldDelete = false;
			switch ((*it)->getDirection()) {
			case Direction::NORTH:
				if ((*it)->getSprite().getPosition().y + 70 >= this->PlayerSprite.getPosition().y) {
					shouldDelete = true;
				}
				break;
			case Direction::EAST:
				if ((*it)->getSprite().getPosition().x <= this->PlayerSprite.getPosition().x + 100) {
					shouldDelete = true;
				}
				break;
			case Direction::SOUTH:
				if ((*it)->getSprite().getPosition().y <= this->PlayerSprite.getPosition().y + 100) {
					shouldDelete = true;
				}
				break;
			case Direction::WEST:
				if ((*it)->getSprite().getPosition().x + 70 >= this->PlayerSprite.getPosition().x) {
					shouldDelete = true;
				}
				break;
			}
			if (shouldDelete) {
				std::cout << "Deleting enemy\n";
				it = this->enemiesVector.erase(it);
				std::cout << this->enemiesVector.size() << std::endl;
				this->spawnNewEnemy();
			}
			else {
				++it;
			}
		}
	}
}
void GamePlay::spawnNewEnemy() {
	int temp = rand() % 4;
	if (temp == 0) {
		std::unique_ptr<Enemy> tempE = std::make_unique<BasicEnemy>(Direction::EAST);
		this->enemiesVector.push_back(std::move(tempE));
	}
	else if (temp == 1) {
		std::unique_ptr<Enemy> tempE = std::make_unique<BasicEnemy>(Direction::NORTH);
		this->enemiesVector.push_back(std::move(tempE));
	}
	else if (temp == 2) {
		std::unique_ptr<Enemy> tempE = std::make_unique<BasicEnemy>(Direction::WEST);
		this->enemiesVector.push_back(std::move(tempE));
	}
	else if (temp == 3) {
		std::unique_ptr<Enemy> tempE = std::make_unique<BasicEnemy>(Direction::SOUTH);
		this->enemiesVector.push_back(std::move(tempE));
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
void GamePlay::setDifficulty(GameDifficulty sent) {
	this->difficulty = sent;
}
