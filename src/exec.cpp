#include <iostream>
#include <stdexcept>
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


void runCasino() {
    Casino casino;
}


int main() {
    printASCIIart();
    runCasino();
    return 0;
}