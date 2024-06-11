#include "../Player.hpp"
#include "../Catan.hpp"
namespace ariel
{
  /**
   * @brief Construct a new RoadBuilding:: RoadBuilding object
   * Construct a new RoadBuilding object
  */
    RoadBuilding::RoadBuilding(){
        this->description = "RoadBuilding";
        this->used = false;
        this->type = 2; 
        this->value = 0;
    }

/**
 * @brief This function is used to use the Road Building card
 * @param player the player that uses the card
 * @param game the game that the player is playing
 * @throw invalid_argument if the player is not the current player or if the player tries to build in an invalid location
*/
    void RoadBuilding::useCard(Player& owner, Catan& game){
        if(this->used) {
            throw invalid_argument("This card has already been used"); //if the card has already been used, throw an exception
        }
        if(&owner!=&game.getCurrentPlayer()) {
            throw invalid_argument("You can only use this card on your turn"); //if the player is not the current player, throw an exception
        }
        cout << "Choose first location to place a road: "; //choose the first location to place a road
        size_t firstLocation;
        cin >> firstLocation;
        cout << "Choose second location to place a road: "; //choose the second location to place a road
        size_t secondLocation;
        cin >> secondLocation;
        //if the locations are invalid, throw an exception, else, if both locations are valid, place the roads and set the card as used
        
        if(game.getBoard().checkValidLocation(firstLocation,Consts::BUILD_ROAD, &owner, false) ){
            game.getBoard().placeRoad(firstLocation, &owner);
            owner.buyRoad(firstLocation, true);
            if(game.getBoard().checkValidLocation(secondLocation,Consts::BUILD_ROAD, &owner, false)){
               game.getBoard().placeRoad(secondLocation, &owner);
               owner.buyRoad(secondLocation, true);
               this->used = true;
              this->description = "RoadBuilding (used)";
              cout << "You have successfully used the Road Building card!" << endl;
            }
            else{
                this->used = true;
                this->description = "RoadBuilding (used)";
                throw invalid_argument("You can't build there! only first road was built. Card is used.");
            }
            
        }
        else{
            throw invalid_argument("You can't build there!");
        }  
    }
};