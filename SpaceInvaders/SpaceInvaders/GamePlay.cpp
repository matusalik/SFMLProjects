#include "GamePlay.h"
GamePlay::GamePlay(const GameDifficulty& sent, const Player& sentPlayer) {
	this->difficulty = sent;
	this->player = sentPlayer;
	this->initEnum();
	this->initVariables();
	this->initFont();
	this->initTextures();
	this->initText();
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
	if (!this->PlayerTextureNorth.loadFromFile("sprites/PlayerSpriteNorth.png")) {
		std::cout << "Couldn't load PlayerSprite!" << std::endl;
	}
	if (!this->PlayerTextureEast.loadFromFile("sprites/PlayerSpriteEast.png")) {
		std::cout << "Couldn't load PlayerSprite!" << std::endl;
	}
	if (!this->PlayerTextureSouth.loadFromFile("sprites/PlayerSpriteSouth.png")) {
		std::cout << "Couldn't load PlayerSprite!" << std::endl;
	}
	if (!this->PlayerTextureWest.loadFromFile("sprites/PlayerSpriteWest.png")) {
		std::cout << "Couldn't load PlayerSprite!" << std::endl;
	}
}
void GamePlay::initSprites() {
	this->GamePlayBackgroundSprite.setTexture(this->GamePlayBackgroundTexture);
	this->PlayerSprite.setTexture(this->PlayerTextureNorth);
}
void GamePlay::initEnum() {
	this->state = GameState::GAME_PLAY;
}
void GamePlay::initVariables() {
	this->isPaused = false;
	this->timer = 0;
	this->shootingBuffer = true;
	this->isGameOver = false;
	this->clearVectors = false;
	this->isHighScore = false;
	this->score = 0;
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
void GamePlay::initText() {
	this->scoreText.setFont(this->gamePlayFont);
	this->scoreText.setString(std::to_string(this->score));
	this->scoreText.setFillColor(sf::Color(100, 255, 43));
	this->scoreText.setOutlineColor(sf::Color::Black);
	this->scoreText.setOutlineThickness(3.f);
	this->scoreText.setPosition(10.f, 10.f);
}
void GamePlay::initFont() {
	if (!this->gamePlayFont.loadFromFile("fonts/PressStart2P-vaV7.ttf")) {
		std::cout << "Couldn't load the font" << std::endl;
	}
}
void GamePlay::draw(sf::RenderWindow*& window) {
	if (!isGameOver) {
		if (!this->isPaused) {
			window->draw(this->GamePlayBackgroundSprite);
			window->draw(this->PlayerSprite);
			window->draw(this->scoreText);
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
	if (this->isGameOver) {
		if (this->clearVectors) {
			this->enemiesVector.clear();
			this->bulletsVector.clear();
			this->clearVectors = false;
		}
		window->draw(this->GamePlayBackgroundSprite);
		this->drawGameOverPanel(window);
	}
}
void GamePlay::drawGameOverPanel(sf::RenderWindow*& window) {
	sf::RectangleShape panel(sf::Vector2f(500.f, 500.f));
	panel.setFillColor(sf::Color(163, 161, 152));
	panel.setOutlineColor(sf::Color::Black);
	panel.setOutlineThickness(10.f);
	panel.setPosition(sf::Vector2f(140.f, 140.f));
	sf::Text gameOver("GAME OVER", this->gamePlayFont, 50U);
	gameOver.setPosition(sf::Vector2f(160.f, 160.f));
	gameOver.setFillColor(sf::Color(100, 255, 43));
	gameOver.setOutlineColor(sf::Color::Black);
	gameOver.setOutlineThickness(5.f);
	sf::Text nickText;
	nickText.setFont(this->gamePlayFont);
	nickText.setString("NICK: ");
	nickText.setPosition(sf::Vector2f(160.f, 250.f));
	nickText.setFillColor(sf::Color::Black);
	sf::Text nick;
	nick.setFont(this->gamePlayFont);
	nick.setString(this->player.getNick());
	nick.setPosition(sf::Vector2f(310.f, 245.f));
	nick.setFillColor(sf::Color::Black);
	sf::Text scoreText;
	scoreText.setFont(this->gamePlayFont);
	scoreText.setString("SCORE: ");
	scoreText.setPosition(sf::Vector2f(160.f, 305.f));
	scoreText.setFillColor(sf::Color::Black);
	sf::Text score;
	score.setFont(this->gamePlayFont);
	score.setString(std::to_string(this->score));
	score.setPosition(sf::Vector2f(335.f, 305.f));
	score.setFillColor(sf::Color::Black);
	sf::Text highScoreText;
	highScoreText.setFont(this->gamePlayFont);
	highScoreText.setString("HIGHSCORE: ");
	highScoreText.setPosition(sf::Vector2f(160.f, 360.f));
	highScoreText.setFillColor(sf::Color::Black);
	sf::Text highScore;
	highScore.setFont(this->gamePlayFont);
	highScore.setString(std::to_string(this->player.getScore()));
	highScore.setPosition(sf::Vector2f(450.f, 360.f));
	highScore.setFillColor(sf::Color::Black);
	sf::RectangleShape exit(sf::Vector2f(200.f, 80.f));
	exit.setPosition(sf::Vector2f(160.f, 540.f));
	exit.setFillColor(sf::Color(140, 140, 140));
	exit.setOutlineColor(sf::Color(97, 97, 97));
	exit.setOutlineThickness(10.f);
	sf::RectangleShape restart(sf::Vector2f(200.f, 80.f));
	restart.setPosition(sf::Vector2f(420.f, 540.f));
	restart.setFillColor(sf::Color(140, 140, 140));
	restart.setOutlineColor(sf::Color(97, 97, 97));
	restart.setOutlineThickness(10.f);
	this->exitText.setFont(this->gamePlayFont);
	this->exitText.setString("EXIT");
	this->exitText.setPosition(sf::Vector2f(195.f, 565.f));
	this->exitText.setFillColor(sf::Color::Black);
	this->exitText.setOutlineColor(sf::Color(100, 255, 43));
	this->restartText.setFont(this->gamePlayFont);
	this->restartText.setString("REPLAY");
	this->restartText.setPosition(sf::Vector2f(430.f, 565.f));
	this->restartText.setFillColor(sf::Color::Black);
	this->restartText.setOutlineColor(sf::Color(100, 255, 43));
	window->draw(panel);
	window->draw(gameOver);
	window->draw(nickText);
	window->draw(nick);
	window->draw(scoreText);
	window->draw(score);
	window->draw(highScoreText);
	window->draw(highScore);
	window->draw(exit);
	window->draw(restart);
	window->draw(this->exitText);
	window->draw(this->restartText);
	if (this->isHighScore) {
		sf::Text newHighScore;
		newHighScore.setFont(this->gamePlayFont);
		newHighScore.setString("NEW HIGH SCORE!");
		newHighScore.setPosition(sf::Vector2f(170.f, 415.f));
		newHighScore.setFillColor(sf::Color::Red);
		window->draw(newHighScore);
	}
}
void GamePlay::update(sf::RenderWindow* window) {
	this->updateMousePosWindow(window);
	if (!this->isPaused && !this->isGameOver) {
		updateEnemies();
		updateBullets();
		updateScore();
		if (!this->shootingBuffer) {
			this->timer++;
			if (this->timer % 15 == 0) {
				this->shootingBuffer = true;
				this->timer = 0;
			}
		}
	}
	if (this->isGameOver) {
		if (this->mousePosWindow.x >= 160.f && this->mousePosWindow.x <= 360.f && this->mousePosWindow.y >= 540.f && this->mousePosWindow.y <= 620.f) {
			this->exitText.setOutlineThickness(5.f);
		}
		else {
			this->exitText.setOutlineThickness(0.f);
		}
		if (this->mousePosWindow.x >= 420.f && this->mousePosWindow.x <= 620.f && this->mousePosWindow.y >= 540.f && this->mousePosWindow.y <= 620.f) {
			this->restartText.setOutlineThickness(5.f);
		}
		else {
			this->restartText.setOutlineThickness(0.f);
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
						if ((*ite)->enemyHit()) {
							shouldDeleteEnemy = true;
						}
						shouldDelete = true;
					}
				}
				if (shouldDeleteEnemy) {
					ite = this->enemiesVector.erase(ite);
					this->spawnNewEnemy();
					score++;
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
						if ((*ite)->enemyHit()) {
							shouldDeleteEnemy = true;
						}
						shouldDelete = true;
					}
				}
				if (shouldDeleteEnemy) {
					ite = this->enemiesVector.erase(ite);
					this->spawnNewEnemy();
					score++;
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
						if ((*ite)->enemyHit()) {
							shouldDeleteEnemy = true;
						}
						shouldDelete = true;
					}
				}
				if (shouldDeleteEnemy) {
					ite = this->enemiesVector.erase(ite);
					this->spawnNewEnemy();
					score++;
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
						if ((*ite)->enemyHit()) {
							shouldDeleteEnemy = true;
						}
						shouldDelete = true;
					}
				}
				if (shouldDeleteEnemy) {
					ite = this->enemiesVector.erase(ite);
					this->spawnNewEnemy();
					score++;
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
		for (auto& newEnemy : this->newEnemiesVector) {
			this->enemiesVector.push_back(std::move(newEnemy));
		}
		this->newEnemiesVector.clear();
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
			this->isGameOver = true;
			this->clearVectors = true;
			if (this->score > this->player.getScore()) {
				this->isHighScore = true;
				if (this->player.getNick() != "GUEST") {
					this->player.setScore(this->score);
					this->leaderboard.updateDatabase(this->player);
				}
			}
			std::cout << "GAME OVER" << std::endl;
		}
		else {
			++it;
		}
	}
}
void GamePlay::updateScore() {
	this->scoreText.setString(std::to_string(this->score));
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
	if (!this->isGameOver) {
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
				this->PlayerSprite.setTexture(this->PlayerTextureNorth);
				std::unique_ptr<Bullet> tempB = std::make_unique<Bullet>(Direction::NORTH);
				this->bulletsVector.push_back(std::move(tempB));
				this->shootingBuffer = false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && this->shootingBuffer && !isPaused) {
				this->PlayerSprite.setTexture(this->PlayerTextureEast);
				std::unique_ptr<Bullet> tempB = std::make_unique<Bullet>(Direction::EAST);
				this->bulletsVector.push_back(std::move(tempB));
				this->shootingBuffer = false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->shootingBuffer && !isPaused) {
				this->PlayerSprite.setTexture(this->PlayerTextureSouth);
				std::unique_ptr<Bullet> tempB = std::make_unique<Bullet>(Direction::SOUTH);
				this->bulletsVector.push_back(std::move(tempB));
				this->shootingBuffer = false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && this->shootingBuffer && !isPaused) {
				this->PlayerSprite.setTexture(this->PlayerTextureWest);
				std::unique_ptr<Bullet> tempB = std::make_unique<Bullet>(Direction::WEST);
				this->bulletsVector.push_back(std::move(tempB));
				this->shootingBuffer = false;
			}
		}
	}
	if (this->isGameOver) {
		while (window->pollEvent(this->ev)) {
			switch (this->ev.type) {
			case sf::Event::Closed:
				window->close();
				break;
			case sf::Event::MouseButtonPressed:
				if (this->mousePosWindow.x >= 160.f && this->mousePosWindow.x <= 360.f && this->mousePosWindow.y >= 540.f && this->mousePosWindow.y <= 620.f) {
					window->close();
				}
				if (this->mousePosWindow.x >= 420.f && this->mousePosWindow.x <= 620.f && this->mousePosWindow.y >= 540.f && this->mousePosWindow.y <= 620.f) {
					this->initEnemies();
					this->score = 0;
					this->isGameOver = false;
					this->isHighScore = false;
				}
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