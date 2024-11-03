#ifndef GAMESESSION_HPP
#define GAMESESSION_HPP

#include <string>
#include <vector>
#include <ctime>
#include "Bet.hpp"

class GameSession {
private:
    time_t startTime;                   // Start time of the game session
    time_t endTime;                     // End time of the game session
    std::string gameType;               // Type of game played in this session (e.g., "Blackjack", "Roulette")
    double sessionBalance;              // Player's balance change during the session
    int handsPlayed;                    // Number of hands played (for card games)
    std::vector<Bet> sessionBets;       // List of bets placed during this session

public:
    // Constructor
    GameSession(const std::string& type);

    // Sets the start time of the session
    void startSession();

    // Sets the end time of the session
    void endSession();

    // Adds a bet to the session's list of bets
    void addBet(const Bet& bet);

    // Sets the session balance after game play
    void setSessionBalance(double balanceChange);

    // Increments the number of hands played
    void incrementHandsPlayed();

    // Getters
    time_t getStartTime() const;
    time_t getEndTime() const;
    std::string getGameType() const;
    double getSessionBalance() const;
    int getHandsPlayed() const;
    std::vector<Bet> getSessionBets() const;

    // Destructor
    ~GameSession();
};

#endif // GAMESESSION_HPP
