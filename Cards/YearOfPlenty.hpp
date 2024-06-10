#include "DevelopmentCard.hpp"
namespace ariel
{
    /*
     * @brief This class represents a YearOfPlenty card in the game
    */
    class YearOfPlenty : public DevelopmentCard
    {
    public:
        // Constructor
        YearOfPlenty();
        void useCard(Player &owner, Catan &game);

        // Override the useCard() method
    };
}