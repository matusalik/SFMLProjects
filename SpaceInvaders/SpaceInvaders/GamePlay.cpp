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
		int enemy = rand() % 3;
		if (dir == 0) {
			if (enemy == 0) {
				std::unique_ptr<Enemy> tempE = std::make_unique<BasicEnemy>(Direction::EAST);
				this->enemiesVector.push_back(std::move(tempE));
			}
			else if (enemy == 1) {
				std::unique_ptr<Enemy> tempE = std::make_unique<FastEnemy>(Direction::EAST);
				this->enemiesVector.push_back(std::move(tempE));
			}
			else if (enemy == 2) {
				std::unique_ptr<Enemy> tempE = std::make_unique<TankEnemy>(Direction::EAST);
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
			else if (enemy == 2) {
				std::unique_ptr<Enemy> tempE = std::make_unique<TankEnemy>(Direction::NORTH);
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
			else if (enemy == 2) {
				std::unique_ptr<Enemy> tempE = std::make_unique<TankEnemy>(Direction::WEST);
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
			else if (enemy == 2) {
				std::unique_ptr<Enemy> tempE = std::make_unique<TankEnemy>(Direction::SOUTH);
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
		for (const auto& i : this->bulletsVector) {
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
			if (this->timer % 15 == 0) {
				this->shootingBuffer = true;
				this->timer = 0;
			}
		}
	}
}
void GamePlay::updateBullets() {
	for (auto it = this->bulletsVector.begin(); it != this->bulletsVector.end(); ) {
		(*it)->move();
		bool shouldDelete = false;
		switch ((*it)->getDirection()) {
		case Direction::NORTH:
			if ((*it)->getSprite().getPosition().y <= 0) {
				shouldDelete = true;
			}
			for (auto ite = this->enemiesVector.begin(); ite != this->enemiesVector.end(); ) {
				bool shouldDeleteEnemy = false;
				if ((*ite)->getDirection() == Direction::NORTH) {
					if ((*ite)->getSprite().getPosition().y + 70 >= (*it)->getSprite().getPosition().y) {
						shouldDelete = true;
						shouldDeleteEnemy = true;
					}
				}
				if (shouldDeleteEnemy) {
					ite = this->enemiesVector.erase(ite);
					this->spawnNewEnemy();
				}
				else {
					++ite;
				}
			}
			break;
		case Direction::EAST:
			if ((*it)->getSprite().getPosition().x >= 800) {
				shouldDelete = true;
			}
			for (auto ite = this->enemiesVector.begin(); ite != this->enemiesVector.end(); ) {
				bool shouldDeleteEnemy = false;
				if ((*ite)->getDirection() == Direction::EAST) {
					if ((*ite)->getSprite().getPosition().x <= (*it)->getSprite().getPosition().x + 20) {
						shouldDelete = true;
						shouldDeleteEnemy = true;
					}
				}
				if (shouldDeleteEnemy) {
					ite = this->enemiesVector.erase(ite);
					this->spawnNewEnemy();
				}
				else {
					++ite;
				}
			}
			break;
		case Direction::SOUTH:
			if ((*it)->getSprite().getPosition().y >= 800) {
				shouldDelete = true;
			}
			for (auto ite = this->enemiesVector.begin(); ite != this->enemiesVector.end(); ) {
				bool shouldDeleteEnemy = false;
				if ((*ite)->getDirection() == Direction::SOUTH) {
					if ((*ite)->getSprite().getPosition().y <= (*it)->getSprite().getPosition().y + 20) {
						shouldDelete = true;
						shouldDeleteEnemy = true;
					}
				}
				if (shouldDeleteEnemy) {
					ite = this->enemiesVector.erase(ite);
					this->spawnNewEnemy();
				}
				else {
					++ite;
				}
			}
			break;
		case Direction::WEST:
			if ((*it)->getSprite().getPosition().x <= 0) {
				shouldDelete = true;
			}
			for (auto ite = this->enemiesVector.begin(); ite != this->enemiesVector.end(); ) {
				bool shouldDeleteEnemy = false;
				if ((*ite)->getDirection() == Direction::WEST) {
					if ((*ite)->getSprite().getPosition().x + 70 >= (*it)->getSprite().getPosition().x) {
						shouldDelete = true;
						shouldDeleteEnemy = true;
					}
				}
				if (shouldDeleteEnemy) {
					ite = this->enemiesVector.erase(ite);
					this->spawnNewEnemy();
				}
				else {
					++ite;
				}
			}
			break;
		}
		if (shouldDelete) {
			it = this->bulletsVector.erase(it);
		}
		else {
			++it;
		}
		std::cout << this->bulletsVector.size() << std::endl;
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
	int enemy = rand() % 3;
	if (dir == 0) {
		if (enemy == 0) {
			std::unique_ptr<Enemy> tempE = std::make_unique<BasicEnemy>(Direction::EAST);
			this->newEnemiesVector.push_back(std::move(tempE));
		}
		else if (enemy == 1) {
			std::unique_ptr<Enemy> tempE = std::make_unique<FastEnemy>(Direction::EAST);
			this->newEnemiesVector.push_back(std::move(tempE));
		}
		else if (enemy == 2) {
			std::unique_ptr<Enemy> tempE = std::make_unique<TankEnemy>(Direction::EAST);
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
		else if (enemy == 2) {
			std::unique_ptr<Enemy> tempE = std::make_unique<TankEnemy>(Direction::NORTH);
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
		else if (enemy == 2) {
			std::unique_ptr<Enemy> tempE = std::make_unique<TankEnemy>(Direction::WEST);
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
		else if (enemy == 2) {
			std::unique_ptr<Enemy> tempE = std::make_unique<TankEnemy>(Direction::SOUTH);
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
		case sf::Event::KeyPressed:
			switch (this->ev.key.code) {
			case sf::Keyboard::Escape:
				this->isPaused = !this->isPaused;
				break;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->shootingBuffer && !isPaused) {
			std::unique_ptr<Bullet> tempB = std::make_unique<Bullet>(Direction::NORTH);
			this->bulletsVector.push_back(std::move(tempB));
			this->shootingBuffer = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && this->shootingBuffer && !isPaused) {
			std::unique_ptr<Bullet> tempB = std::make_unique<Bullet>(Direction::EAST);
			this->bulletsVector.push_back(std::move(tempB));
			this->shootingBuffer = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->shootingBuffer && !isPaused) {
			std::unique_ptr<Bullet> tempB = std::make_unique<Bullet>(Direction::SOUTH);
			this->bulletsVector.push_back(std::move(tempB));
			this->shootingBuffer = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && this->shootingBuffer && !isPaused){
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