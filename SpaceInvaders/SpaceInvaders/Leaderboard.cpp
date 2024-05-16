#include "Leaderboard.h"
Leaderboard::Leaderboard() {
	std::filesystem::path directory;
	std::ifstream directoryFile("Data/dir.txt");
	if (directoryFile.is_open()) {
		std::string line;
		while (std::getline(directoryFile, line)) {
			directory = line;
			if (std::filesystem::exists(line)) {
				break;
			}
		}
		directoryFile.close();
	}
	std::cout << directory << std::endl;
	std::filesystem::path filepath = directory / "database.txt";
	std::cout << filepath << std::endl;
	std::ifstream file("filepath");
	if (file.is_open()) {
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
std::filesystem::path Leaderboard::findFile(const std::string& name) {
	std::filesystem::path mainpath;
	return mainpath;
}
std::vector<Player>Leaderboard::getDatabase() {
	return this->database;
}