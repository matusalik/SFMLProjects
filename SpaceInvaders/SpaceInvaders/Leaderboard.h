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
	std::filesystem::path findFile(const std::string& name);
public:
	Leaderboard();
	std::vector<Player>getDatabase();
};

