#include "Leaderboard.h"
Leaderboard::Leaderboard() {
	this->database = FileManager::downloadData();
	this->database = FileManager::sortDatabase(this->database);
}
std::filesystem::path Leaderboard::findFile(const std::string& name) {
	std::filesystem::path mainpath;
	return mainpath;
}
std::vector<Player>Leaderboard::getDatabase() {
	return this->database;
}
void Leaderboard::updateDatabase(Player& player) {
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
	FileManager::uploadData(this->database);
}
bool Leaderboard::isPlayerInBase(Player& player) {
	for (auto i : this->database) {
		if (i.getNick() == player.getNick()) {
			return true;
		}
	}
	return false;
}