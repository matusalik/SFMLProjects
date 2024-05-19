#include "LeaderboardPanel.h"

LeaderboardPanel::LeaderboardPanel() {
	this->initEnum();
	this->initFont();
	this->initTextures();
	this->initSprites();
	this->initButtons();
	this->initText();
}
void LeaderboardPanel::initTextures(){
	if (!this->leaderboardPanelBackgroundTexture.loadFromFile("backgrounds/LeaderboardPanelBackground.png")) {
		std::cout << "Couldn't load LeaderboardPanelBackground!" << std::endl;
	}
}
void LeaderboardPanel::initSprites() {
	this->leaderboardPanelBackgroundSprite.setTexture(this->leaderboardPanelBackgroundTexture);
}
void LeaderboardPanel::initEnum() {
	this->state = GameState::LEADERBOARD;
}
void LeaderboardPanel::initButtons(){
	this->exitButton.setPosition(257.f, 680.f);
	this->exitButton.setSize(sf::Vector2f(280.f, 80.f));
	this->exitButton.setFillColor(sf::Color(138, 138, 138));
	this->exitButton.setOutlineColor(sf::Color(105, 105, 105));
	this->exitButton.setOutlineThickness(10.f);
}
void LeaderboardPanel::initText() {
	this->exitText.setFont(this->leaderboardPanelFont);
	this->exitText.setPosition(290.f, 705.f);
	this->exitText.setString("GO BACK");
	this->exitText.setFillColor(sf::Color::Black);
	this->exitText.setOutlineColor(sf::Color(100, 255, 43));
}
void LeaderboardPanel::initFont() {
	if (!this->leaderboardPanelFont.loadFromFile("fonts/PressStart2P-vaV7.ttf")) {
		std::cout << "Couldn't load the font" << std::endl;
	}
}
void LeaderboardPanel::draw(sf::RenderWindow*& window) {
	window->draw(this->leaderboardPanelBackgroundSprite);
	window->draw(this->exitButton);
	window->draw(this->exitText);
	this->checkLeaderboard(window);
}
void LeaderboardPanel::checkLeaderboard(sf::RenderWindow*& window) {
	Leaderboard leaderboard;
	std::vector<Player>temp = leaderboard.getDatabase();
	int size = temp.size();
	if (size <= 10) {
		for (int i = 0; i < size; i++) {
			std::string output;
			std::string nick = temp[i].getNick();
			int score = temp[i].getScore();
			output = nick + "      " + std::to_string(score) +"\n";
			sf::Text temptext;
			temptext.setFont(this->leaderboardPanelFont);
			temptext.setPosition(40.f, (40.f * i) + 40.f);
			temptext.setString(output);
			temptext.setFillColor(sf::Color::Black);
			window->draw(temptext);
		}
	}
	else {
		for (int i = 0; i < 10; i++) {
			std::string output;
			std::string nick = temp[i].getNick();
			int score = temp[i].getScore();
			output = nick + "      " + std::to_string(score) + "\n";
			sf::Text temptext;
			temptext.setFont(this->leaderboardPanelFont);
			temptext.setPosition(40.f, (40.f * i) + 40.f);
			temptext.setString(output);
			temptext.setFillColor(sf::Color::Black);
			window->draw(temptext);
		}
	}
}
void LeaderboardPanel::pollEvents(sf::RenderWindow*& window) {
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
void LeaderboardPanel::update(sf::RenderWindow* window) {
	this->updateMousePosWindow(window);
	if (this->mousePosWindow.x >= 257 && this->mousePosWindow.x <= 537 && this->mousePosWindow.y >= 690 && this->mousePosWindow.y <= 770) {
		this->exitText.setOutlineThickness(5.f);
	}
	else {
		this->exitText.setOutlineThickness(0.f);
	}
}
GameState LeaderboardPanel::returnGameState() {
	return this->state;
}
void LeaderboardPanel::setState(GameState sentState) {
	this->state = sentState;
}
void LeaderboardPanel::updateMousePosWindow(sf::RenderWindow* window) {
	this->mousePosWindow = sf::Mouse::getPosition(*window);
}
