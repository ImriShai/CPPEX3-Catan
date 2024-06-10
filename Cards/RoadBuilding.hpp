#include "DevelopmentCard.hpp"
namespace ariel
{
/**
 * @brief This class represents a RoadBuilding card in the game
 * 
 */
class RoadBuilding : public DevelopmentCard {
public:
    // Constructor
    RoadBuilding();
        void useCard(Player& owner, Catan& game);


    // Override the useCard() method
    
};
}