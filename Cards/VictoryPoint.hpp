#include "DevelopmentCard.hpp"
namespace ariel
{
/**
 * @brief This class represents a VictoryPoint card in the game
 * 
 */
class VictoryPoint : public DevelopmentCard {
public:
    // Constructor
    VictoryPoint();
        void useCard(Player& owner, Catan& game);


    // Override the useCard() method
    
};
}