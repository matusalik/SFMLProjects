﻿#include "Game.h"
//Private functions
void Game::initVariables(){
	this->window = nullptr;
}
void Game::initWindow() {
	this->videoMode.height = 800;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "SpaceInvaders", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(144);
}
void Game::initEnemies() {
	
}
void Game::initButton() {
	this->playButton.setPosition(257.f, 410.f);
	this->playButton.setSize(sf::Vector2f(280.f, 80.f));
	this->playButton.setFillColor(sf::Color(138, 138, 138));
	this->playButton.setOutlineColor(sf::Color(105, 105, 105));
	this->playButton.setOutlineThickness(10.f);
	this->helpButton.setPosition(257.f, 550.f);
	this->helpButton.setSize(sf::Vector2f(280.f, 80.f));
	this->helpButton.setFillColor(sf::Color(138, 138, 138));
	this->helpButton.setOutlineColor(sf::Color(105, 105, 105));
	this->helpButton.setOutlineThickness(10.f);
	this->exitButton.setPosition(257.f, 690.f);
	this->exitButton.setSize(sf::Vector2f(280.f, 80.f));
	this->exitButton.setFillColor(sf::Color(138, 138, 138));
	this->exitButton.setOutlineColor(sf::Color(105, 105, 105));
	this->exitButton.setOutlineThickness(10.f);
	this->guestCheckBox.setPosition(252, 340);
	this->guestCheckBox.setSize(sf::Vector2f(30.f, 30.f));
	this->guestCheckBox.setFillColor(sf::Color(138, 138, 138));
	this->guestCheckBox.setOutlineColor(sf::Color(105, 105, 105));
	this->guestCheckBox.setOutlineThickness(5.f);
}
void Game::initFont() {
	if (!this->MainMenuFont.loadFromFile("fonts/PressStart2P-vaV7.ttf")) {
		std::cout << "Couldn't load the font" << std::endl;
	}
}
void Game::initText(){
	this->MainMenuTitlePos = { 120, 50 };
	this->MainMenuTitle.setFont(this->MainMenuFont);
	this->MainMenuTitle.setPosition(MainMenuTitlePos.x, MainMenuTitlePos.y);
	this->MainMenuTitle.setString("Space Invaders");
	this->MainMenuTitle.setCharacterSize(this->mainMenuCharacterSize);
	this->MainMenuNick.setFont(this->MainMenuFont);
	this->MainMenuNick.setPosition(220.f, 150.f);
	this->MainMenuNick.setString("Enter your nickname");
	this->MainMenuNick.setCharacterSize(19);
	this->Nick.setFont(this->MainMenuFont);
	this->Nick.setPosition(250.f, 213.f);
	this->Nick.setFillColor(sf::Color::Black);
	this->playButtonText.setFont(this->MainMenuFont);
	this->playButtonText.setPosition(340.f, 440.f);
	this->playButtonText.setString("PLAY");
	this->playButtonText.setFillColor(sf::Color::Black);
	this->playButtonText.setOutlineColor(sf::Color(100, 255, 43));
	this->helpButtonText.setFont(this->MainMenuFont);
	this->helpButtonText.setPosition(340.f, 580.f);
	this->helpButtonText.setString("HELP");
	this->helpButtonText.setFillColor(sf::Color::Black);
	this->helpButtonText.setOutlineColor(sf::Color(100, 255, 43));
	this->exitButtonText.setFont(this->MainMenuFont);
	this->exitButtonText.setPosition(340.f, 720.f);
	this->exitButtonText.setString("EXIT");
	this->exitButtonText.setFillColor(sf::Color::Black);
	this->exitButtonText.setOutlineColor(sf::Color(100, 255, 43));
	this->playAsAGuest.setFont(this->MainMenuFont);
	this->playAsAGuest.setPosition(295, 347);
	this->playAsAGuest.setCharacterSize(17);
	this->playAsAGuest.setString("Play as a guest");
	this->playAsAGuest.setFillColor(sf::Color(100, 255, 43));
	this->tick.setFont(this->MainMenuFont);
	this->tick.setPosition(254, 342);
	this->tick.setString("");
	this->tick.setFillColor(sf::Color::Black);
}
void Game::initEnum() {
	this->state = MAIN_MENU;
}
void Game::initTextBoxes() {
	this->nickTextBox.setPosition(247.f, 200.f);
	this->nickTextBox.setSize(sf::Vector2f(300.f, 50.f));
	this->nickTextBox.setFillColor(sf::Color::White);
	this->nickTextBox.setOutlineColor(sf::Color(100, 255, 43));
}
void Game::updateMousePosWindow() {
	mousePosWindow = sf::Mouse::getPosition(*this->window);
}
void Game::updateMainMenuCharSize() {
	if (this->mainMenuHowOftenResizeCounter % 4 == 0) {
		if (this->charSizeState) {
			this->MainMenuTitle.setCharacterSize(this->mainMenuCharacterSize--);
			this->MainMenuTitle.setPosition(MainMenuTitlePos.x, MainMenuTitlePos.y);
			MainMenuTitlePos.x += 7;
			if (this->mainMenuCharacterSize == 20) {
				this->charSizeState = false;
			}
		}
		else if (!this->charSizeState) {
			this->MainMenuTitle.setCharacterSize(this->mainMenuCharacterSize++);
			this->MainMenuTitle.setPosition(MainMenuTitlePos.x, MainMenuTitlePos.y);
			MainMenuTitlePos.x -= 7;
			if (this->mainMenuCharacterSize == 50) {
				this->charSizeState = true;
			}
		}
		mainMenuHowOftenResizeCounter = 0;
	}
	mainMenuHowOftenResizeCounter++;
}

