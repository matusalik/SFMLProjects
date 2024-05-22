#pragma once
#include<iostream>
#include"Panel.h"
#include"GameState.h"
#include"Enemy.h"
#include"BasicEnemy.h"
class GamePlay : public Panel
{
private:
	//Enemies
	Enemy* e = new BasicEnemy(Direction::EAST, 50, 50);

	//Textures
	sf::Texture GamePlayBackgroundTexture;
	sf::Texture PlayerTexture;

	//Sprites
	sf::Sprite GamePlayBackgroundSprite;
	sf::Sprite PlayerSprite;

	//Varaibles
	bool isPaused;
	
	//Event
	sf::Event ev;

	//Game State
	GameState state;

	//Mose Position
	sf::Vector2i mousePosWindow;

	//Private functions
	void initPlayer();
	void initVariables();
	void initEnum();
	void initTextures();
	void initSprites();

public:
	void draw(sf::RenderWindow*& window);
	void update(sf::RenderWindow* window);
	void pollEvents(sf::RenderWindow*& window);
	GameState returnGameState();
	void setState(GameState sentState);
	void updateMousePosWindow(sf::RenderWindow* window);
	GamePlay();
};

