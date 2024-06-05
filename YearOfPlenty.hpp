#include "DevelopmentCard.hpp"
namespace ariel
{
class YearOfPlenty : public DevelopmentCard {
public:
    // Constructor
    YearOfPlenty();

    // Override the useCard() method
    void useCard(Player& player) override;
};
}