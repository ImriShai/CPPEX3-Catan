#include "../Player.hpp"
#include "../Catan.hpp"
namespace ariel
{
    RoadBuilding::RoadBuilding(){
        this->discription = "RoadBuilding";
        this->used = false;
        this->type = 2; 
        this->value = 0;
    }

    void RoadBuilding::useCard(Player& owner, Catan& game){
        if(this->used) {
            throw invalid_argument("This card has already been used");
        }
        if(&owner!=&game.getCurrentPlayer()) {
            throw invalid_argument("You can only use this card on your turn");
        }
        cout << "Choose first location to place a road: ";
        size_t firstLocation;
        cin >> firstLocation;
        cout << "Choose second location to place a road: ";
        size_t secondLocation;
        cin >> secondLocation;
        if(game.getBoard().checkValidLocation(firstLocation,Consts::BUILD_ROAD, &owner, false) && game.getBoard().checkValidLocation(secondLocation,Consts::BUILD_ROAD, &owner, false)){
            game.getBoard().placeRoad(firstLocation, &owner);
            game.getBoard().placeRoad(secondLocation, &owner);
            this->used = true;
            cout << "You have successfully used the Road Building card!" << endl;
        }
        else{
            throw invalid_argument("You can't build there!");
        }  
    }
};