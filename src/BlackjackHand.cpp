#include "../include/BlackjackHand.hpp"
#include "../include/Card.hpp"
#include <algorithm>
#include <vector>

// Constructor
BlackjackHand::BlackjackHand(Player* player) : owner(player), betAmount(0.0), isActive(true) {
    //std::cout << "Blackjack hand created." << std::endl;
}

// set bet amount
void BlackjackHand::setBetAmount(double amount) {
    betAmount = amount;
}

// Adds a card to the hand
void BlackjackHand::addCard(const Card& card) {
    cards.push_back(card);
    // std::cout << "Card added to hand." << std::endl;
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

// Check if busted
bool BlackjackHand::isBusted() const {
    return calculateValue() > 21;
}

// Returns the cards in the hand
const std::vector<Card>& BlackjackHand::getCards() const {
    return cards;
}

// Prints visual representation of the hand
void BlackjackHand::prettyPrint() const {
    std::vector<std::string> suits;
    std::vector<std::string> ranks;
    for (const Card& card : cards) {
        std::string suitStr;
        switch (card.getSuit()) {
            case Suit::HEARTS: suitStr = "♥"; break;
            case Suit::DIAMONDS: suitStr = "♦"; break;
            case Suit::CLUBS: suitStr = "♣"; break;
            case Suit::SPADES: suitStr = "♠"; break;
            default: suitStr = " "; break;
        }
        suits.push_back(suitStr);

        std::string rankStr;
        switch (card.getRank()) {
            case Rank::TWO: rankStr = "2"; break;
            case Rank::THREE: rankStr = "3"; break;
            case Rank::FOUR: rankStr = "4"; break;
            case Rank::FIVE: rankStr = "5"; break;
            case Rank::SIX: rankStr = "6"; break;
            case Rank::SEVEN: rankStr = "7"; break;
            case Rank::EIGHT: rankStr = "8"; break;
            case Rank::NINE: rankStr = "9"; break;
            case Rank::TEN: rankStr = "10"; break;
            case Rank::JACK: rankStr = "J"; break;
            case Rank::QUEEN: rankStr = "Q"; break;
            case Rank::KING: rankStr = "K"; break;
            case Rank::ACE: rankStr = "A"; break;
            default: rankStr = " "; break;
        }
        ranks.push_back(rankStr);
    }

    std::string art = "";
    int numCards = cards.size();
    for (int i = 0; i < numCards; i++) {
        art += "  ___ ";
    }
    art += "\n";
    for (int i = 0; i < numCards; i++) {
        if (ranks[i] == "10") {
            art += " |10 |";
        } else {
            art += " |" + ranks[i] + "  |";
        }
    }
    art += "\n";
    for (int i = 0; i < numCards; i++) {
        art += " | " + suits[i] + " |";
    }
    art += "\n";
    for (int i = 0; i < numCards; i++) {
        if (ranks[i] == "10") {
            art += " |_10|";
        } else {
            art += " |__" + ranks[i] + "|";
        }
    }
    art += "\n";
    std::cout << art << std::endl;
}

// Clears the hand for a new round
void BlackjackHand::clearHand() {
    cards.clear();
    // std::cout << "Hand cleared." << std::endl;
}

// Destructor
BlackjackHand::~BlackjackHand() {
    // std::cout << "Blackjack hand destroyed." << std::endl;
}