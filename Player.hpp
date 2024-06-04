#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include "Board.hpp"
#include "Settelment.hpp"
#include "Road.hpp" 


using namespace std;
namespace ariel{
class Player{
    private:
        string name;
        size_t age;
        vector<size_t> resources = {0,0,0,0,0}; // {wood, brick, wheat, sheep, ore}
        vector<size_t> settlements;
        vector<size_t> roads;
        vector<DevelopmentCard*> developmentCards;
        size_t victoryPoints;
    public:
        Player(string name, size_t age);
        void placeSettelement(size_t id,Board &board);//id is the index of the Settelement in the board tiles vector
        void placeCity(size_t id, Board &board);//id is the index of the City in the board tiles vector
        void placeRoad(size_t id, Board &board);//id is the index of the Road in the board tiles vector
        void playDevelopmentCard(size_t id);//id is the index of the card in the developmentCards vector
        DevelopmentCard* buyDevelopmentCard();
        
        string getName();
        const vector<size_t> &getResources();
        const vector<size_t> &getSettelments();
        const vector<size_t> &getRoads();
        size_t getVictoryPoints();
        void addResource(size_t resource, size_t amount);
        void removeResource(size_t resource, size_t amount);

};
}
