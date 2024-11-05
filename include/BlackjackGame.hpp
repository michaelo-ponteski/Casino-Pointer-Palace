#ifndef BLACKJACKGAME_HPP
#define BLACKJACKGAME_HPP

#include <vector>
#include "CardGame.hpp"
#include "Player.hpp"
#include "BlackjackHand.hpp"

class BlackjackGame : public CardGame {
private:
    std::vector<BlackjackHand> playerHands;   // Hands for each player in the game
    BlackjackHand dealerHand;                 // Hand for the dealer

    // Checks if a hand has a blackjack (initial two cards total 21)
    bool checkBlackjack(const BlackjackHand& hand) const;

public:
    // Constructor
    BlackjackGame(double minBetAmount, double maxBetAmount, Dealer gameDealer);

    // Deal cards to players
    void dealCards() override;

    // Player actions
    void hit(Player* player);                 // Player requests an additional card
    void stand(Player* player);               // Player decides to stand
    bool doubleDown(Player* player);          // Player doubles the bet and receives one more card
    bool split(Player* player);               // Player splits a hand into two if possible

    // Starts the Blackjack game, overriding startGame from Game
    void startGame() override;

    // Ends the Blackjack game, overriding endGame from Game
    void endGame() override;

    // Destructor
    ~BlackjackGame();
};

#endif // BLACKJACKGAME_HPP
