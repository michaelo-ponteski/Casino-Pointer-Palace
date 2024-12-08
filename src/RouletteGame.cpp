#include "../include/RouletteGame.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

RouletteGame::RouletteGame(Player* p) : Game("Roulette", 10.0, 1000.0) {
    // Constructor
    std::srand(std::time(0)); // Seed the random number generator
    gamePlayer = p;
}

RouletteGame::~RouletteGame() {
    // Destructor
}

void RouletteGame::placeBet() {
    int betTypeInput;
    int amount;
    int number = -1;

    std::cout << "Choose your bet type:\n";
    std::cout << "1 - Red\n";
    std::cout << "2 - Black\n";
    std::cout << "3 - Odd\n";
    std::cout << "4 - Even\n";
    std::cout << "5 - High (19-36)\n";
    std::cout << "6 - Low (1-18)\n";
    std::cout << "7 - Straight Up (specific number)\n";
    std::cout << "8 - Street (three numbers in a row)\n";
    while (true) {
        std::cin >> betTypeInput;
        if (std::cin.fail() || betTypeInput < 1 || betTypeInput > 8) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cout << "Invalid bet type. Please enter a number between 1 and 8.\n";
        } else {
            break;
        }
    }

    while (true) {
        std::cout << "Enter the amount to bet: ";
        std::cin >> amount;
        if (std::cin.fail() || amount < minBet || amount > maxBet || amount > gamePlayer->getBalance()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cout << "Invalid amount. Please enter an amount between " << minBet << " and " << maxBet 
                      << " that you can afford.\n";
        } else {
            break;
        }
    }
    gamePlayer->placeBet(amount);

    BetType betType;
    switch (betTypeInput) {
        case 1:
            betType = RED;
            break;
        case 2:
            betType = BLACK;
            break;
        case 3:
            betType = ODD;
            break;
        case 4:
            betType = EVEN;
            break;
        case 5:
            betType = HIGH;
            break;
        case 6:
            betType = LOW;
            break;
        case 7:
            betType = STRAIGHT_UP;
            while (true) {
                std::cout << "Enter the number to bet on (0-36): ";
                std::cin >> number;
                if (std::cin.fail() || number < 0 || number > 36) {
                    std::cin.clear(); // Clear the error flag
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
                    std::cout << "Invalid number. Please enter a number between 0 and 36.\n";
                } else {
                    break;
                }
            }
            break;
        case 8:
            betType = STREET;
            while (true) {
                std::cout << "Enter the starting number of the three (1-34): ";
                std::cin >> number;
                if (std::cin.fail() || number < 1 || number > 34) {
                    std::cin.clear(); // Clear the error flag
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
                    std::cout << "Invalid number. Please enter a number between 1 and 34.\n";
                } else {
                    break;
                }
            }
            break;
        default:
            std::cout << "Invalid bet type. Please try again.\n";
            return;
    }

    Bet bet = {betType, amount, number};
    bets.push_back(bet);
}

void RouletteGame::spinWheel() {
    // Generate a random number between 0 and 36
    winningNumber = std::rand() % 37;
    winningColor = getColor(winningNumber);
    std::cout << "The winning number is: " << winningNumber << " (" << winningColor << ")" << std::endl;
}

void RouletteGame::resolveBets() {
    for (const Bet& bet : bets) {
        bool won = false;
        std::string color = "None";
        int payout = bet.amount * 2; // Default payout for even money bets
        switch (bet.type) {
            case RED:
                color = "Red";
                won = (winningColor == "Red");
                break;
            case BLACK:
                color = "Black";
                won = (winningColor == "Black");
                break;
            case ODD:
                won = isOdd(winningNumber);
                break;
            case EVEN:
                won = !isOdd(winningNumber);
                break;
            case HIGH:
                won = isHigh(winningNumber);
                break;
            case LOW:
                won = !isHigh(winningNumber);
                break;
            case STRAIGHT_UP:
                won = (bet.number == winningNumber);
                payout = bet.amount * 36; // Payout for straight up bet
                break;
            case STREET:
                won = (bet.number <= winningNumber && winningNumber < bet.number + 3);
                payout = bet.amount * 12; // Payout for street bet
                break;
        }
        if (won) {
            std::cout << "Bet won! Payout: $" << payout << std::endl;
            gamePlayer->addBalance(payout);
            gamePlayer->stats.updateStats(payout);
            gamePlayer->stats.rouletteStats.updateStats(true, color);
        } else {
            std::cout << "Bet lost. $" << bet.amount << " gone" << std::endl;
            gamePlayer->stats.updateStats(-bet.amount);
            gamePlayer->stats.rouletteStats.updateStats(false, color);
        }
    }
    // Clear bets after resolving
    bets.clear();
}

void RouletteGame::playRound() {
    std::cout << "Your current balance is: $" << gamePlayer->getBalance() << std::endl;

    placeBet();
    spinWheel();
    resolveBets();
}

bool RouletteGame::isOdd(int number) {
    return number % 2 != 0;
}

bool RouletteGame::isHigh(int number) {
    return number >= 19 && number <= 36;
}

std::string RouletteGame::getColor(int number) {
    // Implement the logic to determine the color of the number
    // For simplicity, let's assume:
    // Red numbers: 1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36
    // Black numbers: 2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35
    // Zero is neither red nor black
    if (number == 0) return "Green";
    int redNumbers[] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
    for (int redNumber : redNumbers) {
        if (number == redNumber) return "Red";
    }
    return "Black";
}

void RouletteGame::startGame() {
    std::cout << "Welcome to the Roulette table!" << std::endl;
}

void RouletteGame::endGame() {
    std::cout << "Thank you for playing Roulette!" << std::endl;
}