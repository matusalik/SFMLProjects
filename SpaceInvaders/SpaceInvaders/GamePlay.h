#pragma once
#include<iostream>
#include<thread>
#include"Panel.h"
#include"Player.h"
#include"Leaderboard.h"
#include"GameState.h"
#include"Enemy.h"
#include"BasicEnemy.h"
#include"FastEnemy.h"
#include"TankEnemy.h"
#include"Bullet.h"
class GamePlay : public Panel
{
private:
	//Leaderboard
	Leaderboard leaderboard;

	//Player
	Player player;
	
	//Bullets
	std::vector<std::unique_ptr<Bullet>>bulletsVector;

	//Enemies
	std::vector<std::unique_ptr<Enemy>>enemiesVector;
	std::vector<std::unique_ptr<Enemy>> newEnemiesVector;

	//Textures
	sf::Texture GamePlayBackgroundTexture;
	sf::Texture PlayerTexture;

	//Sprites
	sf::Sprite GamePlayBackgroundSprite;
	sf::Sprite PlayerSprite;

	//Text and fonts
	sf::Text exitText;
	sf::Text restartText;
	sf::Text scoreText;
	sf::Font gamePlayFont;

	//Varaibles
	bool isPaused;
	bool shootingBuffer;
	bool isGameOver;
	bool clearVectors;
	bool isHighScore;
	int maxEnemies;
	int timer;
	int score;

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
	void initFont();
	void initText();
	void spawnNewEnemy();
	void updateEnemies();
	void updateBullets();
	void updateScore();
	void drawGameOverPanel(sf::RenderWindow*& window);

public:
	void draw(sf::RenderWindow*& window);
	void update(sf::RenderWindow* window);
	void pollEvents(sf::RenderWindow*& window);
	GameState returnGameState();
	void setState(GameState sentState);
	void updateMousePosWindow(sf::RenderWindow* window);
	void setDifficulty(GameDifficulty sent);
	GamePlay(const GameDifficulty& sent, const Player& sentPlayer);
};

