#include "Player.hpp"
using namespace std;
namespace ariel
{
        Player::Player(){
            this->name = "";
            this->age = 0;
            this->victoryPoints = 0;
            this->settlements = {};
            this->roads = {};
            this->developmentCards = {};
        }
        Player::Player(string name, size_t age){
            this->name = name;
            this->age = age;
            this->victoryPoints = 0;
            this->settlements = {};
            this->roads = {};
            this->developmentCards = {};
        }
            bool Player::placeSettelement(size_t id){
            if(id<1||id>54){
                throw invalid_argument("id must be between 1 and 54");
            }
            if(this->resources[0] < 1 || this->resources[1] < 1 || this->resources[2] < 1 || this->resources[3] < 1){
                throw invalid_argument("Not enough resources to place a settlement");
            }
            return true;

        }
        void placeCity(size_t id);//id is the index of the City in the board tiles vector
        void placeRoad(size_t id);//id is the index of the Road in the board tiles vector
        void playDevelopmentCard(size_t id);//id is the index of the card in the developmentCards vector
        DevelopmentCard* buyDevelopmentCard();
        
        string Player::getName(){
            return this->name;
        }
        const vector<size_t>& Player::getResources(){
            return this->resources;
        }
        const vector<size_t>& Player::getSettelments(){
            return this->settlements;
        }
        const vector<size_t>& Player::getRoads(){
            return this->roads;
        }
        size_t Player::getVictoryPoints(){
            return this->victoryPoints;
        }

        void Player::addVictoryPoints(size_t amount){
            this->victoryPoints += amount;
        }
        void Player::setColor(string color){
            this->color = color;
        }
        string Player::getColor(){
            return this->color;
        }
        Player::~Player(){
            this->settlements.clear();
            this->roads.clear();
            this->developmentCards.clear();
        }
        size_t Player::getAge() const{
            return this->age;
        }
        void Player::addResource(size_t resource, size_t amount){
            if (resource < 0 || resource > 4 || amount < 0)
            {
                throw invalid_argument("Resource must be between 0 and 4");
            }
            this->resources[resource] += amount;
        }
            void Player::removeResource(size_t resource, size_t amount){
            if (resource < 0 || resource > 4 || amount < 0)
            {
                throw invalid_argument("Resource must be between 0 and 4");
            }
            if(this->resources[resource] < amount){
                throw invalid_argument("Not enough resources to remove");
            }
            this->resources[resource] -= amount;
}
}
