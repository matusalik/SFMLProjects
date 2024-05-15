#include "HelpPanel.h"
HelpPanel::HelpPanel() {
	this->initButtons();
}
HelpPanel::~HelpPanel() {

}
void HelpPanel::initButtons() {
	this->button1.setPosition(50, 50);
	this->button1.setSize(sf::Vector2f(100.f, 50.f));
	this->button1.setFillColor(sf::Color::Green);
}
void HelpPanel::draw(sf::RenderWindow*& window) {
	window->draw(this->button1);
}
void HelpPanel::update(sf::RenderWindow* window) {

}
void HelpPanel::pollEvents(sf::RenderWindow*& window) {
	while (window->pollEvent(this->ev)) {
		switch (this->ev.type) {
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::D) {
				this->button1.setPosition(this->button1.getPosition().x + 3, this->button1.getPosition().y);
			}
			break;
		}
	}
}
GameState HelpPanel::returnGameState() {
	return this->state;
}