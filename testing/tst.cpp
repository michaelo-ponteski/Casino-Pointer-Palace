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
        std::cout << "\n=== Game Over ===\n";
        game.endGame();
        return;
    } else if (blackjackIndex != -2) {
        std::cout << "Blackjack for player " << player1.getName() << "!" << std::endl;
        std::cout << "\n=== Game Over ===\n";
        game.endGame();
        return;
    } else {
        std::cout << "No blackjack." << std::endl;
    }

    // Player actions
    game.promptPlayerAction(&player1);
    std::vector<int> playerValues = game.getHandValues();
    int dealerValue = game.dealersTurn();
    std::cout << "Dealer's hand value: " << dealerValue << std::endl;

    for (size_t i = 0; i < playerValues.size(); ++i) {
        int playerValue = playerValues[i];
        std::cout << "Player " << i + 1 << "'s hand value: " << playerValue << std::endl;
        if (playerValue > 21) {
            std::cout << "Player " << i + 1 << " busts!" << std::endl;
        } else if (dealerValue > 21 || playerValue > dealerValue) {
            std::cout << "Player " << i + 1 << " wins!" << std::endl;
        } else if (playerValue == dealerValue) {
            std::cout << "Player " << i + 1 << " pushes!" << std::endl;
        } else {
            std::cout << "Dealer wins against player " << i + 1 << "!" << std::endl;
        }
    }

    std::cout << "\n=== Game Over ===\n";
    game.endGame();
}

void testSplitHand() {
    // Test splitting a hand
}

void testDoubleDown() {
    // Test double down functionality
}

void testDealerBehavior() {
    // Test dealer's actions
}

int main() {
    while(true) {
        testBasicGameplay();
        std::string input;
        std::cout << "Play again? (y/n): ";
        std::cin >> input;
        if (input != "y") {
            break;
        }
    }
    return 0;
}