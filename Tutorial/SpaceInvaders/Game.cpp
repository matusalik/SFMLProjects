#include "Game.h"
//Private functions
void Game::initVariables(){
	this->window = nullptr;
}
void Game::initWindow() {
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "SpaceInvaders", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(144);
}
void Game::initEnemies() {
	this->enemy.setPosition(10.f, 10.f);
	this->enemy.setSize(sf::Vector2f(80.f, 80.f));
	this->enemy.setFillColor(sf::Color::Cyan);
	this->enemy.setOutlineColor(sf::Color::Green);
	this->enemy.setOutlineThickness(10.f);
}
void Game::initButton() {
	this->button.setPosition(200.f, 100.f);
	this->button1.setPosition(200.f, 300.f);
	this->button.setSize(sf::Vector2f(200.f, 150.f));
	this->button1.setSize(sf::Vector2f(200.f, 150.f));
	this->button.setFillColor(sf::Color::Red);
	this->button1.setFillColor(sf::Color::Green);
	this->button.setOutlineColor(sf::Color::Green);
	this->button1.setOutlineColor(sf::Color::Red);
}
void Game::initFont() {
	if (!this->font.loadFromFile("fonts/PressStart2P-vaV7.ttf")) {
		std::cout << "Couldn't load the font" << std::endl;
	}
}
void Game::initText(){
	this->text.setFont(this->font);
	this->text.setPosition(500, 300);
	this->text.setString("123");
}
void Game::updateMousePositions() {
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}
//Constructors / Destructors
Game::Game() {
	this->initVariables();
	this->initWindow();
	this->initEnemies();
	this->initButton();
	this->initFont();
	this->initText();
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
	while (this->window->pollEvent(this->ev)) {
		switch (this->ev.type) {
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			switch (ev.key.code) {
			case sf::Keyboard::Escape:
				this->window->close();
				break;
			case sf::Keyboard::W:
				this->enemy.move(0, -10);
				break;
			case sf::Keyboard::D:
				this->enemy.move(10, 0);
				break;
			case sf::Keyboard::S:
				this->enemy.move(0, 10);
				break;
			case sf::Keyboard::A:
				this->enemy.move(-10, 0);
				break;
			}
			break;
		case sf::Event::MouseButtonPressed:
			if (sf::Mouse::getPosition(*this->window).x >= 200 && sf::Mouse::getPosition(*this->window).x <= 400
				&& sf::Mouse::getPosition(*this->window).y >= 100 && sf::Mouse::getPosition(*this->window).y <= 250) {
				this->text.setString("PRESSED1");
			}
			if (sf::Mouse::getPosition(*this->window).x >= 200 && sf::Mouse::getPosition(*this->window).x <= 400
				&& sf::Mouse::getPosition(*this->window).y >= 300 && sf::Mouse::getPosition(*this->window).y <= 450) {
				this->text.setString("PRESSED2");
			}
			break;
		}
	}
}
void Game::update(){
	this->pollEvents();
	this->updateMousePositions();
	if (mousePosWindow.x >= 200 && mousePosWindow.x <= 400 && mousePosWindow.y >= 100 && mousePosWindow.y <= 250) {
		this->button.setOutlineThickness(10.f);
	}
	else {
		this->button.setOutlineThickness(0.f);
	}
	if (mousePosWindow.x >= 200 && mousePosWindow.x <= 400 && mousePosWindow.y >= 300 && mousePosWindow.y <= 450) {
		this->button1.setOutlineThickness(10.f);
	}
	else {
		this->button1.setOutlineThickness(0.f);
	}
}
void Game::render() {
	/*
		-clear old frame
		-render objects
		-display frame in window
	*/
	this->window->clear();
	//Draw game obj
	this->window->draw(this->enemy);
	this->window->draw(this->button);
	this->window->draw(this->button1);
	this->window->draw(this->text);
	this->window->display();
}