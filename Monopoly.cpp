#include "DevelopmentCard.hpp"
namespace ariel
{
class Monopoly : public DevelopmentCard {
public:
    // Constructor
    Monopoly(){
        this->discription = "Monopoly";
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