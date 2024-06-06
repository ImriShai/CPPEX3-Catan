#include "../Player.hpp"
#include "../Catan.hpp"
namespace ariel
{
    VictoryPoint::VictoryPoint(){
        this->discription = "VictoryPoint";
        this->used = false;
        this->id = 1;
        this->value = 1;
    }

    void VictoryPoint::useCard(Player& player, Catan& game) {
        if(this->used) {
            throw "This card has already been used";
        }
        if(&player!=&game.getCurrentPlayer()) {
            throw "You can only use this card on your turn";
        }
        player.addVictoryPoints(this->value);
        this->used = true;
    }
    
};