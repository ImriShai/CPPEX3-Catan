#include "../Player.hpp"
#include "../Catan.hpp"
namespace ariel
{
    RoadBuilding::RoadBuilding(){
        this->discription = "RoadBuilding";
        this->used = false;
        this->id = 1;
        this->value = 0;
    }

    void RoadBuilding::useCard(Player& owner, Catan& game){
        // Implement the logic for using the Knight development card
        // ...
    }
    
};