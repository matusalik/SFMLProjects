#include "Leaderboard.h"
Leaderboard::Leaderboard() {
	std::filesystem::path directory = std::filesystem::current_path();
	std::filesystem::path filepath = directory / "Data\\database.txt";
	if (std::filesystem::exists(filepath)) {
		std::ifstream file(filepath.string());
		if (file.is_open()) {
			std::string line;
			while (std::getline(file, line)) {
				std::istringstream iss(line);
				std::string nick;
				int score;
				if (iss >> nick >> score) {
					Player temp;
					temp.setNick(nick);
					temp.setScore(score);
					this->database.push_back(temp);
				}
			}
		}
		else {
			std::cout << "Couldn't open the database file!" << std::endl;
		}
	}
	else {
		std::cout << "Couldn't find the database file!" << std::endl;
	}
}
std::filesystem::path Leaderboard::findFile(const std::string& name) {
	std::filesystem::path mainpath;
	return mainpath;
}
std::vector<Player>Leaderboard::getDatabase() {
	return this->database;
}