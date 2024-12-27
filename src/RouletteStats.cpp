#include "../include/RouletteStats.hpp"
#include <iostream>
#include <stdexcept>

// Constructor
RouletteStats::RouletteStats() {
    resetStats();
}

// Destructor
RouletteStats::~RouletteStats() {}

// Serialize PlayerStats object to JSON
nlohmann::json RouletteStats::toJson() const {
    return {
        {"totalSpins", totalSpins},
        {"wins", wins},
        {"losses", losses},
        {"favouriteColor", favouriteColor}
    };
}

// Deserialize PlayerStats object from JSON
void RouletteStats::fromJson(const nlohmann::json& j) {
    try {
        totalSpins = j.at("totalSpins").get<int>();
        wins = j.at("wins").get<int>();
        losses = j.at("losses").get<int>();
        favouriteColor = j.at("favouriteColor").get<std::string>();
    } catch (const nlohmann::json::exception& e) {
        std::cerr << "Error deserializing JSON: " << e.what() << std::endl;
        throw; // rethrow the exception after logging it
    }
}

// Reset the statistics
void RouletteStats::resetStats() {
    totalSpins = 0;
    wins = 0;
    losses = 0;
    favouriteColor = "None";
}

// Update the statistics
void RouletteStats::updateStats(bool win, std::string color) {
    totalSpins++;
    if (win) {
        wins++;
    } else {
        losses++;
    }
    if (color != "None") {
        favouriteColor = color;
    }
}

// Print specific stats
void RouletteStats::printSpecificStats() const {
    std::cout << "Roulette specific stats:" << std::endl;
    std::cout << "Total spins: " << totalSpins << std::endl;
    std::cout << "Wins: " << wins << std::endl;
    std::cout << "Losses: " << losses << std::endl;
    std::cout << "Favourite color: " << favouriteColor << std::endl;
}