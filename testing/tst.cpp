#include <iostream>
#include <stdexcept>
#include "../include/BlackjackGame.hpp"

// run with: g++ tst.cpp ../src/*.cpp -o tst

enum betType {STANDARD, INSURANCE};

void testBasicGameplay() {
    Dealer dealer(420, "złodziej");
    BlackjackGame game(10.0, 100.0, dealer);
    
    Player player1(69, "Janusz", 1000.0);
    game.addPlayerHand(&player1);

    std::cout << "\n=== Starting New Game ===\n";
    game.startGame();

    std::cout << "\n=== Dealing Cards ===\n";
    game.dealCards();

    // Display initial hands
    game.printHands();

    // Check for blackjack
    size_t blackjackIndex = game.checkBlackjack();
    if (blackjackIndex == -1) {
        std::cout << "Dealer has blackjack!" << std::endl;
    } else if (blackjackIndex != -2) {
        std::cout << "Blackjack for player " << player1.getName() << "!" << std::endl;
    } else {
        std::cout << "No blackjack." << std::endl;
    }

    // Player actions
    game.promptPlayerAction(&player1);
    // game.printHands();
    int dealerValue = game.dealersTurn();
    int playerValue = game.getHandValues()[0];
    std::cout << "Dealer's hand value: " << dealerValue << std::endl;
    std::cout << "Player's hand value: " << playerValue << std::endl;
    if (playerValue > 21) {
        std::cout << "Player busts!" << std::endl;
    } else if (dealerValue > 21 || playerValue > dealerValue) {
        std::cout << "Player wins!" << std::endl;
    } else if (playerValue == dealerValue) {
        std::cout << "Push!" << std::endl;
    } else {
        std::cout << "Dealer wins!" << std::endl;
    }

    std::cout << "\n=== Game Over ===\n";
    game.endGame();
}

void testSplitHand() {
    // Test splitting functionality
}

void testDoubleDown() {
    // Test double down functionality
}

void testDealerBehavior() {
    // Test dealer's actions
}

int main() {
    try {
        testBasicGameplay();
        testSplitHand();
        testDoubleDown();
        testDealerBehavior();
        
        std::cout << "All tests passed!\n";
    } catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}