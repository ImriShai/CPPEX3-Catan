#include "../Player.hpp"
#include "../Catan.hpp"
namespace ariel
{
    Monopoly::Monopoly(){
        this->discription = "Monopoly";
        this->used = false;
        this->type = 3;
        this->value = 0;   
     } 
    // Override the useCard() method
    void Monopoly::useCard(Player& player, Catan& game){
        if(this->used) {
            throw invalid_argument("This card has already been used");
        }
        if(&player!=&game.getCurrentPlayer()) {
            throw invalid_argument("You can only use this card on your turn");
        }
        cout << "Choose a resource to take from all players: 0 for Brick, 1 for Wood, 2 for Wheat, 3 for Sheep, 4 for Ore" << endl;
        size_t resource;
        cin >> resource;
        if(resource > 4 || resource < 0 || cin.fail()){
            throw invalid_argument("Invalid resource");
        }
        for(size_t i = 0; i < Consts::NUM_OF_PLAYERS; i++){
            size_t amount = 0;
            if(&game.getPlayer(i) != &player){
                amount = game.getPlayer(i).stealResource(resource);
                player.addResource(resource, amount);
                cout << "You stole " << amount << " " << Consts::RESOURCES[resource] << " from " << game.getPlayer(i).getName() << endl;
            }
        }
        this->used = true;
    }
}
