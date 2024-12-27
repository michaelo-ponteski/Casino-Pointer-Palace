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
    blackjackStats.resetStats();
}

// Save to file
void PlayerStats::saveToFile() const {
    std::ifstream inFile("../data/player_stats.json");
    nlohmann::json j;
    if (inFile.is_open()) {
        try {
            inFile >> j;
        } catch (const std::exception& e) {
            std::cerr << "Error reading from file: " << e.what() << std::endl;
        }
        inFile.close();
    } else {
        std::cerr << "Could not open file for reading: ../data/player_stats.json" << std::endl;
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
        try {
            outFile << j.dump(4);
        } catch (const std::exception& e) {
            std::cerr << "Error writing to file: " << e.what() << std::endl;
        }
        outFile.close();
    } else {
        std::cerr << "Could not open file for writing: ../data/player_stats.json" << std::endl;
    }
}

// Load from file
void PlayerStats::loadFromFile() {
    std::ifstream file("../data/player_stats.json");
    if (file.is_open()) {
        nlohmann::json j;
        try {
            file >> j;
        } catch (const std::exception& e) {
            std::cerr << "Error reading from file: " << e.what() << std::endl;
            resetStats();
            return;
        }
        file.close();

        for (const auto& player : j) {
            if (player["playerName"] == playerName) {
                fromJson(player["stats"]);
                return;
            }
        }
    } else {
        std::cerr << "Could not open file for reading: ../data/player_stats.json" << std::endl;
    }
    resetStats(); // If player not found or file not opened, reset stats
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
        {"rouletteStats", rouletteStats.toJson()},
        {"blackjackStats", blackjackStats.toJson()}
    };
}

// Deserialize PlayerStats object from JSON
void PlayerStats::fromJson(const nlohmann::json& j) {
    try {
        totalGamesPlayed = j.at("totalGamesPlayed").get<int>();
        totalWinnings = j.at("totalWinnings").get<double>();
        totalLosses = j.at("totalLosses").get<double>();
        highestWin = j.at("highestWin").get<double>();
        biggestLoss = j.at("biggestLoss").get<double>();
        lastPlayedDate = j.at("lastPlayedDate").get<time_t>();
        rouletteStats.fromJson(j.at("rouletteStats"));
        blackjackStats.fromJson(j.at("blackjackStats"));
    } catch (const std::exception& e) {
        std::cerr << "Error parsing JSON: " << e.what() << std::endl;
        resetStats();
    }
}

// Updates player stats based on the game result
void PlayerStats::updateStats(double amountWon) {
    totalGamesPlayed++;
    if (amountWon > 0) {
        totalWinnings += amountWon;
        if (amountWon > highestWin) {
            highestWin = amountWon;
        }
    } else if (amountWon < 0) {
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