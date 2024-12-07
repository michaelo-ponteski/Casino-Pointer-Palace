#include "../include/PlayerStats.hpp"
#include <iostream>
#include <fstream>
#include "../include/nlohmann/json.hpp"

// Constructor
PlayerStats::PlayerStats(std::string name, bool existingPlayer) {
    playerName = name;
    if (existingPlayer) {
        loadFromFile();
    } else {
        resetStats();
    }
}

// Destructor
PlayerStats::~PlayerStats() {
    saveToFile();
}

// Resets the statistics
void PlayerStats::resetStats() {
    totalGamesPlayed = 0;
    totalWinnings = 0.0;
    totalLosses = 0.0;
    highestWin = 0.0;
    biggestLoss = 0.0;
    lastPlayedDate = std::time(nullptr);
    rouletteStats.resetStats();
}

// Save to file
void PlayerStats::saveToFile() const {
    std::ifstream inFile("../data/player_stats.json");
    nlohmann::json j;
    if (inFile.is_open()) {
        inFile >> j;
        inFile.close();
    }

    bool playerFound = false;
    for (auto& player : j) {
        if (player["playerName"] == playerName) {
            player["stats"] = toJson();
            playerFound = true;
            break;
        }
    }

    if (!playerFound) {
        j.push_back({{"playerName", playerName}, {"stats", toJson()}});
    }

    std::ofstream outFile("../data/player_stats.json");
    if (outFile.is_open()) {
        outFile << j.dump(4);
        outFile.close();
    }
}

// Load from file
void PlayerStats::loadFromFile() {
    std::ifstream file("../data/player_stats.json");
    if (file.is_open()) {
        nlohmann::json j;
        file >> j;
        file.close();

        for (const auto& player : j) {
            if (player["playerName"] == playerName) {
                fromJson(player["stats"]);
                return;
            }
        }
    }
    resetStats(); // If player not found, reset stats
}

// Serialize PlayerStats object to JSON
nlohmann::json PlayerStats::toJson() const {
    return {
        {"totalGamesPlayed", totalGamesPlayed},
        {"totalWinnings", totalWinnings},
        {"totalLosses", totalLosses},
        {"highestWin", highestWin},
        {"biggestLoss", biggestLoss},
        {"lastPlayedDate", lastPlayedDate},
        {"rouletteStats", rouletteStats.toJson()}
    };
}

// Deserialize PlayerStats object from JSON
void PlayerStats::fromJson(const nlohmann::json& j) {
    totalGamesPlayed = j.at("totalGamesPlayed").get<int>();
    totalWinnings = j.at("totalWinnings").get<double>();
    totalLosses = j.at("totalLosses").get<double>();
    highestWin = j.at("highestWin").get<double>();
    biggestLoss = j.at("biggestLoss").get<double>();
    lastPlayedDate = j.at("lastPlayedDate").get<time_t>();
    rouletteStats.fromJson(j.at("rouletteStats"));
}

// Updates player stats based on the game result
void PlayerStats::updateStats(double amountWon) {
    totalGamesPlayed++;
    if (amountWon > 0) {
        totalWinnings += amountWon;
        if (amountWon > highestWin) {
            highestWin = amountWon;
        }
    } else {
        totalLosses += -amountWon;
        if (-amountWon > biggestLoss) {
            biggestLoss = -amountWon;
        }
    }
    lastPlayedDate = std::time(nullptr);
}

// Print overall stats
void PlayerStats::printOverallStats() const {
    std::cout << "Player Name: " << playerName << std::endl;
    std::cout << "Total Games Played: " << totalGamesPlayed << std::endl;
    std::cout << "Total Winnings: " << totalWinnings << std::endl;
    std::cout << "Total Losses: " << totalLosses << std::endl;
    std::cout << "Highest Win: " << highestWin << std::endl;
    std::cout << "Biggest Loss: " << biggestLoss << std::endl;
    std::cout << "Last Played Date: " << std::ctime(&lastPlayedDate);
}