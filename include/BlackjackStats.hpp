#ifndef BLACKJACKSTATS_HPP
#define BLACKJACKSTATS_HPP

#include <string>
#include "../include/nlohmann/json.hpp"

class BlackjackStats {
public:
    int totalHands;                 // Total hands played
    int wins;                       // Total wins
    int losses;                     // Total losses
    int pushes;                     // Total pushes
    int blackjacks;                 // Total blackjacks
    int busts;                      // Total busts

    // Serialize PlayerStats object to JSON
    nlohmann::json toJson() const;

    // Deserialize PlayerStats object from JSON
    void fromJson(const nlohmann::json& j);

    // Reset the statistics
    void resetStats();

    // Update the statistics
    void updateStats(bool win, bool push, bool blackjack, bool bust);

    // Print specific stats
    void printSpecificStats() const;

    // Constructor
    BlackjackStats();

    // Destructor
    ~BlackjackStats();
};

#endif // BLACKJACKSTATS_HPP