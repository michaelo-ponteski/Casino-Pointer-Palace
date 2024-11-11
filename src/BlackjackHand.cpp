#include "../include/BlackjackHand.hpp"
#include "../include/Card.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

// Constructor
BlackjackHand::BlackjackHand(Player* player) : owner(player), betAmount(0.0), isActive(true) {
    std::cout << "Blackjack hand created." << std::endl;
}

// Adds a card to the hand
void BlackjackHand::addCard(const Card& card) {
    cards.push_back(card);
    std::cout << "Card added to hand." << std::endl;
}

// Calculates the total value of the hand
int BlackjackHand::calculateValue() const {
    int totalValue = 0;
    int numAces = 0;

    for (const Card& card : cards) {
        int cardValue;
        switch (card.getRank()) {
            case Rank::TWO: cardValue = 2; break;
            case Rank::THREE: cardValue = 3; break;
            case Rank::FOUR: cardValue = 4; break;
            case Rank::FIVE: cardValue = 5; break;
            case Rank::SIX: cardValue = 6; break;
            case Rank::SEVEN: cardValue = 7; break;
            case Rank::EIGHT: cardValue = 8; break;
            case Rank::NINE: cardValue = 9; break;
            case Rank::TEN:
            case Rank::JACK:
            case Rank::QUEEN:
            case Rank::KING: cardValue = 10; break;
            case Rank::ACE: cardValue = 11; break;
            default: cardValue = 0; break;
        }
        totalValue += cardValue;

        if (card.getRank() == Rank::ACE) {
            numAces++;
        }
    }

    // Adjust the total value for aces
    while (totalValue > 21 && numAces > 0) {
        totalValue -= 10; // Convert an ace from 11 to 1
        numAces--;
    }

    return totalValue;
}

// Checks if the hand is splittable
bool BlackjackHand::isSplittable() const {
    if (cards.size() != 2) {
        return false;
    }

    // Check if the two cards have the same rank
    return cards[0].getRank() == cards[1].getRank();
}

// Returns the cards in the hand
const std::vector<Card>& BlackjackHand::getCards() const {
    return cards;
}

// Clears the hand for a new round
void BlackjackHand::clearHand() {
    cards.clear();
    std::cout << "Hand cleared." << std::endl;
}

// Destructor
BlackjackHand::~BlackjackHand() {
    std::cout << "Blackjack hand destroyed." << std::endl;
}