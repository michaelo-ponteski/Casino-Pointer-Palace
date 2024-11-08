#include "../include/BlackjackGame.hpp"
#include "../include/Player.hpp"
#include "../include/BlackjackHand.hpp"
#include <iostream>

// Constructor
BlackjackGame::BlackjackGame(double minBetAmount, double maxBetAmount, Dealer gameDealer)
    : CardGame("Blackjack", minBetAmount, maxBetAmount, gameDealer) {
    dealerHand = std::make_unique<BlackjackHand>(gameDealer);
}

// Checks if any hand has a blackjack (initial two cards total 21)
size_t BlackjackGame::checkBlackjack() {
    // check if the dealer has blackjack
    if (dealerHand->calculateValue() == 21) {
        std::cout << "Blackjack for dealer!" << std::endl;
        return playerHands.size();
    }
    // check for blackjack in player hands
    for (size_t i = 0; i < playerHands.size(); ++i) {
        if (playerHands[i]->calculateValue() == 21) {
            playerHands[i]->isActive = false;
            std::cout << "Blackjack for player " << playerHands[i]->owner->getName() << "!" << std::endl;
            return i;
        }
    }
    return -1;
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
    for (size_t i = 0; i < playerHands.size(); ++i) {
        if ((playerHands[i]->owner == player) && (playerHands[i]->isActive)) {
            if (playerHands[i]->isSplittable()) {
                std::cout << "Choose action for hand " << i + 1 << ": (hit/stand/double/split)" << std::endl;
            } else {
                std::cout << "Choose action for hand " << i + 1 << ": (hit/stand/double)" << std::endl;
            }
            std::string action;
            std::cin >> action;

            if (action == "hit") {
                hit(i);
            } else if (action == "stand") {
                stand(i);
            } else if (action == "double") {
                doubleDown(i);
            } else if (action == "split" && playerHands[i]->isSplittable()) {
                split(i);
            } else {
                std::cout << "Invalid action. Please choose again." << std::endl;
                --i; // Retry the same hand
            }
        }
    }
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