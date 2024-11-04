#include "../src/Deck.cpp"
#include "../src/Card.cpp"
#include <iostream>


int main() {
    Deck deck;
    deck.shuffle();
    while (!deck.isEmpty()) {
        Card card = deck.drawCard();
        std::cout << card.toString() << std::endl;
    }
    return 0;
}