#include "../Player.hpp"
#include "../Catan.hpp"
namespace ariel
{

     Knight::Knight(){
        this->discription = "Knight";
        this->used = false;
        this->type = 0;
        this->value = 0;   
     } 
    // Override the useCard() method
    void Knight::useCard(Player& player, Catan& game){
       if (this->used)
       {
           throw "This card has already been used";
       }
         if (&player != &game.getCurrentPlayer())
         {
              throw "You can only use this card on your turn";
         }
         cout << "Choose player to steal from: 0 for" << game.getPlayer(0).getName() << " 1 for " << game.getPlayer(1).getName() << " 2 for " << game.getPlayer(2).getName() << " 3 for " << game.getPlayer(3).getName() << endl;
         size_t playerToSteal;
         cin >> playerToSteal;   
            if (playerToSteal > 3 || playerToSteal < 0 || cin.fail())
            {
                throw invalid_argument("Invalid player");
            }
           if(&(game.getPlayer(playerToSteal)) == &player){
               throw invalid_argument("You can't steal from yourself");
           }
           if(game.getPlayer(playerToSteal).getResources().size() == 0){
               throw invalid_argument("The player you chose has no resources");
           }
           string resource = game.getPlayer(playerToSteal).stealRandomResource();
              cout << "You stole 1 " << resource << " from " << game.getPlayer(playerToSteal).getName() << endl;
                player.addResource(Consts::getResourceIndex(resource), 1);
            this->used = true;
    }
       
    }

