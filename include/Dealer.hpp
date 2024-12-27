#ifndef DEALER_HPP
#define DEALER_HPP

#include <string>

class Dealer {
private:
    int dealerId;            // Unique identifier for the dealer
    std::string name;        // Dealer's name
    bool isAvailable;        // Availability status of the dealer

public:
    // Constructor
    Dealer(int id, const std::string& dealerName);

    // Sets dealer availability
    void setAvailability(bool availability);

    // Checks if the dealer is available
    bool getAvailability() const;

    // Getters
    int getDealerId() const;
    std::string getName() const;

    // Destructor
    ~Dealer();
};

#endif // DEALER_HPP
