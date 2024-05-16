#include "Settings.h"

Settings::Settings() {
	this->initEnum();
	this->initFont();
	this->initTextures();
	this->initSprites();
	this->initButtons();
	this->initText();
}
void Settings::initFont() {
	if (!this->settingsFont.loadFromFile("fonts/PressStart2P-vaV7.ttf")) {
		std::cout << "Couldn't load the font" << std::endl;
	}
}
void Settings::initText() {
	this->gameDifficultyText.setFont(this->settingsFont);
	this->gameDifficultyText.setPosition(80.f, 150.f);
	this->gameDifficultyText.setFillColor(sf::Color(100, 255, 43));
	this->gameDifficultyText.setString("SELECT GAME DIFFICULTY");
	this->gameDifficultyText.setOutlineColor(sf::Color::Black);
	this->gameDifficultyText.setOutlineThickness(5);
	this->easyCheckboxText.setFont(this->settingsFont);
	this->easyCheckboxText.setPosition(320.f, 255.f);
	this->easyCheckboxText.setFillColor(sf::Color(100, 255, 43));
	this->easyCheckboxText.setString("EASY");
	this->easyCheckboxText.setOutlineColor(sf::Color::Black);
	this->easyCheckboxText.setOutlineThickness(5);
	this->normalCheckboxText.setFont(this->settingsFont);
	this->normalCheckboxText.setPosition(320.f, 385.f);
	this->normalCheckboxText.setFillColor(sf::Color(100, 255, 43));
	this->normalCheckboxText.setString("NORMAL");
	this->normalCheckboxText.setOutlineColor(sf::Color::Black);
	this->normalCheckboxText.setOutlineThickness(5);
	this->hardCheckboxText.setFont(this->settingsFont);
	this->hardCheckboxText.setPosition(320.f, 515.f);
	this->hardCheckboxText.setFillColor(sf::Color(100, 255, 43));
	this->hardCheckboxText.setString("HARD");
	this->hardCheckboxText.setOutlineColor(sf::Color::Black);
	this->hardCheckboxText.setOutlineThickness(5);
	this->exitButtonText.setFont(this->settingsFont);
	this->exitButtonText.setPosition(340.f, 700.f);
	this->exitButtonText.setString("EXIT");
	this->exitButtonText.setFillColor(sf::Color::Black);
	this->exitButtonText.setOutlineColor(sf::Color(100, 255, 43));
	this->tickEasy.setFont(this->settingsFont);
	this->tickEasy.setPosition(258, 257);
	this->tickEasy.setString("");
	this->tickEasy.setFillColor(sf::Color::Black);
	this->tickNormal.setFont(this->settingsFont);
	this->tickNormal.setPosition(258, 387);
	this->tickNormal.setString("");
	this->tickNormal.setFillColor(sf::Color::Black);
	this->tickHard.setFont(this->settingsFont);
	this->tickHard.setPosition(258, 517);
	this->tickHard.setString("");
	this->tickHard.setFillColor(sf::Color::Black);
}
void Settings::initTextures() {
	if (!this->settingsBackgroundTexture.loadFromFile("backgrounds/SettingsBackground.png")) {
		std::cout << "Couldn't load SettingsBackground!" << std::endl;
	}
}
void Settings::initSprites() {
	this->settingsBackgroundSprite.setTexture(this->settingsBackgroundTexture);
}
void Settings::initEnum() {
	this->state = GameState::SETTINGS;
	this->difficulty = GameDifficulty::NORMAL;
}
void Settings::initButtons() {
	this->easyCheckBox.setPosition(252.f, 250.f);
	this->easyCheckBox.setSize(sf::Vector2f(40.f, 40.f));
	this->easyCheckBox.setFillColor(sf::Color(138, 138, 138));
	this->easyCheckBox.setOutlineColor(sf::Color(105, 105, 105));
	this->easyCheckBox.setOutlineThickness(5.f);
	this->normalCheckBox.setPosition(252.f, 380.f);
	this->normalCheckBox.setSize(sf::Vector2f(40.f, 40.f));
	this->normalCheckBox.setFillColor(sf::Color(138, 138, 138));
	this->normalCheckBox.setOutlineColor(sf::Color(105, 105, 105));
	this->normalCheckBox.setOutlineThickness(5.f);
	this->hardCheckBox.setPosition(252.f, 510.f);
	this->hardCheckBox.setSize(sf::Vector2f(40.f, 40.f));
	this->hardCheckBox.setFillColor(sf::Color(138, 138, 138));
	this->hardCheckBox.setOutlineColor(sf::Color(105, 105, 105));
	this->hardCheckBox.setOutlineThickness(5.f);
	this->exitButton.setPosition(257.f, 670.f);
	this->exitButton.setSize(sf::Vector2f(280.f, 80.f));
	this->exitButton.setFillColor(sf::Color(138, 138, 138));
	this->exitButton.setOutlineColor(sf::Color(105, 105, 105));
	this->exitButton.setOutlineThickness(10.f);
}
void Settings::draw(sf::RenderWindow*& window) {
	window->draw(this->settingsBackgroundSprite);
	window->draw(this->easyCheckBox);
	window->draw(this->normalCheckBox);
	window->draw(this->hardCheckBox);
	window->draw(this->exitButton);
	window->draw(this->gameDifficultyText);
	window->draw(this->easyCheckboxText);
	window->draw(this->normalCheckboxText);
	window->draw(this->hardCheckboxText);
	window->draw(this->exitButtonText);
	window->draw(this->tickEasy);
	window->draw(this->tickNormal);
	window->draw(this->tickHard);
}
void Settings::pollEvents(sf::RenderWindow*& window) {
	while (window->pollEvent(this->ev)) {
		switch (this->ev.type) {
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::MouseButtonPressed:
			if (this->mousePosWindow.x >= 257 && this->mousePosWindow.x <= 537 && this->mousePosWindow.y >= 670 && this->mousePosWindow.y <= 750) {
				this->state = GameState::MAIN_MENU;
			}
			if (this->mousePosWindow.x >= 252 && mousePosWindow.x <= 292 && this->mousePosWindow.y >= 250 && mousePosWindow.y <= 290 && this->difficulty != GameDifficulty::EASY) {
				this->difficulty = GameDifficulty::EASY;
			}
			if (this->mousePosWindow.x >= 252 && mousePosWindow.x <= 292 && this->mousePosWindow.y >= 380 && mousePosWindow.y <= 420 && this->difficulty != GameDifficulty::NORMAL) {
				this->difficulty = GameDifficulty::NORMAL;
			}
			if (this->mousePosWindow.x >= 252 && mousePosWindow.x <= 292 && this->mousePosWindow.y >= 510 && mousePosWindow.y <= 550 && this->difficulty != GameDifficulty::HARD) {
				this->difficulty = GameDifficulty::HARD;
			}
			break;
		}
	}
}
void Settings::update(sf::RenderWindow* window) {
	this->updateMousePosWindow(window);
	if (this->difficulty == GameDifficulty::EASY) {
		this->tickEasy.setString("X");
	}
	else {
		this->tickEasy.setString("");
	}
	if (this->difficulty == GameDifficulty::NORMAL) {
		this->tickNormal.setString("X");
	}
	else {
		this->tickNormal.setString("");
	}
	if (this->difficulty == GameDifficulty::HARD) {
		this->tickHard.setString("X");
	}
	else {
		this->tickHard.setString("");
	}
	if (this->mousePosWindow.x >= 257 && this->mousePosWindow.x <= 537 && this->mousePosWindow.y >= 670 && this->mousePosWindow.y <= 750) {
		this->exitButtonText.setOutlineThickness(5.f);
	}
	else {
		this->exitButtonText.setOutlineThickness(0.f);
	}
	if (this->mousePosWindow.x >= 252 && mousePosWindow.x <= 292 && this->mousePosWindow.y >= 510 && mousePosWindow.y <= 550 && this->difficulty != GameDifficulty::HARD) {
		this->hardCheckBox.setFillColor(sf::Color(112, 112, 112));
		this->hardCheckBox.setOutlineColor(sf::Color(79, 79, 79));
	}
	else {
		this->hardCheckBox.setFillColor(sf::Color(138, 138, 138));
		this->hardCheckBox.setOutlineColor(sf::Color(105, 105, 105));
	}
	if (this->mousePosWindow.x >= 252 && mousePosWindow.x <= 292 && this->mousePosWindow.y >= 380 && mousePosWindow.y <= 420 && this->difficulty != GameDifficulty::NORMAL) {
		this->normalCheckBox.setFillColor(sf::Color(112, 112, 112));
		this->normalCheckBox.setOutlineColor(sf::Color(79, 79, 79));
	}
	else {
		this->normalCheckBox.setFillColor(sf::Color(138, 138, 138));
		this->normalCheckBox.setOutlineColor(sf::Color(105, 105, 105));
	}
	if (this->mousePosWindow.x >= 252 && mousePosWindow.x <= 292 && this->mousePosWindow.y >= 250 && mousePosWindow.y <= 290 && this->difficulty != GameDifficulty::EASY) {
		this->easyCheckBox.setFillColor(sf::Color(112, 112, 112));
		this->easyCheckBox.setOutlineColor(sf::Color(79, 79, 79));
	}
	else {
		this->easyCheckBox.setFillColor(sf::Color(138, 138, 138));
		this->easyCheckBox.setOutlineColor(sf::Color(105, 105, 105));
	}
}
void Settings::updateMousePosWindow(sf::RenderWindow* window) {
	this->mousePosWindow = sf::Mouse::getPosition(*window);
}
GameState Settings::returnGameState() {
	return this->state;
}
GameDifficulty Settings::getDifficulty() {
	return this->difficulty;
}
void Settings::setState(GameState sentState) {
	this->state = sentState;
}
