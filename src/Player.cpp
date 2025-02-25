#include <Player.hpp>
#include <iostream>
#include <string>

// Constructor
Player::Player(int id, const std::string& playerName, double initialBalance, bool existingPlayer) : playerId(id), name(playerName), balance(initialBalance), stats(playerName, existingPlayer) {
}

// Places a bet of the specified amount
void Player::placeBet(double amount) {
    if (amount > balance) {
        std::cout << "Insufficient balance to place this bet." << std::endl;
    } else {
        balance -= amount;
    }
}

// Adds a specified amount to the player's balance
void Player::addBalance(double amount) {
    balance += amount;
    // std::cout << name << "'s balance is now $" << balance << "." << std::endl;
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

// Destructor
Player::~Player() {
    // std::cout << "Player " << name << " destroyed." << std::endl;
}