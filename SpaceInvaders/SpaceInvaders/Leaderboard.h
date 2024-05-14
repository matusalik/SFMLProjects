#pragma once
#include<vector>
#include<filesystem>
#include<iostream>
#include"Player.h"
class Leaderboard
{
private:
	std::vector<Player>database;
public:
	Leaderboard();
	std::vector<Player>getDatabase();
};

