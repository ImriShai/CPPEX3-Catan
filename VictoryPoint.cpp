#include "Player.hpp"
#include "Catan.hpp"
namespace ariel
{
    VictoryPoint::VictoryPoint(){
        this->discription = "VictoryPoint";
        this->used = false;
        this->id = 1;
        this->value = 1;
    }

    void VictoryPoint::useCard(Player& player, Catan& game) {
        // Implement the logic for using the Knight development card
        // ...
    }
    
};