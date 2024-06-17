#include"Player.h"
#include<vector>
#include<filesystem>
#include<ranges>
#include<functional>
#include<fstream>
#include<sstream>
#include<iostream>
export module FileManager;
export namespace FileManager {
	std::vector<Player>downloadData() {
		std::vector<Player>database;
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
						database.push_back(temp);
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
		return database;
	};
	void uploadData(std::vector<Player>database) {
		std::filesystem::path directory = std::filesystem::current_path();
		std::filesystem::path filepath = directory / "Data\\database.txt";
		if (std::filesystem::exists(filepath)) {
			std::ofstream ofs(filepath, std::ofstream::trunc);
			if (ofs.is_open()) {
				for (int i = 0; i < database.size(); i++) {
					std::string tempPlayer;
					std::string nickStr = database[i].getNick();
					std::string scoreStr = std::to_string(database[i].getScore());
					tempPlayer = nickStr + " " + scoreStr + "\n";
					ofs << tempPlayer;
				}
				ofs.close();
			}
			else {
				std::cout << "Couldn't open the file!" << std::endl;
			}
		}
		else {
			std::cout << "Couldn't find the database file!" << std::endl;
		}
	};
	std::vector<Player>sortDatabase(std::vector<Player>sent) {
		std::ranges::sort(sent,std::ranges::greater{}, &Player::getScore);
		return sent;
	};
}