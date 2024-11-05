#ifndef CARDGAME_HPP
#define CARDGAME_HPP

#include <vector>
#include "Game.hpp"
#include "Deck.hpp"
#include "Dealer.hpp"
#include "Card.hpp"

class CardGame : public Game {
protected:
    Deck deck;                               // Deck of cards used in the game
    Dealer dealer;                           // Dealer for managing game operations
    std::vector<Card*> communityCards;       // Community cards for games that use them (e.g., Poker)


public:
    // Constructor
    CardGame(const std::string& name, double minBetAmount, double maxBetAmount, Dealer gameDealer);

    // Shuffles the deck at the beginning of the game or between rounds
    void shuffleDeck();

    // Deals cards to players; virtual for possible override by derived classes
    virtual void dealCards() = 0;

    // Destructor
    virtual ~CardGame();
};

#endif // CARDGAME_HPP
