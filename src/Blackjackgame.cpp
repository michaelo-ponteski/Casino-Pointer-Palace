#include "../include/BlackjackGame.hpp"
#include "../include/Player.hpp"
#include "../include/BlackjackHand.hpp"
#include <iostream>

// Constructor
BlackjackGame::BlackjackGame(double minBetAmount, double maxBetAmount, Dealer gameDealer)
    : CardGame("Blackjack", minBetAmount, maxBetAmount, gameDealer) {
    dealerHand = std::make_unique<BlackjackHand>(gameDealer);
}

// Checks if a hand has a blackjack (initial two cards total 21)
bool BlackjackGame::checkBlackjack(const BlackjackHand& hand) const {
    //return hand.getHandValue() == 21 && hand.getHandSize() == 2;
    return false; // Placeholder implementation
}

// Add player hand
void BlackjackGame::addPlayerHand(Player* player) {
    playerHands.push_back(std::make_unique<BlackjackHand>(player));
}

// Deal cards to players
void BlackjackGame::dealCards() {
    std::cout << "Dealing cards for Blackjack..." << std::endl;
}

// Player requests an additional card
void BlackjackGame::hit(size_t handIndex) {
    std::cout << "hit" << std::endl;
}

// Player decides to stand
void BlackjackGame::stand(size_t handIndex) {
    std::cout << "stand" << std::endl;
}

// Player doubles the bet and receives one more card
bool BlackjackGame::doubleDown(size_t handIndex) {
    std::cout << "double down" << std::endl;
    return true;
}

// Player splits a hand into two if possible
bool BlackjackGame::split(size_t handIndex) {
    if (handIndex >= playerHands.size()) {
        std::cout << "Invalid hand index." << std::endl;
        return false;
    }

    BlackjackHand* originalHand = playerHands[handIndex].get();
    if (originalHand->getCards().size() != 2) {
        std::cout << "Cannot split hand with more than two cards." << std::endl;
        return false;
    }

    // Create a new hand with the second card from the original hand with the same owner
    Card firstCard = originalHand->getCards()[0];
    Card secondCard = originalHand->getCards()[1];
    originalHand->clearHand();
    auto newHand = std::make_unique<BlackjackHand>(originalHand->owner);
    originalHand->addCard(firstCard);
    newHand->addCard(secondCard);
    newHand->betAmount = originalHand->betAmount;

    // Add the new hand to the player's hands
    playerHands.push_back(std::move(newHand));
    return true;
}

// Prompts the player to choose an action
void BlackjackGame::promptPlayerAction(Player* player) {
    std::cout << "Prompting player " << player->getName() << " to choose an action..." << std::endl;
}

// Starts the Blackjack game
void BlackjackGame::startGame() {
    std::cout << "Starting Blackjack game..." << std::endl;
}

// Ends the Blackjack game
void BlackjackGame::endGame() {
    std::cout << "Ending Blackjack game..." << std::endl;
}

// Destructor
BlackjackGame::~BlackjackGame() {
    // No additional cleanup needed
}

// example usage of hand class
/*
void BlackjackGame::dealCards() override {
    // Deal two cards to each player hand
    for (auto& hand : playerHands) {
        hand->addCard(deck.drawCard());
        hand->addCard(deck.drawCard());
    }
    
    // Deal to dealer
    dealerHand->addCard(deck.drawCard());
    dealerHand->addCard(deck.drawCard());
}
*/