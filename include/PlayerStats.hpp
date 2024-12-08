#ifndef PLAYERSTATS_HPP
#define PLAYERSTATS_HPP

#include <vector>
#include <map>
#include <string>
#include "../include/nlohmann/json.hpp"
#include <ctime>
#include "../include/RouletteStats.hpp"
#include "../include/BlackjackStats.hpp"

class PlayerStats {
private:
    std::string playerName;                         // Name of the player
    int totalGamesPlayed;                           // Total games played by the player
    double totalWinnings;                           // Total amount won by the player
    double totalLosses;                             // Total amount lost by the player
    double highestWin;                              // Highest win in a single game
    double biggestLoss;                             // Biggest loss in a single game
    time_t lastPlayedDate;                          // Timestamp of the last game played


    // Resets the statistics (protected for controlled access by subclasses)
    void resetStats();

    // Load from file
    void loadFromFile();

    // Serialize PlayerStats object to JSON
    nlohmann::json toJson() const;

    // Deserialize PlayerStats object from JSON
    void fromJson(const nlohmann::json& j);
public:
    // game specific stats
    RouletteStats rouletteStats;                    // Roulette specific stats
    BlackjackStats blackjackStats;                  // Blackjack specific stats
    
    // Constructor
    PlayerStats(std::string name, bool existingPlayer = false);

    // Updates player stats based on the game result
    void updateStats(double amountWon);

    // Print overall stats
    void printOverallStats() const;

    // Save to file
    void saveToFile() const;
    
    // Destructor
    ~PlayerStats();
};

#endif // PLAYERSTATS_HPP
