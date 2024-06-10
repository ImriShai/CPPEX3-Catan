#include "../Player.hpp"
#include "../Catan.hpp"
namespace ariel
{
    VictoryPoint::VictoryPoint(){
        this->discription = "VictoryPoint";
        this->used = false;
        this->type = 1;
        this->value = 1;
    }

    void VictoryPoint::useCard(Player& player, Catan& game) {
        if(this->used) {
            throw invalid_argument("This card has already been used");
        }
        if(&player!=&game.getCurrentPlayer()) {
            throw invalid_argument("You can only use this card on your turn");
        }
        player.addVictoryPoints(this->value);
        this->used = true;
        cout << "You have successfully used the Victory Point card!" << endl;
        cout << "You now have " << player.getVictoryPoints() << " victory points" << endl;
    }
    
};