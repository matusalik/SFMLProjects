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
void Leaderboard::updateDatabase(Player& player) {
	std::ofstream ofs("Data\\database.txt", std::ofstream::trunc);
	if (ofs.is_open()) {
		if (isPlayerInBase(player)) {
			for (auto& i : this->database) {
				if (i.getNick() == player.getNick()) {
					i.setScore(player.getScore());
				}
			}
		}
		else {
			this->database.push_back(player);
		}
		for (int i = 0; i < this->database.size(); i++) {
			std::string tempPlayer;
			std::string nickStr = this->database[i].getNick();
			std::string scoreStr = std::to_string(this->database[i].getScore());
			tempPlayer = nickStr + " " + scoreStr + "\n";
			ofs << tempPlayer;
		}
		ofs.close();
	}
	else {
		std::cout << "Couldn't open the file!" << std::endl;
	}
}
bool Leaderboard::isPlayerInBase(Player& player) {
	for (auto i : this->database) {
		if (i.getNick() == player.getNick()) {
			return true;
		}
	}
	return false;
}