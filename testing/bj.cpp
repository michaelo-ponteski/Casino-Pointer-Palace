#include "../include/BlackjackGame.hpp"
#include <iostream>

// run with: g++ bj.cpp ../src/Bet.cpp ../src/Player.cpp ../src/BlackjackGame.cpp ../src/Dealer.cpp ../src/CardGame.cpp ../src/Game.cpp ../src/Deck.cpp ../src/Card.cpp ../src/BlackjackHand.cpp -o bj

int main() {
    // Create a new Blackjack game
    Dealer dealer(420, "Ziomal");
    BlackjackGame game(10.0, 100.0, dealer);

    // Add player to the game
    Player player1(69, "Alice", 100.0);
    game.addPlayerHand(&player1);

    // Start the game
    game.startGame();

    // Deal cards to players
    game.dealCards();

    // Check for blackjack (private for now)
    //game.checkBlackjack();

    // Prompt player to choose an action
    game.promptPlayerAction(&player1);

    // End the game
    game.endGame();

    return 0;
}