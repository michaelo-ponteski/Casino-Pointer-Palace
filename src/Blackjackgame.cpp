#include "../include/BlackjackGame.hpp"
#include <iostream>

// Constructor
BlackjackGame::BlackjackGame(double minBetAmount, double maxBetAmount, Dealer gameDealer)
    : CardGame("Blackjack", minBetAmount, maxBetAmount, gameDealer) {
    std::cout << "Blackjack game created." << std::endl;
}

// Checks if a hand has a blackjack (initial two cards total 21)
bool BlackjackGame::checkBlackjack(const BlackjackHand& hand) const {
    //return hand.getHandValue() == 21 && hand.getHandSize() == 2;
}

// Deal cards to players
void BlackjackGame::dealCards() {
    std::cout << "Dealing cards for Blackjack..." << std::endl;
}

// Player requests an additional card
void BlackjackGame::hit(Player* player) {
    std::cout << player->getName() << " hits." << std::endl;
}

// Player decides to stand
void BlackjackGame::stand(Player* player) {
    std::cout << player->getName() << " stands." << std::endl;
}

// Player doubles the bet and receives one more card
bool BlackjackGame::doubleDown(Player* player) {
    std::cout << player->getName() << " doubles down." << std::endl;
    return true;
}

// Player splits a hand into two if possible
bool BlackjackGame::split(Player* player) {
    std::cout << player->getName() << " splits." << std::endl;
    return true;
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