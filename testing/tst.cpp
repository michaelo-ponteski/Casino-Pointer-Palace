#include <iostream>
#include <stdexcept>
#include "../include/BlackjackGame.hpp"
#include "../include/Player.hpp"
#include "../include/RouletteGame.hpp"
#include <limits>

// run with: g++ tst.cpp ../src/*.cpp -o tst


void testRoulette() {
    // Test a full round of Roulette
    Player player(1, "Alice", 1000.0);
    RouletteGame game(&player);
    game.startGame();
    while(true) {
        game.playRound();
        std::cout << "Press ENTER to play another round" << std::endl;
        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // any other button means exit
        if (std::cin.get() != '\n') {
            break;
        }
    }
    game.endGame();
}

void testBlackjack() {
    // Test a full round of Blackjack
    Dealer dealer(420, "Miłosz");
    BlackjackGame game(10.0, 100.0, dealer);
    
    Player player1(69, "Janusz", 1000.0);
    game.addPlayerHand(&player1);
    while(true) {
        game.playRound();
        std::cout << "Press ENTER to play another round" << std::endl;
        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // any other button means exit
        if (std::cin.get() != '\n') {
            break;
        }
    }
}

int main() {
    testRoulette();
    return 0;
}