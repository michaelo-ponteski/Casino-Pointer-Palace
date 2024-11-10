#ifndef DEALERHAND_HPP
#define DEALERHAND_HPP

#include "BlackjackHand.hpp"
#include "Dealer.hpp"
#include <vector>

class DealerHand : public BlackjackHand {
private:
    bool firstCardHidden;  // To implement hole card rule

public:
    // Constructor - pass nullptr as Player* since dealer isn't a player
    DealerHand(Dealer* dealer);

    // Dealer specific
    bool shouldHit() const;  // Determines if the dealer should hit or stand

    // Get the card(s) - overridden to return the visible card or both
    std::vector<Card> getCards();

    // Get the visible hand value (when firstCardHidden is true)
    int getVisibleValue() const;

    // Reveal the hidden card
    void revealHiddenCard();

    // Destructor
    ~DealerHand();
};

#endif // DEALERHAND_HPP