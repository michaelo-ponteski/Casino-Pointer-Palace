#include "../include/BlackjackGame.hpp"
#include "../include/Player.hpp"
#include "../include/BlackjackHand.hpp"
#include <iostream>
#include <algorithm>
#include <limits>

// Constructor
BlackjackGame::BlackjackGame(double minBetAmount, double maxBetAmount, Dealer& gameDealer) : CardGame("Blackjack", minBetAmount, maxBetAmount, gameDealer), dealer(gameDealer) {
    dealerHand = std::make_unique<DealerHand>(&dealer);
}

// Checks if any hand has a blackjack (initial two cards total 21)
size_t BlackjackGame::checkBlackjack() {
    // check if the dealer has blackjack
    if (dealerHand->getVisibleValue() == 11) {
        dealerHand->revealHiddenCard();
        std::cout << "Dealer's hand: " << dealerHand->getCards()[0].toString() << " " << dealerHand->getCards()[1].toString() << std::endl;
        if (dealerHand->calculateValue() == 21) {
            std::cout << "Dealer has blackjack!" << std::endl;
            return -1; // dealer has blackjack
        }
    }
    // check for blackjack in player hands
    for (size_t i = 0; i < playerHands.size(); ++i) {
        if (playerHands[i]->calculateValue() == 21) {
            //playerHands[i]->isActive = false;
            std::cout << "Blackjack for player " << playerHands[i]->owner->getName() << "!" << std::endl;
            return i;
        }
    }
    return -2; // no blackjack
}

// Add player hand
void BlackjackGame::addPlayerHand(Player* player) {
    playerHands.push_back(std::make_unique<BlackjackHand>(player));
}

// Deal cards to players
void BlackjackGame::dealCards() {
    // shuffle the deck
    shuffleDeck();
    std::cout << "\n=== Dealing Cards ===\n";
    // Clear all hands before dealing new cards
    dealerHand->clearHand();
    for (auto& hand : playerHands) {
        hand->clearHand();
    }
    // two cards for the dealer and for each player hand
    dealerHand->addCard(deck.drawCard());
    dealerHand->addCard(deck.drawCard());
    for (auto& hand : playerHands) {
        hand->addCard(deck.drawCard());
        hand->addCard(deck.drawCard());
    }
}

// Print all hands
void BlackjackGame::printHands() const {
    // print the dealer's hand
    std::cout << "Dealer's hand: [Hidden Card]  " << dealerHand->getCards()[1].toString() << std::endl;

    for (size_t i = 0; i < playerHands.size(); ++i) {
        std::cout << "Player " << playerHands[i]->owner->getName() << "'s hand: ";
        for (const Card& card : playerHands[i]->getCards()) {
            std::cout << card.toString() << "   ";
        }
        std::cout << std::endl;
    }
}

// Player requests an additional card
void BlackjackGame::hit(size_t handIndex) {
    if (handIndex >= playerHands.size()) {
        std::cout << "Invalid hand index." << std::endl;
        return;
    }

    BlackjackHand* hand = playerHands[handIndex].get();
    if (!hand->isActive) {
        std::cout << "Hand is not active." << std::endl;
        return;
    }

    hand->addCard(deck.drawCard());
    std::cout << "Player hits." << std::endl;
    std::cout << "Player's hand: ";
    for (const Card& card : hand->getCards()) {
        std::cout << card.toString() << " ";
    }
    std::cout << std::endl;
    hand->isActive = false;
}

// Player decides to stand
void BlackjackGame::stand(size_t handIndex) {
    if (handIndex >= playerHands.size()) {
        std::cout << "Invalid hand index." << std::endl;
        return;
    }

    BlackjackHand* hand = playerHands[handIndex].get();
    if (!hand->isActive) {
        std::cout << "Hand is not active." << std::endl;
        return;
    }

    hand->isActive = false;
    std::cout << "Player stands." << std::endl;
}

// Player doubles the bet and receives one more card
bool BlackjackGame::doubleDown(size_t handIndex) {
    if (handIndex >= playerHands.size()) {
        std::cout << "Invalid hand index." << std::endl;
        return false;
    }
    playerHands[handIndex]->betAmount *= 2;
    hit(handIndex);
    return true;
}

// Player splits a hand into two if possible
bool BlackjackGame::split(size_t handIndex) {
    if (handIndex >= playerHands.size()) {
        std::cout << "Invalid hand index." << std::endl;
        return false;
    }

    BlackjackHand* originalHand = playerHands[handIndex].get();
    if (originalHand->getCards().size() != 2 || !originalHand->isSplittable()) {
        std::cout << "Cannot split hand." << std::endl;
        return false;
    }

    // Split cards into two hands
    Card firstCard = originalHand->getCards()[0];
    Card secondCard = originalHand->getCards()[1];
    originalHand->clearHand();
    auto newHand = std::make_unique<BlackjackHand>(originalHand->owner);

    originalHand->addCard(firstCard);
    originalHand->addCard(deck.drawCard());
    originalHand->isActive = true; // Mark the original hand as active

    newHand->addCard(secondCard);
    newHand->addCard(deck.drawCard());
    newHand->betAmount = originalHand->betAmount;
    newHand->isActive = true; // Ensure the new hand is active

    // Add the new hand to the player's hands
    playerHands.insert(playerHands.begin() + handIndex + 1, std::move(newHand));

    printHands();
    return true;
}

