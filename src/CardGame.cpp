#include "../include/CardGame.hpp"
#include "../include/Deck.hpp"
#include <iostream>


// Constructor
CardGame::CardGame(const std::string& name, double minBetAmount, double maxBetAmount, Dealer gameDealer)
    : Game(name, minBetAmount, maxBetAmount), dealer(gameDealer) {
    std::cout << "Card game " << name << " created." << std::endl;
    deck = Deck();  // Initialize the deck
}

//Deal cards to players
void CardGame::dealCards() {
    std::cout << "Dealing cards..." << std::endl;
}

// Shuffles the deck at the beginning of the game or between rounds
void CardGame::shuffleDeck() {
    deck.shuffle();
}

// Destructor
CardGame::~CardGame() {
    // Free memory allocated for community cards
    for (Card* card : communityCards) {
        delete card;
    }
}