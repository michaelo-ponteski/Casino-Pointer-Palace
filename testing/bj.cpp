#include "../include/BlackjackGame.hpp"
#include <iostream>

// run with: g++ bj.cpp ../src/Bet.cpp ../src/Player.cpp ../src/BlackjackGame.cpp ../src/Dealer.cpp ../src/CardGame.cpp ../src/Game.cpp ../src/Deck.cpp ../src/Card.cpp ../src/BlackjackHand.cpp -o bj

int main() {
    // Create a Blackjack game
    Dealer dealer(160333, "Ziomal");
    BlackjackGame blackjack(10.0, 100.0, dealer);

    // Start the game
    blackjack.startGame();

    // Create a player
    Player player(123456, "Agnieszka", 1000.0);

    // Player actions
    blackjack.hit(&player);
    
    // End the game
    blackjack.endGame();

    return 0;
}