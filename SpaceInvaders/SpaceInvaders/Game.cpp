#include "Game.h"
//Private functions
void Game::initPanels() {
	this->mainMenu = new MainMenu;
	this->helpPanel = new HelpPanel;
	//this->gamePlay = new GamePlay;
	this->settings = new Settings;
	this->leaderboardPanel = new LeaderboardPanel;
}
void Game::initVariables() {
	this->window = nullptr;
}
void Game::initWindow() {
	this->videoMode.height = 800;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "SpaceInvaders", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(144);
}
void Game::initEnum() {
	this->state = GameState::MAIN_MENU;
}
void Game::updateMousePosWindow() {
	mousePosWindow = sf::Mouse::getPosition(*this->window);
}

//Constructors / Destructors
Game::Game() {
	this->initEnum();
	this->initPanels();
	this->initVariables();
	this->initWindow();
}
Game::~Game() {
	delete this->window;
}

//Accessors
const bool Game::running() {
	return this->window->isOpen();
}

//Functions
void Game::pollEvents() {
	//Event polling
	if (this->state == GameState::MAIN_MENU) {
		this->mainMenu->pollEvents(this->window);
		if (this->mainMenu->returnGameState() == GameState::HELP_PANEL) {
			this->state = GameState::HELP_PANEL;
			this->mainMenu->setState(GameState::MAIN_MENU);
		}
		if (this->mainMenu->returnGameState() == GameState::GAME_PLAY) {
			Settings* sett = dynamic_cast<Settings*>(this->settings);
			if (sett) {
				this->difficulty = sett->getDifficulty();
			}
			else {
				std::cout << "Cast failed" << std::endl;
			}
			MainMenu* menu = dynamic_cast<MainMenu*>(this->mainMenu);
			if (menu) {
				this->player = menu->getPlayer();
				std::cout << player.getNick() << std::endl;
				std::cout << player.getScore() << std::endl;
			}
			else {
				std::cout << "Cast failed" << std::endl;
			}
			this->gamePlay = new GamePlay(this->difficulty, this->player);
			this->state = GameState::GAME_PLAY;
			this->mainMenu->setState(GameState::MAIN_MENU);
		}
		if (this->mainMenu->returnGameState() == GameState::SETTINGS) {
			this->state = GameState::SETTINGS;
			this->mainMenu->setState(GameState::MAIN_MENU);
		}
		if (this->mainMenu->returnGameState() == GameState::LEADERBOARD) {
			this->state = GameState::LEADERBOARD;
			this->mainMenu->setState(GameState::MAIN_MENU);
		}
	}
	if (this->state == GameState::HELP_PANEL) {
		this->helpPanel->pollEvents(this->window);
		if (this->helpPanel->returnGameState() == GameState::MAIN_MENU) {
			this->state = GameState::MAIN_MENU;
			this->helpPanel->setState(GameState::HELP_PANEL);
		}
	}
	if (this->state == GameState::SETTINGS) {
		this->settings->pollEvents(this->window);
		if (this->settings->returnGameState() == GameState::MAIN_MENU) {
			this->state = GameState::MAIN_MENU;
			this->settings->setState(GameState::SETTINGS);
		}
	}
	if (this->state == GameState::LEADERBOARD) {
		this->leaderboardPanel->pollEvents(this->window);
		if (this->leaderboardPanel->returnGameState() == GameState::MAIN_MENU) {
			this->state = GameState::MAIN_MENU;
			this->leaderboardPanel->setState(GameState::LEADERBOARD);
		}
	}
	if (this->state == GameState::GAME_PLAY) {
		this->gamePlay->pollEvents(this->window);
		if (this->gamePlay->returnGameState() == GameState::MAIN_MENU) {
			this->state = GameState::MAIN_MENU;
			this->gamePlay->setState(GameState::GAME_PLAY);
		}
	}
}
void Game::update() {
	this->updateMousePosWindow();
	this->pollEvents();
	if (this->state == GameState::MAIN_MENU) {
		this->mainMenu->update(this->window);
	}
	if (this->state == GameState::HELP_PANEL) {
		this->helpPanel->update(this->window);
	}
	if (this->state == GameState::SETTINGS) {
		this->settings->update(this->window);
	}
	if (this->state == GameState::LEADERBOARD) {
		this->leaderboardPanel->update(this->window);
	}
	if (this->state == GameState::GAME_PLAY) {
		this->gamePlay->update(this->window);
	}
}
void Game::render() {
	this->window->clear();
	if (this->state == GameState::MAIN_MENU) {
		this->mainMenu->draw(this->window);
	}
	if (this->state == GameState::HELP_PANEL) {
		this->helpPanel->draw(this->window);
	}
	if (this->state == GameState::GAME_PLAY) {
		this->gamePlay->draw(this->window);
	}
	if (this->state == GameState::SETTINGS) {
		this->settings->draw(this->window);
	}
	if (this->state == GameState::LEADERBOARD) {
		this->leaderboardPanel->draw(this->window);
	}
	this->window->display();
}