// Prompts the player to choose an action
void BlackjackGame::promptPlayerAction(Player* player) {
    size_t i = 0;
    while (i < playerHands.size()) {
        BlackjackHand* hand = playerHands[i].get();
        if (hand->owner == player && hand->isActive) {
            std::cout << "Choose action for hand " << i + 1 << ": ";
            if (hand->isSplittable()) {
                std::cout << "(hit/stand/double/split)" << std::endl;
            } else {
                std::cout << "(hit/stand/double)" << std::endl;
            }

            std::string action;
            std::cin >> action;

            if (action == "hit") {
                hit(i);
            } else if (action == "stand") {
                stand(i);
            } else if (action == "double") {
                if (player->getBalance() < hand->betAmount) {
                    std::cout << "Insufficient balance to double down." << std::endl;
                } else {
                    doubleDown(i);
                }
            } else if (action == "split" && hand->isSplittable()) {
                if (split(i)) {
                    // No need to increment `i` since the original hand needs reprocessing
                    continue;
                }
            } else {
                std::cout << "Invalid action. Please choose again." << std::endl;
                continue;
            }
        }
        i++;
    }
}


// Dealer's turn
int BlackjackGame::dealersTurn() {
    // Reveal the dealer's hidden card
    dealerHand->revealHiddenCard();
    std::cout << "Dealer's hand: ";
    for (const Card& card : dealerHand->getCards()) {
        std::cout << card.toString() << " ";
    }
    std::cout << std::endl;

    // Dealer hits until the hand value is 17 or higher
    while (dealerHand->shouldHit()) {
        dealerHand->addCard(deck.drawCard());
        std::cout << "Dealer hits." << std::endl;
        std::cout << "Dealer's hand: ";
        for (const Card& card : dealerHand->getCards()) {
            std::cout << card.toString() << " ";
        }
        std::cout << std::endl;
    }

    // Return the dealer's final hand value
    return dealerHand->calculateValue();
}

// Get the value of each player hand
std::vector<int> BlackjackGame::getHandValues() const {
    std::vector<int> handValues;
    for (const auto& hand : playerHands) {
        handValues.push_back(hand->calculateValue());
    }
    return handValues;
}

// check results and update player balance
void BlackjackGame::resolveBets() {
    int dealerValue = dealerHand->calculateValue();

    for (auto& hand : playerHands) {
        Player* player = hand->owner;
        double bet = hand->betAmount;
        int playerValue = hand->calculateValue();

        std::cout << "Player " << player->getName() << "'s hand value: " << playerValue << std::endl;

        if (playerValue > 21) {
            std::cout << "Player " << player->getName() << " busts and loses $" << bet << "!" << std::endl;
        } else if (dealerValue > 21 || playerValue > dealerValue) {
            double payout = bet * 2;  // Standard payout
            player->addBalance(payout);
            std::cout << "Player " << player->getName() << " wins $" << payout << "!" << std::endl;
        } else if (playerValue == dealerValue) {
            player->addBalance(bet);  // Return the original bet
            std::cout << "Player " << player->getName() << " pushes and keeps $" << bet << "." << std::endl;
        } else {
            std::cout << "Dealer wins against player " << player->getName() << "!" << std::endl;
        }
    }
}



// Starts the Blackjack game
void BlackjackGame::startGame() {
    std::cout << "\n=== Starting New Game ===\n";
}

// Play a round of Blackjack
void BlackjackGame::playRound() {
    // Check if there are any players
    if (playerHands.empty()) {
        std::cout << "No players at the table." << std::endl;
        return;
    }
    startGame();

    // Prompt players to place bets
    for (auto& hand : playerHands) {
        Player* player = hand->owner;
        double bet;
        std::cout << "Balance: $" << player->getBalance() << std::endl;
        while (true) {
            std::cout << player->getName() << ", place your bet (min: $" << minBet << ", max: $" << maxBet << "): ";
            
            if (!(std::cin >> bet)) {  // Check for non-numeric input
                std::cin.clear();  // Clear error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
                std::cout << "Invalid input. Please enter a number." << std::endl;
                continue;
            }

            // Check if bet is within the allowed range
            if (bet < minBet || bet > maxBet) {
                std::cout << "Bet must be between $" << minBet << " and $" << maxBet << "." << std::endl;
                continue;
            }

            // Check if player has enough balance
            if (bet > player->getBalance()) {
                std::cout << "You don't have enough balance to place this bet!" << std::endl;
                continue;
            }

            // Valid input
            break;
        }

        // Deduct bet from player balance and set it for the hand
        player->placeBet(bet);
        hand->setBetAmount(bet);
        std::cout << player->getName() << " bet $" << bet << "." << std::endl;
    }


    // Deal cards
    dealCards();
    printHands();

    // Proceed with Blackjack checks, player actions, and dealer turn
    size_t blackjackIndex = checkBlackjack();
    if (blackjackIndex == -1) {  // Dealer blackjack
        resolveBets();
        endGame();
        return;
    } else if (blackjackIndex != -2) {  // Player blackjack
        resolveBets();
        endGame();
        return;
    }

    for (auto& hand : playerHands) {
        promptPlayerAction(hand->owner);
    }

    int dealerValue = dealersTurn();
    std::cout << "Dealer's hand value: " << dealerValue << std::endl;
    resolveBets();

    // Delete all player hands and create new one for each unique player
    std::vector<Player*> uniquePlayers;
    for (const auto& hand : playerHands) {
        if (std::find(uniquePlayers.begin(), uniquePlayers.end(), hand->owner) == uniquePlayers.end()) {
            uniquePlayers.push_back(hand->owner);
        }
    }
    playerHands.clear();
    for (Player* player : uniquePlayers) {
        addPlayerHand(player);
    }

    endGame();
}

// Ends the Blackjack game
void BlackjackGame::endGame() {
    std::cout << "\n=== Game Over ===" << std::endl;
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