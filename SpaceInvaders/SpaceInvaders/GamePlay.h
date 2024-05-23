#pragma once
#include<iostream>
#include<thread>
#include"Panel.h"
#include"GameState.h"
#include"Enemy.h"
#include"BasicEnemy.h"
#include"FastEnemy.h"
class GamePlay : public Panel
{
private:
	//Enemies
	std::vector<std::unique_ptr<Enemy>>enemiesVector;
	std::vector<std::unique_ptr<Enemy>> newEnemiesVector;

	//Textures
	sf::Texture GamePlayBackgroundTexture;
	sf::Texture PlayerTexture;

	//Sprites
	sf::Sprite GamePlayBackgroundSprite;
	sf::Sprite PlayerSprite;

	//Varaibles
	bool isPaused;
	int maxEnemies;
	
	//Event
	sf::Event ev;

	//Game State
	GameState state;

	//Game Difficulty
	GameDifficulty difficulty;

	//Mose Position
	sf::Vector2i mousePosWindow;

	//Private functions
	void initEnemies();
	void initPlayer();
	void initVariables();
	void initEnum();
	void initTextures();
	void initSprites();
	void spawnNewEnemy();

public:
	void draw(sf::RenderWindow*& window);
	void update(sf::RenderWindow* window);
	void pollEvents(sf::RenderWindow*& window);
	GameState returnGameState();
	void setState(GameState sentState);
	void updateMousePosWindow(sf::RenderWindow* window);
	void setDifficulty(GameDifficulty sent);
	GamePlay(const GameDifficulty& sent);
};

