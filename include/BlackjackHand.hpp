#ifndef BLACKJACKHAND_HPP
#define BLACKJACKHAND_HPP

#include <vector>
#include "Card.hpp"

class BlackjackHand {
private:
    std::vector<Card> cards; // The cards in this Blackjack hand

public:
    // Constructor
    BlackjackHand();

    // Adds a card to the hand
    void addCard(const Card& card);

    // Calculates the total value of the hand
    int calculateValue() const;

    // Returns the cards in the hand
    const std::vector<Card>& getCards() const;

    // Clears the hand for a new round
    void clearHand();

    // Destructor
    ~BlackjackHand();
};

#endif // BLACKJACKHAND_HPP
