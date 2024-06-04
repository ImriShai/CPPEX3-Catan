#include "DevelopmentCard.hpp"
namespace ariel
{
class VictoryPoint : public DevelopmentCard {
public:
    // Constructor
    VictoryPoint(){
        this->discription = "VictoryPoint";
        this->isUsed = false;
        this->id = 1;
        this->value = 1;
        this->owner = nullptr;
    }

    // Override the useCard() method
    void useCard() override {
        // Implement the logic for using the Knight development card
        // ...
    }
    
};
}