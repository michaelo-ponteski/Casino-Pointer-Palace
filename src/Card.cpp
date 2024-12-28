#include <Card.hpp>
#include <string>


// Constructor
Card::Card(Suit cardSuit, Rank cardRank) : suit(cardSuit), rank(cardRank) {}

// Getters
Suit Card::getSuit() const {
    return suit;
}

Rank Card::getRank() const {
    return rank;
}

// Returns a string representation of the card
std::string Card::toString() const {
    std::string suitStr;
    std::string rankStr;

    switch (suit) {
        case Suit::HEARTS:
            suitStr = "Hearts";
            break;
        case Suit::DIAMONDS:
            suitStr = "Diamonds";
            break;
        case Suit::CLUBS:
            suitStr = "Clubs";
            break;
        case Suit::SPADES:
            suitStr = "Spades";
            break;
    }

    switch (rank) {
        case Rank::TWO:
            rankStr = "Two";
            break;
        case Rank::THREE:
            rankStr = "Three";
            break;
        case Rank::FOUR:
            rankStr = "Four";
            break;
        case Rank::FIVE:
            rankStr = "Five";
            break;
        case Rank::SIX:
            rankStr = "Six";
            break;
        case Rank::SEVEN:
            rankStr = "Seven";
            break;
        case Rank::EIGHT:
            rankStr = "Eight";
            break;
        case Rank::NINE:
            rankStr = "Nine";
            break;
        case Rank::TEN:
            rankStr = "Ten";
            break;
        case Rank::JACK:
            rankStr = "Jack";
            break;
        case Rank::QUEEN:
            rankStr = "Queen";
            break;
        case Rank::KING:
            rankStr = "King";
            break;
        case Rank::ACE:
            rankStr = "Ace";
            break;
    }

    return rankStr + " of " + suitStr;
}

// Destructor
Card::~Card() {}