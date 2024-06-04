#include "DevelopmentCard.hpp"
namespace ariel
{
class RoadBuilding : public DevelopmentCard {
public:
    // Constructor
    RoadBuildng(){
        this->discription = "RoadBuilding";
        this->isUsed = false;
        this->id = 1;
        this->value = 0;
        this->owner = nullptr;
    }

    // Override the useCard() method
    void useCard() override {
        // Implement the logic for using the Knight development card
        // ...
    }
    
};
}