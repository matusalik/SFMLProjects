#include "GamePlay.h"
GamePlay::GamePlay(const GameDifficulty& sent) {
	this->difficulty = sent;
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
	this->timer = 0;
	this->shootingBuffer = true;
	switch (this->difficulty) {
	case GameDifficulty::EASY:
		this->maxEnemies = 1;
		std::cout << "easy" << std::endl;
		break;
	case GameDifficulty::NORMAL:
		this->maxEnemies = 2;
		std::cout << "normal" << std::endl;
		break;
	case GameDifficulty::HARD:
		this->maxEnemies = 3;
		std::cout << "hard" << std::endl;
		break;
	}
}
void GamePlay::initEnemies() {
	std::cout << this->maxEnemies<<std::endl;
	for (int i = 0; i < this->maxEnemies; i++) {
		int dir = rand() % 4;
		int enemy = rand() % 2;
		if (dir == 0) {
			if (enemy == 0) {
				std::unique_ptr<Enemy> tempE = std::make_unique<BasicEnemy>(Direction::EAST);
				this->enemiesVector.push_back(std::move(tempE));
			}
			else if (enemy == 1) {
				std::unique_ptr<Enemy> tempE = std::make_unique<FastEnemy>(Direction::EAST);
				this->enemiesVector.push_back(std::move(tempE));
			}
		}
		else if (dir == 1) {
			if (enemy == 0) {
				std::unique_ptr<Enemy> tempE = std::make_unique<BasicEnemy>(Direction::NORTH);
				this->enemiesVector.push_back(std::move(tempE));
			}
			else if (enemy == 1) {
				std::unique_ptr<Enemy> tempE = std::make_unique<FastEnemy>(Direction::NORTH);
				this->enemiesVector.push_back(std::move(tempE));
			}
		}
		else if (dir == 2) {
			if (enemy == 0) {
				std::unique_ptr<Enemy> tempE = std::make_unique<BasicEnemy>(Direction::WEST);
				this->enemiesVector.push_back(std::move(tempE));
			}
			else if (enemy == 1) {
				std::unique_ptr<Enemy> tempE = std::make_unique<FastEnemy>(Direction::WEST);
				this->enemiesVector.push_back(std::move(tempE));
			}
		}
		else if (dir == 3) {
			if (enemy == 0) {
				std::unique_ptr<Enemy> tempE = std::make_unique<BasicEnemy>(Direction::SOUTH);
				this->enemiesVector.push_back(std::move(tempE));
			}
			else if (enemy == 1) {
				std::unique_ptr<Enemy> tempE = std::make_unique<FastEnemy>(Direction::SOUTH);
				this->enemiesVector.push_back(std::move(tempE));
			}
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
		for (const auto& i : this->bulletsVector) {
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
		updateEnemies();
		updateBullets();
		if (!this->shootingBuffer) {
			this->timer++;
			if (this->timer % 25 == 0) {
				this->shootingBuffer = true;
				this->timer = 0;
			}
		}
	}
}
void GamePlay::updateBullets() {
	for (const auto& i : this->bulletsVector) {
		i.get()->move();
	}
}
void GamePlay::updateEnemies() {
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
			it = this->enemiesVector.erase(it);
			this->spawnNewEnemy();
		}
		else {
			++it;
		}
	}
	for (auto& newEnemy : this->newEnemiesVector) {
		this->enemiesVector.push_back(std::move(newEnemy));
	}
	this->newEnemiesVector.clear();
}
void GamePlay::spawnNewEnemy() {
	int dir = rand() % 4;
	int enemy = rand() % 2;
	if (dir == 0) {
		if (enemy == 0) {
			std::unique_ptr<Enemy> tempE = std::make_unique<BasicEnemy>(Direction::EAST);
			this->newEnemiesVector.push_back(std::move(tempE));
		}
		else if (enemy == 1) {
			std::unique_ptr<Enemy> tempE = std::make_unique<FastEnemy>(Direction::EAST);
			this->newEnemiesVector.push_back(std::move(tempE));
		}
	}
	else if (dir == 1) {
		if (enemy == 0) {
			std::unique_ptr<Enemy> tempE = std::make_unique<BasicEnemy>(Direction::NORTH);
			this->newEnemiesVector.push_back(std::move(tempE));
		}
		else if (enemy == 1) {
			std::unique_ptr<Enemy> tempE = std::make_unique<FastEnemy>(Direction::NORTH);
			this->newEnemiesVector.push_back(std::move(tempE));
		}
	}
	else if (dir == 2) {
		if (enemy == 0) {
			std::unique_ptr<Enemy> tempE = std::make_unique<BasicEnemy>(Direction::WEST);
			this->newEnemiesVector.push_back(std::move(tempE));
		}
		else if (enemy == 1) {
			std::unique_ptr<Enemy> tempE = std::make_unique<FastEnemy>(Direction::WEST);
			this->newEnemiesVector.push_back(std::move(tempE));
		}
	}
	else if (dir == 3) {
		if (enemy == 0) {
			std::unique_ptr<Enemy> tempE = std::make_unique<BasicEnemy>(Direction::SOUTH);
			this->newEnemiesVector.push_back(std::move(tempE));
		}
		else if (enemy == 1) {
			std::unique_ptr<Enemy> tempE = std::make_unique<FastEnemy>(Direction::SOUTH);
			this->newEnemiesVector.push_back(std::move(tempE));
		}
	}
}
void GamePlay::pollEvents(sf::RenderWindow*& window) {
	while (window->pollEvent(this->ev)) {
		switch (this->ev.type) {
		case sf::Event::Closed:
			window->close();
			break;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			this->isPaused = !this->isPaused;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->shootingBuffer) {
			std::unique_ptr<Bullet> tempB = std::make_unique<Bullet>(Direction::NORTH);
			this->bulletsVector.push_back(std::move(tempB));
			this->shootingBuffer = false;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && this->shootingBuffer) {
			std::unique_ptr<Bullet> tempB = std::make_unique<Bullet>(Direction::EAST);
			this->bulletsVector.push_back(std::move(tempB));
			this->shootingBuffer = false;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->shootingBuffer) {
			std::unique_ptr<Bullet> tempB = std::make_unique<Bullet>(Direction::SOUTH);
			this->bulletsVector.push_back(std::move(tempB));
			this->shootingBuffer = false;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && this->shootingBuffer) {
			std::unique_ptr<Bullet> tempB = std::make_unique<Bullet>(Direction::WEST);
			this->bulletsVector.push_back(std::move(tempB));
			this->shootingBuffer = false;
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
