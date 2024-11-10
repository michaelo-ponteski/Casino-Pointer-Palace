#ifndef BLACKJACKHAND_HPP
#define BLACKJACKHAND_HPP

#include <vector>
#include "Card.hpp"
#include "Player.hpp"

class BlackjackHand {
protected:
    std::vector<Card> cards; // The cards in this Blackjack hand

public:
    Player* owner; // The player who owns this hand
    double betAmount; // The amount of the bet placed on this hand
    bool isActive; // Whether the hand is still active in the game

    // Constructor
    BlackjackHand(Player* player);

    // Adds a card to the hand
    void addCard(const Card& card);

    // Calculates the total value of the hand
    int calculateValue() const;

    // Checks if the hand is splittable
    bool isSplittable() const;

    // Returns the cards in the hand
    const std::vector<Card>& getCards() const;

    // Clears the hand for a new round
    void clearHand();

    // Destructor
    ~BlackjackHand();
};

#endif // BLACKJACKHAND_HPP
