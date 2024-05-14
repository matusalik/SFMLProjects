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
void HelpPanel::update() {
	this->button1.setPosition(this->a, this->a);
	this->a = this->a + 1;
}