//Constructors / Destructors
Game::Game() {
	this->initEnum();
	this->initVariables();
	this->initWindow();
	this->initEnemies();
	this->initButton();
	this->initFont();
	this->initText();
	this->initTextBoxes();
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
	if (this->state == MAIN_MENU) {
		while (this->window->pollEvent(this->ev)) {
			switch (this->ev.type) {
			case sf::Event::Closed:
				this->window->close();
				break;
			case sf::Event::MouseButtonPressed:
				if (mousePosWindow.x >= 252 && mousePosWindow.x <= 282 && mousePosWindow.y >= 340 && mousePosWindow.y <= 370) {
					if (this->tick.getString() == "") {
						this->tick.setString("X");
						this->nickTextBox.setFillColor(sf::Color(207, 207, 207));
						this->isGuestChecked = true;

					}
					else {
						this->tick.setString("");
						this->nickTextBox.setFillColor(sf::Color::White);
						this->isGuestChecked = false;
					}
				}
				if (mousePosWindow.x >= 247 && mousePosWindow.x <= 547 && mousePosWindow.y >= 200 && mousePosWindow.y <= 250 && !this->isGuestChecked) {
					this->isNickTextBoxClicked = true;
				}
				else {
					this->isNickTextBoxClicked = false;
				}
				break;
			case sf::Event::TextEntered:
				if (this->isNickTextBoxClicked) {
					if (this->ev.text.unicode == 8) {
						if (this->NickStr.size() != 0) {
							this->NickStr.pop_back();
							this->Nick.setString(this->NickStr);
						}
					}
					else {
						if (this->NickStr.size() < 10 && this->ev.text.unicode >= 48 && this->ev.text.unicode <= 57 ||
							this->ev.text.unicode >= 65 && this->ev.text.unicode <= 90 ||
							this->ev.text.unicode >= 97 && this->ev.text.unicode <= 122) {
							std::cout << this->ev.text.unicode << std::endl;
							this->NickStr.push_back((char)this->ev.text.unicode);
							this->Nick.setString(this->NickStr);
						}
					}
				}
			}
		}
	}
}
void Game::update(){
	if (this->state == MAIN_MENU) {
		this->pollEvents();
		this->updateMousePosWindow();
		this->updateMainMenuCharSize();
		if (mousePosWindow.x >= 252 && mousePosWindow.x <= 282 && mousePosWindow.y >= 340 && mousePosWindow.y <= 370) {
			this->guestCheckBox.setFillColor(sf::Color(112, 112, 112));
			this->guestCheckBox.setOutlineColor(sf::Color(79, 79, 79));
		}
		else {
			this->guestCheckBox.setFillColor(sf::Color(138, 138, 138));
			this->guestCheckBox.setOutlineColor(sf::Color(105, 105, 105));
		}
		if (mousePosWindow.x >= 257 && mousePosWindow.x <= 537 && mousePosWindow.y >= 690 && mousePosWindow.y <= 770) {
			this->exitButtonText.setOutlineThickness(3.f);
		}
		else {
			this->exitButtonText.setOutlineThickness(0.f);
		}
		if (mousePosWindow.x >= 257 && mousePosWindow.x <= 537 && mousePosWindow.y >= 550 && mousePosWindow.y <= 630) {
			this->helpButtonText.setOutlineThickness(3.f);
		}
		else {
			this->helpButtonText.setOutlineThickness(0.f);
		}
		if (mousePosWindow.x >= 257 && mousePosWindow.x <= 537 && mousePosWindow.y >= 410 && mousePosWindow.y <= 490) {
			this->playButtonText.setOutlineThickness(3.f);
		}
		else {
			this->playButtonText.setOutlineThickness(0.f);
		}
		if (mousePosWindow.x >= 247 && mousePosWindow.x <= 547 && mousePosWindow.y >= 200 && mousePosWindow.y <= 250 && !this->isGuestChecked) {
			this->nickTextBox.setOutlineThickness(4.f);
		}
		else if (!this->isNickTextBoxClicked) {
			this->nickTextBox.setOutlineThickness(0.f);
		}
	}
}
void Game::render() {
	if (this->state == MAIN_MENU) {
		this->window->clear();
		this->window->draw(this->MainMenuTitle);
		this->window->draw(this->MainMenuNick);
		this->window->draw(this->nickTextBox);
		this->window->draw(this->Nick);
		this->window->draw(this->playButton);
		this->window->draw(this->helpButton);
		this->window->draw(this->exitButton);
		this->window->draw(this->playButtonText);
		this->window->draw(this->helpButtonText);
		this->window->draw(this->exitButtonText);
		this->window->draw(this->guestCheckBox);
		this->window->draw(this->playAsAGuest);
		this->window->draw(this->tick);
		this->window->display();
	}
}