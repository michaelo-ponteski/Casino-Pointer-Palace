#include "../include/DealerHand.hpp"
#include "../include/Dealer.hpp"
#include "../include/BlackjackHand.hpp"
#include "../include/Card.hpp"
#include <stdexcept>

// Constructor - pass nullptr as Player* since dealer isn't a player
DealerHand::DealerHand(Dealer* dealer) : BlackjackHand(nullptr), firstCardHidden(true) {}

// Dealer specific
bool DealerHand::shouldHit() const {
    return calculateValue() < 17;
}

// Check if the dealer has a hidden card
bool DealerHand::hasHiddenCard() const {
    return firstCardHidden;
}

// Get the visible hand value (when firstCardHidden is true)
int DealerHand::getVisibleValue() const {
    if (cards.size() < 2) {
        throw std::runtime_error("Not enough cards to get visible value.");
    }

    int cardValue = 0;
    switch (cards[1].getRank()) {
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
    return cardValue;
}

// Reveal the hidden card
void DealerHand::revealHiddenCard() {
    firstCardHidden = false;
}

// Hide the first card
void DealerHand::hideFirstCard() {
    firstCardHidden = true;
}

// Override prettyPrint to hide the first card if it's hidden
void DealerHand::prettyPrint() const {
    if (cards.empty()) {
        throw std::runtime_error("No cards to print.");
    }

    std::vector<std::string> suits;
    std::vector<std::string> ranks;
    int crd_no = 1;
    for (const Card& card : cards) {
        std::string suitStr;
        switch (card.getSuit()) {
            case Suit::HEARTS: suitStr = "♥"; break;
            case Suit::DIAMONDS: suitStr = "♦"; break;
            case Suit::CLUBS: suitStr = "♣"; break;
            case Suit::SPADES: suitStr = "♠"; break;
            default: suitStr = " "; break;
        }
        if (crd_no == 1 && firstCardHidden) {
            suitStr = "?";
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
        if (crd_no == 1 && firstCardHidden) {
            rankStr = "?";
        }
        ranks.push_back(rankStr);
        crd_no++;
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

// Destructor
DealerHand::~DealerHand() {}
