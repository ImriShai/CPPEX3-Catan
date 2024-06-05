#include "DevelopmentCard.hpp"
namespace ariel
{
class RoadBuilding : public DevelopmentCard {
public:
    // Constructor
    RoadBuilding();

    // Override the useCard() method
    void useCard() override;
    
};
}