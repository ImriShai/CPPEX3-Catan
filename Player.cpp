#include "Player.hpp"
using namespace std;
namespace ariel
{
       
        Player::Player(string name, size_t age){
            if(name.empty()){
                throw invalid_argument("Name cannot be empty");
            }
            if(age < 0){
                throw invalid_argument("Age cannot be negative");
            }
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
        
        string Player::getName() const{
            return this->name;
        }
        const vector<size_t>& Player::getResources() const{
            return this->resources;
        }
        const vector<size_t>& Player::getSettelments() const{
            return this->settlements;
        }
        const vector<size_t>& Player::getRoads() const{
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
        size_t Player::getNumResources() const{
            size_t sum = 0;
            for(size_t i : this->resources){
                sum += i;
            }
            return sum;
        }

        string Player::stealRandomResource() { //Look at the cards as a vector, each card has one spot in the vector, the amount of cards is the sum of resources in the player resources vector
        //then choose a random number between 0 and the size of the vector, if the number is smaller than the amount of brick cards, it means were still at the brick cards in the original vector, so we remove one brick card
        //else, we subtract the amount of brick cards from the random number and check if its smaller than the amount of wood cards, if so, we remove one wood card, and so on
            
            size_t size = this->resources.size();
            size_t resourceIndex = rand() % size;
            if(this->resources[Consts::BRICK] >= resourceIndex){
                this->resources[Consts::BRICK]--;
                return "BRICK";
            }
            resourceIndex-= this->resources[Consts::BRICK];
            if(this->resources[Consts::WOOD] >= resourceIndex){
                this->resources[Consts::WOOD]--;
                return "WOOD";
        }
        resourceIndex-= this->resources[Consts::WOOD];
        if(this->resources[Consts::WHEAT] >= resourceIndex){
            this->resources[Consts::WHEAT]--;
            return "WHEAT";
        }
        resourceIndex-= this->resources[Consts::WHEAT];
        if(this->resources[Consts::SHEEP] >= resourceIndex){
            this->resources[Consts::SHEEP]--;
            return "SHEEP";
        }
        resourceIndex-= this->resources[Consts::SHEEP];
        if(this->resources[Consts::ORE] >= resourceIndex){
            this->resources[Consts::ORE]--;
            return "ORE";
        }
        return "ERROR";
}
        size_t Player::stealResource(size_t resource){
            if(resource < 0 || resource > 4){
                throw invalid_argument("Resource must be between 0 and 4");
            }
            size_t amount = this->resources[resource];
            this->resources[resource] = 0;
            return amount;
        }
        const Player& Player::getPlayer(){
            return *this;
        }
} // namespace ariel
