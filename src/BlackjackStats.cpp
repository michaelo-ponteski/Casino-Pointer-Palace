#include "../include/BlackjackStats.hpp"
#include <iostream>

// Constructor
BlackjackStats::BlackjackStats() {
    resetStats();
}

// Destructor
BlackjackStats::~BlackjackStats() {}

// Serialize PlayerStats object to JSON
nlohmann::json BlackjackStats::toJson() const {
    return {
        {"totalHands", totalHands},
        {"wins", wins},
        {"losses", losses},
        {"pushes", pushes},
        {"blackjacks", blackjacks},
        {"busts", busts}
    };
}

// Deserialize PlayerStats object from JSON
void BlackjackStats::fromJson(const nlohmann::json& j) {
    totalHands = j.at("totalHands").get<int>();
    wins = j.at("wins").get<int>();
    losses = j.at("losses").get<int>();
    pushes = j.at("pushes").get<int>();
    blackjacks = j.at("blackjacks").get<int>();
    busts = j.at("busts").get<int>();
}

// Reset the statistics
void BlackjackStats::resetStats() {
    totalHands = 0;
    wins = 0;
    losses = 0;
    pushes = 0;
    blackjacks = 0;
    busts = 0;
}

// Update the statistics
void BlackjackStats::updateStats(bool win, bool push, bool blackjack, bool bust) {
    totalHands++;
    if (win) {
        wins++;
    } else if (push) {
        pushes++;
    } else if (blackjack) {
        blackjacks++;
    } else if (bust) {
        busts++;
    } else {
        losses++;
    }
}

// Print specific stats
void BlackjackStats::printSpecificStats() const {
    std::cout << "Blackjack specific stats:" << std::endl;
    std::cout << "Total hands: " << totalHands << std::endl;
    std::cout << "Wins: " << wins << std::endl;
    std::cout << "Losses: " << losses << std::endl;
    std::cout << "Pushes: " << pushes << std::endl;
    std::cout << "Blackjacks: " << blackjacks << std::endl;
    std::cout << "Busts: " << busts << std::endl;
}

