#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>
#include "Player.hpp"

class Game {
protected:
    std::string gameName;                 // Name of the game
    double minBet;                        // Minimum bet allowed in the game
    double maxBet;                        // Maximum bet allowed in the game
    Player* gamePlayer;                   // Pointer to the player who is in the game

    // Validates if a given bet amount is within the acceptable bet range
    bool validateBet(double amount) const;

public:
    // Constructor
    Game(const std::string& name, double minBetAmount, double maxBetAmount);

    // Starts the game; virtual for possible override by derived classes
    virtual void startGame() = 0;

    // Ends the game; virtual for possible override by derived classes
    virtual void endGame() = 0;

    // Places a bet for a given player; returns true if the bet is valid and accepted
    bool placeBet(Player* player, double amount);

    // Plays a round of the game; virtual for possible override by derived classes
    virtual void playRound() = 0;

    // Getter for game name
    std::string getGameName() const;

    // Getter for minimum bet
    double getMinBet() const;

    // Getter for maximum bet
    double getMaxBet() const;

    // Destructor
    virtual ~Game();
};

#endif // GAME_HPP
