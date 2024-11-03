#ifndef CARD_HPP
#define CARD_HPP

#include <string>

enum class Suit {
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES
};

enum class Rank {
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
};

class Card {
private:
    Suit suit;           // The suit of the card
    Rank rank;          // The rank of the card

public:
    // Constructor
    Card(Suit cardSuit, Rank cardRank);

    // Getters
    Suit getSuit() const;
    Rank getRank() const;

    // Returns a string representation of the card
    std::string toString() const;

    // Destructor
    ~Card();
};

#endif // CARD_HPP
