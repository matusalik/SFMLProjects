#pragma once
#include<string>
class Player
{
private:
	std::string nick;
	int score;
public:
	Player();
	std::string getNick();
	int getScore();
	void setNick(std::string sentNick);
	void setScore(int sentScore);
};

