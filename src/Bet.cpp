#include "../include/Bet.hpp"
#include <iostream>

// Constructor
Bet::Bet(double betAmount, BetType betType, Player* betPlayer)
    : amount(betAmount), type(betType), player(betPlayer), isWon(false) {
    std::cout << "Bet of $" << amount << " placed by " << player->getName() << " created." << std::endl;
}

// Calculates and returns the payout for the bet based on the game rules
double Bet::calculatePayout() const {
    // Placeholder calculation
    return amount * 2.0;
}

// Getters
double Bet::getAmount() const {
    return amount;
}

BetType Bet::getType() const {
    return type;
}

Player* Bet::getPlayer() const {
    return player;
}

bool Bet::getIsWon() const {
    return isWon;
}

// Sets the status of the bet (won or lost)
void Bet::setIsWon(bool status) {
    isWon = status;
}

// Destructor
Bet::~Bet() {
    std::cout << "Bet of $" << amount << " placed by " << player->getName() << " destroyed." << std::endl;
}