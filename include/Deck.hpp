#ifndef DECK_HPP
#define DECK_HPP

#include <vector>
#include "Card.hpp"

class Deck {
private:
    std::vector<Card> cards;   // Vector holding all cards in the deck

public:
    // Constructor to initialize the deck with a standard set of cards
    Deck();

    // Shuffles the deck of cards
    void shuffle();

    // Draws a card from the top of the deck
    Card drawCard();

    // Resets the deck to the full set of cards
    void resetDeck();

    // Checks if the deck is empty
    bool isEmpty() const;

    // Destructor
    ~Deck();
};

#endif // DECK_HPP
