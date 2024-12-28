#include <Deck.hpp>
#include <Card.hpp>
#include <algorithm>
#include <random>


// Constructor to initialize the deck with a standard set of cards
Deck::Deck() {
    resetDeck();
}

// Shuffles the deck of cards
void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
} 

// Draws a card from the top of the deck
Card Deck::drawCard() {
    if (cards.empty()) {
        resetDeck();
        shuffle();
    }
    Card topCard = cards.back();
    cards.pop_back();
    return topCard;
}

// Resets the deck to the full set of cards (6 decks)
void Deck::resetDeck() {
    cards.clear();
    for (int dck = 0; dck < 6; dck++){
        for (int suit = 0; suit < 4; suit++) {
            for (int rank = 0; rank < 13; rank++) {
                cards.push_back(Card(static_cast<Suit>(suit), static_cast<Rank>(rank)));
            }
        }
    }
}

// Checks if the deck is empty
bool Deck::isEmpty() const {
    return cards.empty();
}

// Destructor
Deck::~Deck() {}