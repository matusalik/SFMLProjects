#include "Game.h"
//Private functions
void Game::initPanels() {
	mainMenu = new MainMenu;
	helpPanel = new HelpPanel;
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
	}
	if (this->state == GameState::HELP_PANEL) {
		this->helpPanel->pollEvents(this->window);
	}
}
void Game::update(){
	this->updateMousePosWindow();
	this->pollEvents();
	if (this->state == GameState::MAIN_MENU) {
		this->mainMenu->update(this->window);
		if (this->mainMenu->returnGameState() == GameState::HELP_PANEL) {
			this->state = GameState::HELP_PANEL;
		}
	}
	if (this->state == GameState::HELP_PANEL) {
		this->helpPanel->update(this->window);
	}
}
void Game::render() {
	if (this->state == GameState::MAIN_MENU) {
		this->window->clear();
		this->mainMenu->draw(this->window);
		this->window->display();
	}
	if (this->state == GameState::HELP_PANEL) {
		this->window->clear();
		this->helpPanel->draw(this->window);
		this->window->display();
	}
}