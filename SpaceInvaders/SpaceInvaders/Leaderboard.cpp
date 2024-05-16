#include "Leaderboard.h"
Leaderboard::Leaderboard() {
	std::filesystem::path directory;
	std::ifstream directoriesFile("Data\\dir.txt");
	if (directoriesFile.is_open()) {
		std::string line;
		while (std::getline(directoriesFile, line)) {
			std::cout << line << std::endl;
			directory = line;
			if (std::filesystem::exists(directory)) {
				std::cout << "found directory!" << std::endl;
			}
			return;
		}
	}
	else {
		std::cout << "Couldn't find directories file!" << std::endl;
	}
	/*if (file.is_open()) {
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
	}*/
}
std::vector<Player>Leaderboard::getDatabase() {
	return this->database;
}