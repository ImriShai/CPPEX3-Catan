#include "../Player.hpp"
#include "../Catan.hpp"
namespace ariel
{
    Monopoly::Monopoly(){
        this->discription = "Monopoly";
        this->used = false;
        this->id = 1;
        this->value = 0;   
     } 
    // Override the useCard() method
    void Monopoly::useCard(Player& player, Catan& game){
        // Implement the logic for using the Knight development card
        // ...
    }
}
