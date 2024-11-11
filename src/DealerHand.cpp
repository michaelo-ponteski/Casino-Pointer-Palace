#include "../include/DealerHand.hpp"
#include "../include/Dealer.hpp"
#include "../include/BlackjackHand.hpp"
#include "../include/Card.hpp"

// Constructor - pass nullptr as Player* since dealer isn't a player
DealerHand::DealerHand(Dealer* dealer) : BlackjackHand(nullptr), firstCardHidden(true) {}

// Dealer specific
bool DealerHand::shouldHit() const {
    return calculateValue() < 17;
}

// Get the card(s) - overridden to return the visible card or both
std::vector<Card> DealerHand::getCards() {
    if (firstCardHidden) {
        return std::vector<Card>{cards[1]};
    } else {
        return cards;
    }
}

// Get the visible hand value (when firstCardHidden is true)
int DealerHand::getVisibleValue() const {
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

// Destructor
DealerHand::~DealerHand() {}
