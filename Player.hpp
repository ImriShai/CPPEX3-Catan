#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include "Board.hpp"
using namespace std;
namespace ariel{
class Player{
    private:
        string name;
        vector<string> resources;
        vector<int> resourcesNum;
        vector<string> settlements;
        vector<int> settlementsNum;
        vector<string> roads;
        vector<int> roadsNum;
    public:
        Player(string name);
        void placeSettelemnt(vector<string> places, vector<int> placesNum, Board &board);
        void placeRoad(vector<string> places, vector<int> placesNum, Board &board);
        void rollDice();
        string getName();
        vector<string> getResources();
        vector<int> getResourcesNum();
        vector<string> getSettlements();
        vector<int> getSettlementsNum();
        vector<string> getRoads();
        vector<int> getRoadsNum();
};
}
