#ifndef BLACKJACKGAME_HPP
#define BLACKJACKGAME_HPP

#include <vector>
#include <memory>
#include "CardGame.hpp"
#include "Player.hpp"
#include "BlackjackHand.hpp"
#include "Dealer.hpp"

class BlackjackGame : public CardGame {
private:
    std::vector<std::unique_ptr<BlackjackHand>> playerHands;  // Hands of the player
    std::unique_ptr<BlackjackHand> dealerHand;                // Hand of the dealer

    // Checks if any hand has a blackjack (initial two cards total 21)
    size_t checkBlackjack();

public:
    // Constructor
    BlackjackGame(double minBetAmount, double maxBetAmount, Dealer gameDealer);

    // Add player hand
    void addPlayerHand(Player* player);
    
    // Deal cards to players
    void dealCards() override;

    // Player actions
    void hit(size_t handIndex);                 // Player requests an additional card
    void stand(size_t handIndex);               // Player decides to stand
    bool doubleDown(size_t handIndex);          // Player doubles the bet and receives one more card
    bool split(size_t handIndex);               // Player splits a hand into two if possible

    void promptPlayerAction(Player* player);  // Prompts the player to choose an action


    // Starts the Blackjack game, overriding startGame from Game
    void startGame() override;

    // Ends the Blackjack game, overriding endGame from Game
    void endGame() override;

    // Destructor
    ~BlackjackGame();
};

#endif // BLACKJACKGAME_HPP
