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
            return this->victoryPoints + hasLongestArmy();
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
        const vector<DevelopmentCard*>& Player::getDevelopmentCards() {
            return this->developmentCards;
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
            size_t resourceIndex = (size_t)rand() % size;
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

        bool Player::canBuySettelement(){
           if(this->resources[Consts::BRICK] >= 1 && this->resources[Consts::WOOD] >= 1 && this->resources[Consts::WHEAT] >= 1 && this->resources[Consts::SHEEP] >= 1){
               return true;
           }
              cout << "You don't have enough resources to buy a settlement" << endl;
           return false;
            
        }
        void Player::buySettlement(size_t id, bool firstRound){
             if(firstRound){
               this->settlements.push_back(id);
            }
            else if(canBuySettelement()){
                this->resources[Consts::BRICK]--;
                this->resources[Consts::WOOD]--;
                this->resources[Consts::WHEAT]--;
                this->resources[Consts::SHEEP]--;
                this->settlements.push_back(id);
                cout << "You bought a settlement!" << endl;
            }
            
            
        }


        bool Player::canBuyCity(){
            if(this->resources[Consts::ORE] >= 3 && this->resources[Consts::WHEAT] >= 2){
                return true;
            }
            cout << "You don't have enough resources to buy a city" << endl;
            return false;
        }
        void Player::buyCity(size_t id, bool firstRound){
            if(firstRound){
               this->settlements.push_back(id);
            }
            else if(canBuyCity()){
                this->resources[Consts::ORE]-=3;
                this->resources[Consts::WHEAT]-=2;
                this->settlements.push_back(id);
                cout << "You bought a city!" << endl;
            }
            
        }
        bool Player::canBuyRoad(){
            if(this->resources[Consts::BRICK] >= 1 && this->resources[Consts::WOOD] >= 1){

                return true;
            }
            cout << "You don't have enough resources to buy a road" << endl;
            return false;

        }
        void Player::buyRoad(size_t id, bool firstRound){
            if(firstRound){
               this->roads.push_back(id);
            }
            else if(canBuyRoad()){
                this->resources[Consts::BRICK]--;
                this->resources[Consts::WOOD]--;
                this->roads.push_back(id);
                cout << "You bought a road!" << endl;
            }
            
        }
        bool Player::canBuyDevelopmentCard(){
            if(this->resources[Consts::ORE] >= 1 && this->resources[Consts::WHEAT] >= 1 && this->resources[Consts::SHEEP] >= 1){
                return true;
            }
            cout << "You don't have enough resources to buy a development card" << endl;
            return false;
        }
        void Player::buyDevelopmentCard(DevelopmentCard* card){
            this->resources[Consts::ORE]--;
            this->resources[Consts::WHEAT]--;
            this->resources[Consts::SHEEP]--;
            this->developmentCards.push_back(card);
            cout << "You bought a development card! Card drawed: "<< card->getDiscription() << endl;
        }



        

         void Player::tradeResources(Player* player,vector<size_t> resourcesToGive, vector<size_t> resourcesToTake){
            for(size_t i = 0; i < resourcesToGive.size(); i++){
                if(this->resources[i] < resourcesToGive[i] || player->resources[i] < resourcesToTake[i]){
                    throw invalid_argument("Not enough resources to trade");
                }
            }
            for(size_t i = 0; i < resourcesToGive.size(); i++){
                this->resources[i] -= resourcesToGive[i]; //remove the resources from the player who initiated the trade
                player->resources[i]-= resourcesToTake[i]; //remove the resources from the player who accepted the trade
                this->resources[i] += resourcesToTake[i]; //add the resources to the player who initiated the trade
                player->resources[i] += resourcesToGive[i]; //add the resources to the player who accepted the trade
            }
         }
         void Player::tradeDevelopmentCards(Player* player, vector<size_t> cardsToGive, vector<size_t> cardsToTake){
            vector<size_t> availableToGive = {0,0,0,0,0};
            vector<size_t> availableToTake = {0,0,0,0,0};
            for(size_t i = 0; i < this->developmentCards.size(); i++){ //count the amount of each type of card in the player's hand
                if(this->developmentCards[i]->getDiscription() == "Knight"){
                    availableToGive[Consts::KNIGHT]++;
                }
                else if(this->developmentCards[i]->getDiscription() == "VictoryPoint"){
                    availableToGive[Consts::VICTORY_POINT]++;
                }
                else if(this->developmentCards[i]->getDiscription() == "RoadBuilding"){
                    availableToGive[Consts::ROAD_BUILDING]++;
                }
                else if(this->developmentCards[i]->getDiscription() == "Monopoly"){
                    availableToGive[Consts::MONOPOLY]++;
                }
                else if(this->developmentCards[i]->getDiscription() == "YearOfPlenty"){
                    availableToGive[Consts::YEAR_OF_PLENTY]++;
                }
                
            }
             for(size_t i = 0; i < player->developmentCards.size(); i++){ //count the amount of each type of card in the player's hand
                if(player->developmentCards[i]->getDiscription() == "Knight"){
                    availableToGive[Consts::KNIGHT]++;
                }
                else if(this->developmentCards[i]->getDiscription() == "VictoryPoint"){
                    availableToGive[Consts::VICTORY_POINT]++;
                }
                else if(this->developmentCards[i]->getDiscription() == "RoadBuilding"){
                    availableToGive[Consts::ROAD_BUILDING]++;
                }
                else if(this->developmentCards[i]->getDiscription() == "Monopoly"){
                    availableToGive[Consts::MONOPOLY]++;
                }
                else if(this->developmentCards[i]->getDiscription() == "YearOfPlenty"){
                    availableToGive[Consts::YEAR_OF_PLENTY]++;
                }
                
            }
            for(size_t i = 0; i < cardsToGive.size(); i++){   //check if the players has enough cards to trade
                if(availableToGive[i] < cardsToGive[i] || availableToTake[i] < cardsToTake[i]){
                    throw invalid_argument("Not enough development cards to trade");
                }
            }
            for(size_t i = 0; i < cardsToGive.size(); i++){ //iterate over the cards to give and take and trade them
                
                    for(size_t j = 0; j < cardsToGive[i]; j++){ //find the card in the player's hand and trade it
                        size_t cardToGive = findCard(i); 
                        player->developmentCards.push_back(this->developmentCards[cardToGive]);
                        this->developmentCards.erase(this->developmentCards.begin() + (long)cardToGive);
                    }
            }
            for(size_t i = 0; i < cardsToTake.size(); i++){
                
                    for(size_t j = 0; j < cardsToTake[i]; j++){
                        size_t cardToTake = player->findCard(i);
                        this->developmentCards.push_back(player->developmentCards[cardToTake]);
                        player->developmentCards.erase(player->developmentCards.begin() + (long)cardToTake);
                    }
            }
         }

         void Player::printResources(){
             cout << "Player " << this->name << " has the following resources:" << endl;
             for(size_t i = 0; i < this->resources.size(); i++){
                 cout << Consts::RESOURCES[i] << ": " << this->resources[i] << " ";
             }
         }

            void Player::printDevelopmentCards(){
                cout << "Player " << this->name << " has the following development cards:" << endl;
                for(size_t i = 0; i < this->developmentCards.size(); i++){
                    cout << this->developmentCards[i]->getDiscription() << " ";
                }
            }
        size_t Player::findCard(size_t type){//returns the index of the first card in the player's hand with the given type
            for(size_t i = 0; i < this->developmentCards.size(); i++){
                if(this->developmentCards[i]->getType() == type){
                    return i;
                }
            }
            return INT32_MAX;
        }
        size_t Player::hasLongestArmy(){
            for(size_t i = 0; i < this->developmentCards.size(); i++){
                if(this->developmentCards[i]->getDiscription() == "Knight"){
                    return 2;
                }
            }
            return 0;
        }
        




} // namespace ariel
