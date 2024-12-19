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

    // check if the dealer has a hidden card
    bool hasHiddenCard() const;

    // Get the visible hand value (when firstCardHidden is true)
    int getVisibleValue() const;

    // Reveal the hidden card
    void revealHiddenCard();

    // Hide the first card
    void hideFirstCard();

    // Override prettyPrint to hide the first card if it's hidden
    void prettyPrint() const override;

    // Destructor
    ~DealerHand();
};

#endif // DEALERHAND_HPP