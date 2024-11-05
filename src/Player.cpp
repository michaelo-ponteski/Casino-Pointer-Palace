#include "../include/Player.hpp"
#include "../src/Bet.cpp"
#include <iostream>
#include <string>

// Constructor
Player::Player(int id, const std::string& playerName, double initialBalance)
    : playerId(id), name(playerName), balance(initialBalance) {
    std::cout << "Player " << name << " created." << std::endl;
}

// Places a bet of the specified amount, returns true if successful
bool Player::placeBet(double amount) {
    if (amount > balance) {
        std::cout << "Insufficient balance to place bet." << std::endl;
        return false;
    }
    Bet* newBet = new Bet(amount);
    bets.push_back(newBet);
    balance -= amount;
    std::cout << name << " placed a bet of $" << amount << "." << std::endl;
    return true;
}

// Adds a specified amount to the player's balance
void Player::addBalance(double amount) {
    balance += amount;
    std::cout << name << " added $" << amount << " to their balance." << std::endl;
}

// Returns the current balance of the player
double Player::getBalance() const {
    return balance;
}

// Getter for player ID
int Player::getPlayerId() const {
    return playerId;
}

// Getter for player name
std::string Player::getName() const {
    return name;
}

// Updates player stats based on the game result
// void Player::updateStats(GameResult result) {
//     stats.updateStats(result);
// }

// Destructor
Player::~Player() {
    for (Bet* bet : bets) {
        delete bet;
    }
    std::cout << "Player " << name << " destroyed." << std::endl;
}