#include "Player.hpp"
using namespace std;
namespace ariel{

        Player(string name, size_t age){
            this->name = name;
            this->age = age;
            this->victoryPoints = 0;
            this->settlements = {};
            this->roads = {};
            this->developmentCards = {};
        }
        void placeSettelement(size_t id,Board &board){
            if(id<1||id>54){
                throw invalid_argument("id must be between 1 and 54");
            }
            if(this->resources[0] < 1 || this->resources[1] < 1 || this->resources[2] < 1 || this->resources[3] < 1){
                throw invalid_argument("Not enough resources to place a settlement");
            }
            
        }
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


}
