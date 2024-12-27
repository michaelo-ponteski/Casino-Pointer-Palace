#include "../include/Game.hpp"
#include "../include/Player.hpp"
#include <iostream>
#include <string>
#include <vector>

// Constructor
Game::Game(const std::string& name, double minBetAmount, double maxBetAmount) : gameName(name), minBet(minBetAmount), maxBet(maxBetAmount) {}

// Starts the game; virtual for possible override by derived classes
void Game::startGame() {
    std::cout << "Game " << gameName << " started." << std::endl;
}

// Ends the game; virtual for possible override by derived classes
void Game::endGame() {
    std::cout << "Game " << gameName << " ended." << std::endl;
}

// Validates if a given bet amount is within the acceptable bet range
bool Game::validateBet(double amount) const {
    return amount >= minBet && amount <= maxBet;
}

// Getter for game name
std::string Game::getGameName() const {
    return gameName;
}

// Getter for minimum bet
double Game::getMinBet() const {
    return minBet;
}

// Getter for maximum bet
double Game::getMaxBet() const {
    return maxBet;
}

// Destructor
Game::~Game() {
}