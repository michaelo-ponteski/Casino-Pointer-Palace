#ifndef BET_HPP
#define BET_HPP

#include <string>
#include "Player.hpp"

enum class BetType {
    NUMBER,     // Bet on a specific number
    COLOR,      // Bet on a color (e.g., red or black)
    EVEN_ODD,   // Bet on even or odd
    PLAYER,     // Bet on the player's hand in Baccarat
    BANKER,     // Bet on the banker's hand in Baccarat
    TIE         // Bet on a tie in Baccarat
    // Add more bet types as needed
};

class Bet {
private:
    double amount;        // Amount of the bet
    BetType type;        // Type of the bet
    Player* player;      // Pointer to the player who placed the bet
    bool isWon;          // Status of the bet (true if won, false otherwise)

public:
    // Constructor
    Bet(double betAmount, BetType betType, Player* betPlayer);

    // Calculates and returns the payout for the bet based on the game rules
    double calculatePayout() const;

    // Getters
    double getAmount() const;
    BetType getType() const;
    Player* getPlayer() const;
    bool getIsWon() const;

    // Sets the status of the bet (won or lost)
    void setIsWon(bool status);

    // Destructor
    ~Bet();
};

#endif // BET_HPP
