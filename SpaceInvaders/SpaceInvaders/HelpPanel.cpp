#include "HelpPanel.h"
HelpPanel::HelpPanel() {
	this->initEnum();
	this->initTextures();
	this->initSprites();
	this->initFonts();
	this->initButtons();
	this->initVariables();
	this->initText();
}
HelpPanel::~HelpPanel() {

}
void HelpPanel::initVariables() {
	this->helpString = "   Your mission is to \nprotect yourself against\naliens coming from north,\n  east, south and west.\n       Controlls: \n    W - Shoot North\n    A - Shoot West\n    S - Shoot South\n    D - Shoot East\n    ESC - Pause";		
}
void HelpPanel::initEnum() {
	this->state = GameState::HELP_PANEL;
}
void HelpPanel::initTextures() {
	if (!this->helpPanelBackgroundTexture.loadFromFile("backgrounds/HelpPanelBackground.png")) {
		std::cout << "Couldn't load HelpPanelBackground!" << std::endl;
	}
}
void HelpPanel::initSprites() {
	this->helpPanelBackgroundSprite.setTexture(this->helpPanelBackgroundTexture);
}
void HelpPanel::initButtons() {
	this->exitButton.setPosition(257.f, 680.f);
	this->exitButton.setSize(sf::Vector2f(280.f, 80.f));
	this->exitButton.setFillColor(sf::Color(138, 138, 138));
	this->exitButton.setOutlineColor(sf::Color(105, 105, 105));
	this->exitButton.setOutlineThickness(10.f);
}
void HelpPanel::initText() {
	this->exitText.setFont(this->helpPanelFont);
	this->exitText.setPosition(290.f, 705.f);
	this->exitText.setString("GO BACK");
	this->exitText.setFillColor(sf::Color::Black);
	this->exitText.setOutlineColor(sf::Color(100, 255, 43));
	this->helpText.setFont(this->helpPanelFont);
	this->helpText.setPosition(30.f, 30.f);
	this->helpText.setLineSpacing(2.f);
	this->helpText.setString(this->helpString);
	this->helpText.setFillColor(sf::Color::Black);
	
}
void HelpPanel::initFonts() {
	if (!this->helpPanelFont.loadFromFile("fonts/PressStart2P-vaV7.ttf")) {
		std::cout << "Couldn't load the font" << std::endl;
	}
}
void HelpPanel::updateMousePosWindow(sf::RenderWindow* window) {
	this->mousePosWindow = sf::Mouse::getPosition(*window);
	//std::cout << "X" << this->mousePosWindow.x << " ";
	//std::cout << "Y" << this->mousePosWindow.y << std::endl;
}
void HelpPanel::draw(sf::RenderWindow*& window) {
	window->draw(this->helpPanelBackgroundSprite);
	window->draw(this->exitButton);
	window->draw(this->exitText);
	window->draw(this->helpText);
}
void HelpPanel::update(sf::RenderWindow* window) {
	this->updateMousePosWindow(window);
	if (this->mousePosWindow.x >= 257 && this->mousePosWindow.x <= 537 && this->mousePosWindow.y >= 690 && this->mousePosWindow.y <= 770) {
		this->exitText.setOutlineThickness(5.f);
	}
	else {
		this->exitText.setOutlineThickness(0.f);
	}
}
void HelpPanel::pollEvents(sf::RenderWindow*& window) {
	while (window->pollEvent(this->ev)) {
		switch (this->ev.type) {
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::MouseButtonPressed:
			if (this->mousePosWindow.x >= 257 && this->mousePosWindow.x <= 537 && this->mousePosWindow.y >= 690 && this->mousePosWindow.y <= 770) {
				this->state = GameState::MAIN_MENU;
			}
			break;
		}
	}
}
GameState HelpPanel::returnGameState() {
	return this->state;
}
void HelpPanel::setState(GameState sentState) {
	this->state = sentState;
}