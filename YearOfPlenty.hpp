#include "DevelopmentCard.hpp"
namespace ariel
{
class YearOfPlenty : public DevelopmentCard {
public:
    // Constructor
    YearOfPlenty();
        void useCard(Player& owner, Catan& game);


    // Override the useCard() method
};
}