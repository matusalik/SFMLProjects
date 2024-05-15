#include "HelpPanel.h"
HelpPanel::HelpPanel() {
	this->initFonts();
	this->initButtons();
	this->initText();
}
HelpPanel::~HelpPanel() {

}
void HelpPanel::initButtons() {
	this->exitButton.setPosition(257.f, 690.f);
	this->exitButton.setSize(sf::Vector2f(280.f, 80.f));
	this->exitButton.setFillColor(sf::Color(138, 138, 138));
	this->exitButton.setOutlineColor(sf::Color(105, 105, 105));
	this->exitButton.setOutlineThickness(10.f);
}
void HelpPanel::initText() {
	this->exitText.setFont(this->helpPanelFont);
	this->exitText.setPosition(290.f, 720.f);
	this->exitText.setString("GO BACK");
	this->exitText.setFillColor(sf::Color::Black);
	this->exitText.setOutlineColor(sf::Color(100, 255, 43));
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
	window->draw(this->exitButton);
	window->draw(this->exitText);
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
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::D) {
				
			}
			break;
		}
	}
}
GameState HelpPanel::returnGameState() {
	return this->state;
}