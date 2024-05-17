#include "Leaderboard.h"
Leaderboard::Leaderboard() {
	//Using ifstream to serch through the dir.txt text file with possible directories of Data folder
	//If you are a new user of this game you should add path to mentioned text file
	std::filesystem::path directory;
	std::ifstream directoryFile("Data/dir.txt");
	if (directoryFile.is_open()) {
		std::string line;
		while (std::getline(directoryFile, line)) {
			directory = line;
			if (std::filesystem::exists(line)) {
				std::filesystem::path filepath = directory / "database.txt";
				std::ifstream file(filepath.string());
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
			}
		}
		directoryFile.close();
	}
	else {
		std::cout << "Couldn't find dir file!" << std::endl;
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