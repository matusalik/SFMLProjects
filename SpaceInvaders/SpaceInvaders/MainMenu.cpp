#include "MainMenu.h"
MainMenu::MainMenu() {
	this->initEnum();
	this->initTextures();
	this->initSprites();
	this->initVariables();
	this->initFont();
	this->initButton();
	this->initText();
	this->initTextBoxes();
}
MainMenu::~MainMenu() {

}
void MainMenu::initEnum() {
	this->state = GameState::MAIN_MENU;
}
void MainMenu::initTextures() {
	if (!this->mainMenuBackgroundTexture.loadFromFile("backgrounds/MainMenuBackground.png")) {
		std::cout << "Couldn't load MainMenuBackground!" << std::endl;
	}
	if (!this->leaderboardsButtonTexture.loadFromFile("sprites/LeaderboardButtonSprite.png")) {
		std::cout << "Couldn't load LeaderboardButtonSprite!" << std::endl;
	}
	if (!this->leaderboardsButtonTextureOutline.loadFromFile("sprites/LeaderboardButtonSpriteOutline.png")) {
		std::cout << "Couldn't load LeaderboardButtonSpriteOutline!" << std::endl;
	}
	if (!this->settingsButtonTexture.loadFromFile("sprites/SettingsButtonSprite.png")) {
		std::cout << "Couldn't load SettingsButtonSprite!" << std::endl;
	}
	if (!this->settingsButtonTextureOutline.loadFromFile("sprites/SettingsButtonSpriteOutline.png")) {
		std::cout << "Couldn't load SettingsButtonSpriteOutline!" << std::endl;
	}
}
void MainMenu::initSprites() {
	this->mainMenuBackgroundSprite.setTexture(this->mainMenuBackgroundTexture);
	this->leaderboardsButtonSprite.setTexture(this->leaderboardsButtonTexture);
	this->leaderboardsButtonSprite.setPosition(730.f, 650.f);
	this->settingsButtonSprite.setTexture(this->settingsButtonTexture);
	this->settingsButtonSprite.setPosition(730.f, 730.f);
}
void MainMenu::initTextBoxes() {
	this->nickTextBox.setPosition(247.f, 200.f);
	this->nickTextBox.setSize(sf::Vector2f(300.f, 50.f));
	this->nickTextBox.setFillColor(sf::Color::White);
	this->nickTextBox.setOutlineColor(sf::Color(100, 255, 43));
}
void MainMenu::initButton() {
	this->playButton.setPosition(257.f, 420.f);
	this->playButton.setSize(sf::Vector2f(280.f, 80.f));
	this->playButton.setFillColor(sf::Color(138.f, 138.f, 138.f));
	this->playButton.setOutlineColor(sf::Color(105, 105, 105));
	this->playButton.setOutlineThickness(10.f);
	this->helpButton.setPosition(257.f, 560.f);
	this->helpButton.setSize(sf::Vector2f(280.f, 80.f));
	this->helpButton.setFillColor(sf::Color(138, 138, 138));
	this->helpButton.setOutlineColor(sf::Color(105, 105, 105));
	this->helpButton.setOutlineThickness(10.f);
	this->exitButton.setPosition(257.f, 700.f);
	this->exitButton.setSize(sf::Vector2f(280.f, 80.f));
	this->exitButton.setFillColor(sf::Color(138, 138, 138));
	this->exitButton.setOutlineColor(sf::Color(105, 105, 105));
	this->exitButton.setOutlineThickness(10.f);
	this->guestCheckBox.setPosition(252, 340);
	this->guestCheckBox.setSize(sf::Vector2f(30.f, 30.f));
	this->guestCheckBox.setFillColor(sf::Color(138, 138, 138));
	this->guestCheckBox.setOutlineColor(sf::Color(105, 105, 105));
	this->guestCheckBox.setOutlineThickness(5.f);
	this->settingsButon.setPosition(730.f, 730.f);
	this->settingsButon.setSize(sf::Vector2f(50.f, 50.f));
	this->settingsButon.setFillColor(sf::Color(138, 138, 138));
	this->settingsButon.setOutlineColor(sf::Color(105, 105, 105));
	this->settingsButon.setOutlineThickness(10.f);
	this->leaderboardButton.setPosition(730.f, 650.f);
	this->leaderboardButton.setSize(sf::Vector2f(50.f, 50.f));
	this->leaderboardButton.setFillColor(sf::Color(138, 138, 138));
	this->leaderboardButton.setOutlineColor(sf::Color(105, 105, 105));
	this->leaderboardButton.setOutlineThickness(10.f);
}
void MainMenu::initFont() {
	if (!this->MainMenuFont.loadFromFile("fonts/PressStart2P-vaV7.ttf")) {
		std::cout << "Couldn't load the font" << std::endl;
	}
}
void MainMenu::initText() {
	this->MainMenuTitlePos = { 120, 50 };
	this->MainMenuTitle.setFont(this->MainMenuFont);
	this->MainMenuTitle.setPosition(MainMenuTitlePos.x, MainMenuTitlePos.y);
	this->MainMenuTitle.setFillColor(sf::Color(100, 255, 43));
	this->MainMenuTitle.setString("Space Invaders");
	this->MainMenuTitle.setCharacterSize(this->mainMenuCharacterSize);
	this->MainMenuTitle.setOutlineColor(sf::Color::Black);
	this->MainMenuTitle.setOutlineThickness(5);
	this->MainMenuNick.setFont(this->MainMenuFont);
	this->MainMenuNick.setPosition(220.f, 150.f);
	this->MainMenuNick.setFillColor(sf::Color(100, 255, 43));
	this->MainMenuNick.setString("Enter your nickname");
	this->MainMenuNick.setCharacterSize(19);
	this->MainMenuNick.setOutlineColor(sf::Color::Black);
	this->MainMenuNick.setOutlineThickness(5);
	this->Nick.setFont(this->MainMenuFont);
	this->Nick.setPosition(250.f, 213.f);
	this->Nick.setFillColor(sf::Color::Black);
	this->nickValidationInfo.setFont(this->MainMenuFont);
	this->nickValidationInfo.setPosition(247.f, 260.f);
	this->nickValidationInfo.setFillColor(sf::Color(100, 255, 43));
	this->nickValidationInfo.setCharacterSize(14.f);
	this->nickValidationInfo.setString("Maximum 10 characters");
	this->nickValidationInfo.setOutlineColor(sf::Color::Black);
	this->nickValidationInfo.setOutlineThickness(5);
	this->playButtonText.setFont(this->MainMenuFont);
	this->playButtonText.setPosition(340.f, 450.f);
	this->playButtonText.setString("PLAY");
	this->playButtonText.setFillColor(sf::Color::Black);
	this->playButtonText.setOutlineColor(sf::Color(100, 255, 43));
	this->helpButtonText.setFont(this->MainMenuFont);
	this->helpButtonText.setPosition(340.f, 590.f);
	this->helpButtonText.setString("HELP");
	this->helpButtonText.setFillColor(sf::Color::Black);
	this->helpButtonText.setOutlineColor(sf::Color(100, 255, 43));
	this->exitButtonText.setFont(this->MainMenuFont);
	this->exitButtonText.setPosition(340.f, 730.f);
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
void MainMenu::initVariables() {
	this->NickStr = "";
	this->mainMenuCharacterSize = 40;
	this->mainMenuHowOftenResizeCounter = 0;
	this->isGuestCheckboxClicked = false;
	this->charSizeState = true;
	this->isNickTextBoxClicked = false;
}
void MainMenu::isNickValid() {
	std::string temp = this->Nick.getString();
}
bool MainMenu::checkIfPlayerExists() {
	Leaderboard leaderboard;
	for (auto i : leaderboard.getDatabase()) {
		if (player.getNick() == i.getNick()) {
			return true;
		}
		return false;
	}
}
void MainMenu::updateMainMenuCharSize() {
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
void MainMenu::draw(sf::RenderWindow*& window) {
	window->draw(this->mainMenuBackgroundSprite);
	window->draw(this->MainMenuTitle);
	window->draw(this->MainMenuNick);
	window->draw(this->nickTextBox);
	window->draw(this->Nick);
	window->draw(this->nickValidationInfo);
	window->draw(this->playButton);
	window->draw(this->helpButton);
	window->draw(this->exitButton);
	window->draw(this->settingsButon);
	window->draw(this->leaderboardButton);
	window->draw(this->playButtonText);
	window->draw(this->helpButtonText);
	window->draw(this->exitButtonText);
	window->draw(this->leaderboardsButtonSprite);
	window->draw(this->settingsButtonSprite);
	window->draw(this->guestCheckBox);
	window->draw(this->playAsAGuest);
	window->draw(this->tick);
}
void MainMenu::pollEvents(sf::RenderWindow*& window) {
	while (window->pollEvent(this->ev)) {
		switch (this->ev.type) {
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::MouseButtonPressed:
			if (mousePosWindow.x >= 730 && mousePosWindow.x <= 780 && mousePosWindow.y >= 730 && mousePosWindow.y <= 780) {
				this->state = GameState::SETTINGS;
			}
			if (mousePosWindow.x >= 730 && mousePosWindow.x <= 780 && mousePosWindow.y >= 650 && mousePosWindow.y <= 700) {
				this->state = GameState::LEADERBOARD;
			}
			if (mousePosWindow.x >= 257 && mousePosWindow.x <= 537 && mousePosWindow.y >= 420 && mousePosWindow.y <= 500) {
				this->state = GameState::GAME_PLAY;
				if (!this->isGuestCheckboxClicked) {
					player.setNick(this->NickStr);
					if (checkIfPlayerExists()) {
						player = getExistingPlayer();
					}
				}
				else {
					player.setNick("GUEST");
				}
			}
			if (mousePosWindow.x >= 257 && mousePosWindow.x <= 537 && mousePosWindow.y >= 560 && mousePosWindow.y <= 640) {
				this->state = GameState::HELP_PANEL;
			}
			if (mousePosWindow.x >= 257 && mousePosWindow.x <= 537 && mousePosWindow.y >= 700 && mousePosWindow.y <= 780) {
				window->close();
			}
			if (mousePosWindow.x >= 252 && mousePosWindow.x <= 282 && mousePosWindow.y >= 340 && mousePosWindow.y <= 370) {
				if (this->tick.getString() == "") {
					this->tick.setString("X");
					this->NickStr = "";
					this->Nick.setString(this->NickStr);
					this->nickTextBox.setFillColor(sf::Color(207, 207, 207));
					this->isGuestCheckboxClicked = true;

				}
				else {
					this->tick.setString("");
					this->nickTextBox.setFillColor(sf::Color::White);
					this->isGuestCheckboxClicked = false;
				}
			}
			if (mousePosWindow.x >= 247 && mousePosWindow.x <= 547 && mousePosWindow.y >= 200 && mousePosWindow.y <= 250 && !this->isGuestCheckboxClicked) {
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
Player MainMenu::getExistingPlayer() {
	Leaderboard leaderboard;
	for (auto i : leaderboard.getDatabase()) {
		if (this->player.getNick() == i.getNick()) {
			return i;
		}
	}
}
void MainMenu::update(sf::RenderWindow* window) {
	this->updateMainMenuCharSize();
	this->updateMousePosWindow(window);
	this->isNickValid();
	if (mousePosWindow.x >= 730 && mousePosWindow.x <= 780 && mousePosWindow.y >= 650 && mousePosWindow.y <= 700) {
		this->leaderboardsButtonSprite.setTexture(this->leaderboardsButtonTextureOutline);
	}
	else {
		this->leaderboardsButtonSprite.setTexture(this->leaderboardsButtonTexture);
	}
	if (mousePosWindow.x >= 730 && mousePosWindow.x <= 780 && mousePosWindow.y >= 730 && mousePosWindow.y <= 780) {
		this->settingsButtonSprite.setTexture(this->settingsButtonTextureOutline);
	}
	else {
		this->settingsButtonSprite.setTexture(this->settingsButtonTexture);
	}
	if (mousePosWindow.x >= 252 && mousePosWindow.x <= 282 && mousePosWindow.y >= 340 && mousePosWindow.y <= 370) {
		this->guestCheckBox.setFillColor(sf::Color(112, 112, 112));
		this->guestCheckBox.setOutlineColor(sf::Color(79, 79, 79));
	}
	else {
		this->guestCheckBox.setFillColor(sf::Color(138, 138, 138));
		this->guestCheckBox.setOutlineColor(sf::Color(105, 105, 105));
	}
	if (mousePosWindow.x >= 257 && mousePosWindow.x <= 537 && mousePosWindow.y >= 700 && mousePosWindow.y <= 780) {
		this->exitButtonText.setOutlineThickness(3.f);
	}
	else {
		this->exitButtonText.setOutlineThickness(0.f);
	}
	if (mousePosWindow.x >= 257 && mousePosWindow.x <= 537 && mousePosWindow.y >= 560 && mousePosWindow.y <= 640) {
		this->helpButtonText.setOutlineThickness(3.f);
	}
	else {
		this->helpButtonText.setOutlineThickness(0.f);
	}
	if (mousePosWindow.x >= 257 && mousePosWindow.x <= 537 && mousePosWindow.y >= 420 && mousePosWindow.y <= 500) {
		this->playButtonText.setOutlineThickness(3.f);
	}
	else {
		this->playButtonText.setOutlineThickness(0.f);
	}
	if (mousePosWindow.x >= 247 && mousePosWindow.x <= 547 && mousePosWindow.y >= 200 && mousePosWindow.y <= 250 && !this->isGuestCheckboxClicked) {
		this->nickTextBox.setOutlineThickness(4.f);
	}
	else if (!this->isNickTextBoxClicked) {
		this->nickTextBox.setOutlineThickness(0.f);
	}
}
void MainMenu::updateMousePosWindow(sf::RenderWindow* window) {
	this->mousePosWindow = sf::Mouse::getPosition(*window);
}
GameState MainMenu::returnGameState() {
	return this->state;
}
void MainMenu::setState(GameState sentState) {
	this->state = sentState;
}
Player MainMenu::getPlayer() {
	return this->player;
}