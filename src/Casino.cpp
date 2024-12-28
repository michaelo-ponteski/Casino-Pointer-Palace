#include <Casino.hpp>

Casino::Casino() : houseBalance(0.0), loggedInPlayer(nullptr) {
    try {
        // Initialize
        std::srand(std::time(nullptr));
        loadData();
        printPlayers();
        loginPlayer();

        // Create games
        Dealer dealer(160, "Main Dealer");
        games.push_back(std::make_unique<RouletteGame>(loggedInPlayer));
        games.push_back(std::make_unique<BlackjackGame>(loggedInPlayer, 10.0, 1000.0, dealer));

        // Main loop
        while (true) {
            playerMenu();
        }
    } catch (const std::exception& e) {
        std::cerr << "An error occurred during initialization: " << e.what() << std::endl;
        exit(1);
    }
}

void Casino::loadData() {
    std::ifstream file("data/casino_data.json");
    if (!file.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
        return;
    }
    try {
        nlohmann::json jsonData;
        file >> jsonData;

        houseBalance = jsonData["balance"].get<double>();

        for (const auto& playerData : jsonData["players"]) {
            std::string name = playerData["name"].get<std::string>();
            double balance = playerData["balance"].get<double>();
            int id = playerData["id"].get<int>();
            addPlayer(std::make_unique<Player>(id, name, balance, true));
        }
    } catch (const std::exception& e) {
        std::cerr << "An error occurred while loading data: " << e.what() << std::endl;
    }
}

void Casino::saveData() {
    try {
        nlohmann::json jsonData;
        jsonData["balance"] = houseBalance;

        for (const auto& player : players) {
            nlohmann::json playerData;
            playerData["id"] = player->getPlayerId();
            playerData["name"] = player->getName();
            playerData["balance"] = player->getBalance();
            jsonData["players"].push_back(playerData);
        }

        std::ofstream file("data/casino_data.json");
        if (!file.is_open()) {
            std::cerr << "Could not open the file!" << std::endl;
            return;
        }
        file << jsonData.dump(4);
        file.close();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred while saving data: " << e.what() << std::endl;
    }
}

void Casino::printPlayers() {
    try {
        std::cout << "Players in the casino: ";
        for (const auto& player : players) {
            std::cout << player->getName() << " ";
        }
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "An error occurred while printing players: " << e.what() << std::endl;
    }
}

