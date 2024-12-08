#include <iostream>
#include <stdexcept>
#include "../include/BlackjackGame.hpp"
#include "../include/Player.hpp"
#include "../include/RouletteGame.hpp"
#include "../include/Casino.hpp"
#include <limits>


// Run the main executable in /build/ with: ./CasinoPointerPalace
// If you need to build then build in /build/ with: cmake --build .  
// or if you live under the stone then run with smth like this: g++ /src/*.cpp -o execFile

void printASCIIart() {
    std::cout << R"(
    WELCOME TO
    __   ____  _____ ____  ____    ___       ____   ___  ____  ____   ______    ___  ____       ____   ____  _       ____    __    ___ 
   /  ] /    |/ ___/|    ||    \  /   \     |    \ /   \|    ||    \ |      |  /  _]|    \     |    \ /    || |     /    |  /  ]  /  _]
  /  / |  o  (   \_  |  | |  _  ||     |    |  o  )     ||  | |  _  ||      | /  [_ |  D  )    |  o  )  o  || |    |  o  | /  /  /  [_ 
 /  /  |     |\__  | |  | |  |  ||  O  |    |   _/|  O  ||  | |  |  ||_|  |_||    _]|    /     |   _/|     || |___ |     |/  /  |    _]
/   \_ |  _  |/  \ | |  | |  |  ||     |    |  |  |     ||  | |  |  |  |  |  |   [_ |    \     |  |  |  _  ||     ||  _  /   \_ |   [_ 
\     ||  |  |\    | |  | |  |  ||     |    |  |  |     ||  | |  |  |  |  |  |     ||  .  \    |  |  |  |  ||     ||  |  \     ||     |
 \____||__|__| \___||____||__|__| \___/     |__|   \___/|____||__|__|  |__|  |_____||__|\_|    |__|  |__|__||_____||__|__|\____||_____|
)" << std::endl;
}

void testRoulette() {
    // Test a full round of Roulette
    Player player(1, "Janusz", 1000.0, false);
    RouletteGame game(&player);
    game.startGame();
    while(true) {
        game.playRound();
        player.stats.saveToFile();
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
    Player player1(69, "Janusz", 1000.0, false);
    BlackjackGame game(&player1, 10.0, 1000.0, dealer);
    
    while(true) {
        game.playRound();
        player1.stats.saveToFile();
        std::cout << "Press ENTER to play another round" << std::endl;
        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // any other button means exit
        if (std::cin.get() != '\n') {
            break;
        }
    }
}

void testCasino() {
    // Test the Casino class
    Casino casino;
}


int main() {
    // pick one
    // testBlackjack();
    // testRoulette();
    printASCIIart();
    testCasino();
    return 0;
}