#ifndef PLAYERSTATS_HPP
#define PLAYERSTATS_HPP

#include <vector>
#include <map>
#include <string>
#include <ctime>
#include "GameSession.hpp"
#include "GameResult.hpp"
//#include "GameSpecificStats.hpp"

class PlayerStats {
private:
    int totalGamesPlayed;                           // Total games played by the player
    double totalWinnings;                           // Total amount won by the player
    double totalLosses;                             // Total amount lost by the player
    double highestWin;                              // Highest win in a single game
    double biggestLoss;                             // Biggest loss in a single game
    std::map<std::string, int> gamesPlayedByType;   // Count of games played by type (e.g., Blackjack, Roulette)
    std::vector<GameSession> recentSessions;        // Recent game sessions
    double winRate;                                 // Win rate across all games
    double averageBetSize;                          // Average bet size
    time_t lastPlayedDate;                          // Timestamp of the last game played

    // Resets the statistics (protected for controlled access by subclasses)
    void resetStats();

public:
    // Constructor
    PlayerStats();

    // Updates the stats based on a game result
    void updateStats(const GameResult& result);

    // Calculates and returns the overall win rate
    double calculateWinRate() const;

    // Retrieves game-specific statistics (e.g., Blackjack-specific or Roulette-specific stats)
    //GameSpecificStats getGameSpecificStats(const std::string& gameType) const;

    // Calculates and returns the average bet size
    double getAverageBetSize() const;

    // Returns the last time the player played
    time_t getPlayTime() const;

    // Adds a game session to recentSessions
    void addSession(const GameSession& session);

    // Destructor
    ~PlayerStats();
};

#endif // PLAYERSTATS_HPP