void Casino::loginPlayer() {
    try {
        std::string login;
        std::cout << "ENTER YOUR NAME:  ";
        std::cin >> login;
        auto it = std::find_if(players.begin(), players.end(), [&login](const std::unique_ptr<Player>& player) {
            return player->getName() == login;
        });

        if (it != players.end()) {
            loggedInPlayer = it->get();
            std::cout << "Welcome back, " << loggedInPlayer->getName() << "!" << std::endl;
        } else {
            std::cout << "First time here? No problem!" << std::endl;
            std::cout << "What's your initial balance: ";
            double balance;
            while (!(std::cin >> balance) || balance < 0) {
                std::cin.clear(); // clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
                std::cout << "Invalid input. Please enter a positive number: ";
            }
            int newId = players.size() + 1; // Generate a new ID for the player (need to change later)
            loggedInPlayer = new Player(newId, login, balance, true);
            addPlayer(std::unique_ptr<Player>(loggedInPlayer));
            std::cout << "Welcome to the casino, " << loggedInPlayer->getName() << "!" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "An error occurred during login: " << e.what() << std::endl;
    }
}

double Casino::calculateRevenue() {
    return 0.0;
}

void Casino::addPlayer(std::unique_ptr<Player> player) {
    try {
        players.push_back(std::move(player));
    } catch (const std::exception& e) {
        std::cerr << "An error occurred while adding a player: " << e.what() << std::endl;
    }
}

void Casino::removePlayer(const std::string& playerName) {
    try {
        // Find and remove player from players vector
        auto it = std::find_if(players.begin(), players.end(), [&playerName](const std::unique_ptr<Player>& player) {
            return player->getName() == playerName;
        });

        if (it != players.end()) {
            players.erase(it);
            nlohmann::json jsonData;
            std::ifstream file("data/casino_data.json");
            if (file.is_open()) {
                file >> jsonData;
                file.close();

                auto& playersArray = jsonData["players"];
                auto jsonit = std::find_if(playersArray.begin(), playersArray.end(), [&playerName](const nlohmann::json& playerData) {
                    return playerData["name"].get<std::string>() == playerName;
                });

                if (jsonit != playersArray.end()) {
                    playersArray.erase(jsonit);

                    std::ofstream outFile("data/casino_data.json");
                    if (outFile.is_open()) {
                        outFile << jsonData.dump(4);
                        outFile.close();
                    } else {
                        std::cerr << "Could not open the file for writing!" << std::endl;
                    }
                }
            } else {
                std::cerr << "Could not open the file for reading!" << std::endl;
            }
            
        } else {
            std::cout << "Player not found." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "An error occurred while removing a player: " << e.what() << std::endl;
    }
}

std::vector<Game*> Casino::getGameList() const {
    std::vector<Game*> gameList;
    try {
        for (const auto& game : games) {
            gameList.push_back(game.get());
        }
    } catch (const std::exception& e) {
        std::cerr << "An error occurred while getting the game list: " << e.what() << std::endl;
    }
    return gameList;
}

double Casino::getHouseBalance() const {
    return houseBalance;
}

void Casino::playerMenu() {
    try {
        int choice;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Your current balance is: $" << loggedInPlayer->getBalance() << std::endl;
        std::cout << "MENU" << std::endl;
        std::cout << "1. Play Roulette" << std::endl;
        std::cout << "2. Play Blackjack" << std::endl;
        std::cout << "3. View stats" << std::endl;
        std::cout << "4. Add balance" << std::endl;
        std::cout << "5. Delete account" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        while (!(std::cin >> choice) || choice < 1 || choice > 6) {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid input. Please enter a number between 1 and 6: ";
        }
        if (choice == 6) {
            saveData();
            std::cout << "Thank you for playing! Goodbye." << std::endl;
            exit(0);
        }
        if (choice == 5) {
            removePlayer(loggedInPlayer->getName());
            std::cout << "Account deleted. Goodbye." << std::endl;
            exit(0);
        }
        if (choice == 3) {
            int which;
            std::cout << "1. Overall stats" << std::endl;
            std::cout << "2. Roulette stats" << std::endl;
            std::cout << "3. Blackjack stats" << std::endl;
            std::cout << "Enter your choice: ";
            while (!(std::cin >> which) || which < 1 || which > 3) {
                std::cin.clear(); // clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
                std::cout << "Invalid input. Please enter a number between 1 and 3: ";
            }
            switch (which) {
                case 1:
                    std::cout << std::endl << "=== OVERALL STATS ===" << std::endl;
                    loggedInPlayer->stats.printOverallStats();
                    break;
                case 2:
                    std::cout << std::endl << "=== ROULETTE STATS ===" << std::endl;
                    loggedInPlayer->stats.rouletteStats.printSpecificStats();
                    break;
                case 3:
                    std::cout << std::endl << "=== BLACKJACK STATS ===" << std::endl;
                    loggedInPlayer->stats.blackjackStats.printSpecificStats();
                    break;
            }
            return;
        }
        if (choice == 4) {
            double amount;
            std::cout << "Enter the amount to add: ";
            while (!(std::cin >> amount) || amount < 0) {
                std::cin.clear(); // clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
                std::cout << "Invalid input. Please enter a positive number: ";
            }
            loggedInPlayer->addBalance(amount);
            return;
        }
        playGame(choice);
        saveData();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred in the player menu: " << e.what() << std::endl;
    }
}

void Casino::playGame(size_t choice) {
    try {
        Game* game = games.at(choice - 1).get();
        while (true) {
            game->playRound();
            loggedInPlayer->stats.saveToFile();
            std::cout << "ENTER -> play again ,  any other -> MENU" << std::endl;
            // Clear the input buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // any other button means exit
            if (std::cin.get() != '\n') {
                break;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "An error occurred while playing the game: " << e.what() << std::endl;
    }
}

Casino::~Casino() {
    // Destructor
}