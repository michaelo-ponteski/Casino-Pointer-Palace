#ifndef ROULETTEGAME_HPP
#define ROULETTEGAME_HPP

#include "Game.hpp"
#include <string>
#include <vector>

class RouletteGame : public Game {
public:
    enum BetType {
        RED,
        BLACK,
        ODD,
        EVEN,
        HIGH,
        LOW,
        STRAIGHT_UP,
        STREET
    };

    struct Bet {
        BetType type;
        int amount;
        int number; // Only used for STRAIGHT_UP and STREET bets
    };

    RouletteGame(Player* player);
    virtual ~RouletteGame();

    void placeBet();
    void spinWheel();
    void resolveBets();
    void playRound();

    void startGame() override;
    void endGame() override;

private:
    std::vector<Bet> bets;
    int winningNumber;
    std::string winningColor;
    bool isOdd(int number);
    bool isHigh(int number);
    std::string getColor(int number);
};

#endif // ROULETTEGAME_HPP
