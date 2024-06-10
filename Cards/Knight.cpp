#include "../Player.hpp"
#include "../Catan.hpp"
namespace ariel
{
/**
 * @brief Construct a new Knight:: Knight object
 * Construct a new Knight object 
*/
     Knight::Knight(){
        this->description = "Knight";
        this->used = false;
        this->type = 0;
        this->value = 0;   
     } 
    // Override the useCard() method
    /*
    * @brief This function is used to use the Knight card
    * @param player the player that uses the card
    * @param game the game that the player is playing
    * @throw invalid_argument if the player is not the current player or if the player to steal from has no resources
    */
    void Knight::useCard(Player& player, Catan& game){
       if (this->used) //if the card has already been used, throw an exception
       {
           throw "This card has already been used";
       }
         if (&player != &game.getCurrentPlayer()) //if the player is not the current player, throw an exception
         {
              throw "You can only use this card on your turn";
         }

         //choose player to steal from
         cout << "Choose player to steal from: 0 for" << game.getPlayer(0).getName() << " 1 for " << game.getPlayer(1).getName() << " 2 for " << game.getPlayer(2).getName() << " 3 for " << game.getPlayer(3).getName() << endl;
         size_t playerToSteal;
         cin >> playerToSteal;   
            if (playerToSteal > 3 || playerToSteal < 0 || cin.fail()) //if the player to steal from is invalid, throw an exception
            {
                throw invalid_argument("Invalid player");
            }
           if(&(game.getPlayer(playerToSteal)) == &player){ //if the player tries to steal from himself, throw an exception
               throw invalid_argument("You can't steal from yourself");
           }
           if(game.getPlayer(playerToSteal).getResources().size() == 0){ //if the player to steal from has no resources, throw an exception
               if(game.getPlayer(0).getResources().size() == 0 && game.getPlayer(1).getResources().size() == 0 && game.getPlayer(2).getResources().size() ==0){
                   throw invalid_argument("All players have no resources, card cannot be used for now");
               }
               throw invalid_argument("The player you chose has no resources");
           }
           string resource = game.getPlayer(playerToSteal).stealRandomResource(); // steal a random resource from the player
              cout << "You stole 1 " << resource << " from " << game.getPlayer(playerToSteal).getName() << endl;
                player.addResource(Consts::getResourceIndex(resource), 1); //add the stolen resource to the player
            this->used = true; //set the card as used
            this->description = "Knight (used)";
    }
       
    }

