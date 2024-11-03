// #ifndef ROULETTEGAME_HPP
// #define ROULETTEGAME_HPP

// #include <vector>
// #include <string>
// #include "Game.hpp"
// #include "Bet.hpp"
// #include "RouletteWheel.hpp"

// class RouletteGame : public Game {
// private:
//     int winningNumber;                     // The winning number for each spin
//     std::vector<BetType> betTypes;         // Types of bets available (e.g., number, color, even/odd)
//     RouletteWheel wheel;                   // The roulette wheel for generating the winning number

//     // Calculates the payout based on the type of bet placed
//     double calculatePayout(const Bet& bet) const;

// public:
//     // Constructor
//     RouletteGame(double minBetAmount, double maxBetAmount);

//     // Spins the wheel and returns the winning number
//     int spinWheel();

//     // Place a bet on a specific number, returns true if the bet is accepted
//     bool placeBetOnNumber(Player* player, int number);

//     // Place a bet on a color (e.g., red or black), returns true if the bet is accepted
//     bool placeBetOnColor(Player* player, const std::string& color);

//     // Starts the Roulette game, overriding startGame from Game
//     void startGame() override;

//     // Ends the Roulette game, overriding endGame from Game
//     void endGame() override;

//     // Destructor
//     ~RouletteGame();
// };

// #endif // ROULETTEGAME_HPP
