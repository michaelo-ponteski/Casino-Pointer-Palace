#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include "../include/PlayerStats.hpp"


class Player {
private:
    int playerId;                   // Unique identifier for the player
    std::string name;               // Name of the player
    double balance;                 // Player's balance

public:
    PlayerStats stats;              // Player statistics

    // Constructor
    Player(int id, const std::string& playerName, double initialBalance, bool existingPlayer = false);

    // Places a bet of the specified amount
    void placeBet(double amount);

    // Adds a specified amount to the player's balance
    void addBalance(double amount);

    // Returns the current balance of the player
    double getBalance() const;

    // Getter for player ID
    int getPlayerId() const;

    // Getter for player name
    std::string getName() const;

    // Destructor
    ~Player();
};

#endif // PLAYER_HPP
