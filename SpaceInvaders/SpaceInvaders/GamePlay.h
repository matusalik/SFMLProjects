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
	std::unique_ptr<Enemy> e = std::make_unique<BasicEnemy>(Direction::EAST);
	std::vector<std::unique_ptr<Enemy>>enemiesVector;

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
	void initEnemies();
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

