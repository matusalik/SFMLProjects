#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include<filesystem>
#include"Player.h"

class Leaderboard
{
private:
	std::vector<Player>database;
public:
	Leaderboard();
	std::vector<Player>getDatabase();
};

