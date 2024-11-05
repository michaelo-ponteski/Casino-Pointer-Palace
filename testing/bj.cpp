#include "../src/BlackjackGame.cpp"
#include <iostream>

int main() {
    // Create a Blackjack game
    Dealer dealer(160333, "Dealer");
    BlackjackGame blackjack(10.0, 100.0, dealer);

    // Start the game
    blackjack.startGame();

    // Create a player
    Player player(123456, "Alice", 1000.0);

    // Player actions
    blackjack.hit(&player);
    
    // End the game
    blackjack.endGame();

    return 0;
}