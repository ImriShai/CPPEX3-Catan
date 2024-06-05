#include "Player.hpp"
#include "Catan.hpp"
namespace ariel
{

     Knight::Knight(){
        this->discription = "Knight";
        this->used = false;
        this->id = 1;
        this->value = 0;   
     } 
    // Override the useCard() method
    void Knight::useCard(Player& player, Catan& game){
        // Implement the logic for using the Knight development card
        // ...
    }
}
