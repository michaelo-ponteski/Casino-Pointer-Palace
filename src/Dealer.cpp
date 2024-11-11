#include "../include/Dealer.hpp"
#include <iostream>
#include <string>


// Constructor
Dealer::Dealer(int id, const std::string& dealerName) : dealerId(id), name(dealerName), isAvailable(true) {
    std::cout << "Dealer " << name << " created." << std::endl;
}

// Sets dealer availability
void Dealer::setAvailability(bool availability) {
    isAvailable = availability;
}

// Checks if the dealer is available
bool Dealer::getAvailability() const {
    return isAvailable;
}

// Deals cards to players (specific to card games)
void Dealer::dealCards() {
    std::cout << "Dealing cards..." << std::endl;
}

// Collects bets from players
void Dealer::collectBets() {
    std::cout << "Collecting bets..." << std::endl;
}

// Payouts winnings to players
void Dealer::payoutWinnings() {
    std::cout << "Paying out winnings..." << std::endl;
}

// Getters
int Dealer::getDealerId() const {
    return dealerId;
}

std::string Dealer::getName() const {
    return name;
}

// Destructor
Dealer::~Dealer() {
    std::cout << "Dealer " << name << " destroyed." << std::endl;
}