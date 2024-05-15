#include "Leaderboard.h"
Leaderboard::Leaderboard() {
	std::ifstream file("Data/database.txt");
	if (file.is_open()) {
		std::cout << "Found file!" << std::endl;
		std::string line;
		while (std::getline(file, line)) {
			std::istringstream iss(line);
			std::string nick;
			int score;
			if (iss >> nick >> score) {
				Player temp(nick);
				temp.setScore(score);
				this->database.push_back(temp);
			}
		}
	}
	else {
		std::cout << "Couldn't find database file!" << std::endl;
	}
	for (auto i : this->database) {
		std::cout << i.getNick() << " ";
		std::cout << i.getScore() << std::endl;
	}
}
std::vector<Player>Leaderboard::getDatabase() {
	return this->database;
}