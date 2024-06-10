#include "../Player.hpp"
#include "../Catan.hpp"
namespace ariel
{
   
     /**
      * @brief Construct a new Victory Point:: Victory Point object
     */
    VictoryPoint::VictoryPoint(){
        this->description = "VictoryPoint";
        this->used = false;
        this->type = 1;
        this->value = 1;
    }
/**
 * @brief This method is used to use the Victory Point card
 * @param player - the player who uses the card
 * @param game - the game that the player is playing
 * @throw invalid_argument if the player is not the current player or if the card has already been used
*/
    void VictoryPoint::useCard(Player& player, Catan& game) {
        if(this->used) { //if the card has already been used, throw an exception
            throw invalid_argument("This card has already been used");
        }
        if(&player!=&game.getCurrentPlayer()) { //if the player is not the current player, throw an exception
            throw invalid_argument("You can only use this card on your turn");
        }
        player.addVictoryPoints(this->value); //add the victory points to the player
        this->used = true;//set the card as used
        this->description = "VictoryPoint (used)";
        cout << "You have successfully used the Victory Point card!" << endl;
        cout << "You now have " << player.getVictoryPoints() << " victory points" << endl; //print the player's victory points
    }
    
};