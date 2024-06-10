#include "../Player.hpp"
#include "../Catan.hpp"
namespace ariel
{

    /**
     * @brief Construct a new Monopoly:: Monopoly object
     * Construct a new Monopoly object
    */
    Monopoly::Monopoly(){
        this->description = "Monopoly";
        this->used = false;
        this->type = 3;
        this->value = 0;   
     } 
    // Override the useCard() method
    /**
     * @brief This function is used to use the Monopoly card
     * @param player the player that uses the card
     * @param game the game that the player is playing
     * @throw invalid_argument if the player is not the current player or if the card has already been used
    */
    void Monopoly::useCard(Player& player, Catan& game){
        if(this->used) {//if the card has already been used, throw an exception
            throw invalid_argument("This card has already been used");
        }
        if(&player!=&game.getCurrentPlayer()) {//if the player is not the current player, throw an exception
            throw invalid_argument("You can only use this card on your turn");
        }
        cout << "Choose a resource to take from all players: 0 for Brick, 1 for Wood, 2 for Wheat, 3 for Sheep, 4 for Ore" << endl; //choose resource to steal
        size_t resource;
        cin >> resource;
        if(resource > 4 || resource < 0 || cin.fail()){ //if the resource is invalid, throw an exception
            throw invalid_argument("Invalid resource");
        }
        for(size_t i = 0; i < Consts::NUM_OF_PLAYERS; i++){ //steal the resource from all players
            size_t amount = 0;
            if(&game.getPlayer(i) != &player){ //if the player to steal from is not the current player
                amount = game.getPlayer(i).stealResource(resource); //steal the resource
                player.addResource(resource, amount); //add the stolen resource to the player
                cout << "You stole " << amount << " " << Consts::RESOURCES[resource] << " from " << game.getPlayer(i).getName() << endl;
            }
        }
        this->used = true; //set the card as used
        this->description = "Monopoly (used)";
    }
}
