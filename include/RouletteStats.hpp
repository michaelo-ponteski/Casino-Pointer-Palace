#ifndef ROULETTESTATS_HPP
#define ROULETTESTATS_HPP

#include <string>
#include "../include/nlohmann/json.hpp"

class RouletteStats {
public:
    int totalSpins;                 // Total spins of the roulette wheel
    int wins;                       // Total wins
    int losses;                     // Total losses
    std::string favouriteColor;     // Favourite color bet

    // Serialize PlayerStats object to JSON
    nlohmann::json toJson() const;

    // Deserialize PlayerStats object from JSON
    void fromJson(const nlohmann::json& j);

    // Reset the statistics
    void resetStats();

    // Update the statistics 
    void updateStats(bool win, std::string color);

    // Print specific stats
    void printSpecificStats() const;

    // Constructor
    RouletteStats();

    // Destructor
    ~RouletteStats();
};

#endif // ROULETTESTATS_HPP