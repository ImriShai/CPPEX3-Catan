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
        vector<size_t> resources = {0,0,0,0,0};
        vector<Settelments*> settlements;
        vector<Road*> roads;
        size_t victoryPoints;
    public:
        Player(string name);
        void placeSettelemnt(size_t id,Board &board);
        void placeRoad(size_t id, Board &board);
        void rollDice();
        string getName();
        vector<size_t> getResources();
        vector<Settelments*> getSettelments();
        vector<Road*> getRoads();
        size_t getVictoryPoints();
        void addResource(size_t resource);
};
}
