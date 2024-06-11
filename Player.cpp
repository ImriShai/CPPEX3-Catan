#include "Player.hpp"
using namespace std;

namespace ariel
{
    /**
     * @brief Construct a new Player:: Player object
     * Construct a new Player object
     * @param name the name of the player
     * @param age the age of the player
     * @throw invalid_argument if the name is empty or if the age is negative
     */
    Player::Player(string name, size_t age)
    {
        if (name.empty())
        {
            throw invalid_argument("Name cannot be empty");
        }
        if (age < 0)
        {
            throw invalid_argument("Age cannot be negative");
        }
        this->name = name;
        this->age = age;
        this->victoryPoints = 0;
        this->settlements = {};
        this->roads = {};
        this->developmentCards = {};
        this->resources = {0, 0, 0, 0, 0};
    }

/**
 * @brief Returns the name of the player
 * @return string the name of the player
 */
    string Player::getName() const
    {
        return this->name;
    }
    /**
     * @brief Returns the resources of the player
     * @return const vector<size_t>& the resources of the player
    */
    const vector<size_t> &Player::getResources() const
    {
        return this->resources;
    }
    /**
     * @brief Returns the settlements of the player
     * @return const vector<size_t>& the settlements of the player
    */
    const vector<size_t> &Player::getSettelments() const
    {
        return this->settlements;
    }

    /**
     * @brief Returns the roads of the player
     * @return const vector<size_t>& the roads of the player
    */
    const vector<size_t> &Player::getRoads() const
    {
        return this->roads;
    }

    /**
     * @brief Returns the victory points of the player
     * @return size_t the victory points of the player
    */
    size_t Player::getVictoryPoints()
    {
        return this->victoryPoints + hasLongestArmy() + getVictoryPointCards(); // add the victory points from the development cards, and the longest army points if exists
    }

/**
 * @brief Returns the victory point cards of the player, that been used
 */
    size_t Player::getVictoryPointCards()
    {
        size_t sum = 0;
        for (size_t i = 0; i < this->developmentCards.size(); i++) //itesrate over the development cards and count the amount of victory point cards that already active
        {
            if (this->developmentCards[i]->getDescription() == "VictoryPoint (used)") //
            {
                sum += this->developmentCards[i]->getValue();
            }
        }
        return sum;
    }
/**
 * @brief Add victory points to the player
 * @param amount the amount of victory points to add
 * @throw invalid_argument if the amount is negative
 */
    void Player::addVictoryPoints(size_t amount)
    {
        this->victoryPoints += amount;
    }
    /**
     * @brief Set the color of the player
     * @param color the color of the player
     */
    void Player::setColor(string color)
    {
        this->color = color;
    }
    /**
     * @brief Returns the color of the player
     * @return string the color of the player
     */
    string Player::getColor()
    {
        return this->color;
    }

    /**
     * @brief Destroy the Player:: Player object
     */
    Player::~Player()
    {
        this->settlements.clear();
        this->roads.clear();
        this->developmentCards.clear();
    }
    /**
     * @brief Returns the age of the player
     * @return size_t the age of the player
     */
    size_t Player::getAge() const
    {
        return this->age;
    }

    /**
     * @brief Returns the development cards of the player
     * @return const vector<DevelopmentCard*>& the development cards of the player
     */
    const vector<DevelopmentCard *> &Player::getDevelopmentCards()
    {
        return this->developmentCards;
    }


    /**
     * @brief Add resources to the player
     * @param resource the resource to add
     * @param amount the amount of the resource to add
     * @throw invalid_argument if the resource is not between 0 and 4 or if the amount is negative
     */
    void Player::addResource(size_t resource, size_t amount)
    {
        if (resource == Consts::DESERT) // the desert card is not a resource
        {
            cout << "DESERT" << endl;
            return;
        }
        if (resource < 0 || resource > 4 || amount < 0) // check if the resource is valid
        {
            throw invalid_argument("Resource must be between 0 and 4 with non-negative amount");
        }
        this->resources[resource] += amount; // add the resource to the player
    }

    /**
     * @brief Remove resources from the player
     * @param resource the resource to remove
     * @param amount the amount of the resource to remove
     * @throw invalid_argument if the resource is not between 0 and 4 or if the amount is negative or if the player doesn't have enough resources to remove
     */
    void Player::removeResource(size_t resource, size_t amount)
    {
        if (resource < 0 || resource > 4 || amount < 0) // check if the resource is valid and the amount is non-negative
        {
            throw invalid_argument("Resource must be between 0 and 4 with non-negative amount");
        }
        if (this->resources[resource] < amount) // check if the player has enough resources to remove
        {
            throw invalid_argument("Not enough resources to remove");
        }
        this->resources[resource] -= amount; // remove the resource from the player
    }

    /**
     * @brief Returns the number of resources the player has
     * @return size_t the number of resources the player has
     */
    size_t Player::getNumResources() const
    {
        size_t sum = 0;
        for (size_t i : this->resources) // iterate over the resources and count the amount of each resource
        {
            sum += i;
        }
        return sum;
    }

/**
 * @brief This method is used to steal a random resource from the player, for the knight card
 * @return string the resource that was stolen
 * by using this implementation, we can steal a random resource from the player with same probability for each resource.  
    EXAMPLE: if the player has 2 brick cards, 1 wood card, 3 wheat cards, 1 sheep card, and 2 ore cards, the vector will look like this: [BRICK, BRICK, WOOD, WHEAT, WHEAT, WHEAT, SHEEP, ORE, ORE].
    then we choose a random number between 0 and 8, and return the resource at that index in the vector.
    Lets say we choose 5, the resource at index 5 is "WHEAT", so we return "WHEAT".
 */
    string Player::stealRandomResource()
    { 
        size_t size = this->getNumResources(); // get the amount of resources the player has
        if(size==0){
            throw invalid_argument("No resources to steal");
        }
        size_t resourceIndex = (size_t)rand() % size;// choose a random number between 0 and the amount of resources the player has -1
        vector<string> resources(size);
        for(size_t i = 0; i < this->resources.size(); i++){ // iterate over the resources and add the resource to the vector the amount of times the player has that resource
            for(size_t j = 0; j < this->resources[i]; j++){
                resources.push_back(Consts::RESOURCES[i]);
            }
        }
        return resources[resourceIndex]; // return the resource at the random index. 
    }


/**
 * @brief This method is used to steal a specific resource from the player, for the monopoly card
 * @param resource the resource to steal
 * @return the amount of resources stolen
 */
    size_t Player::stealResource(size_t resource)
    {
        if (resource < 0 || resource > 4) //if the resource is invalid, throw an exception
        {
            throw invalid_argument("Resource must be between 0 and 4");
        }
        size_t amount = this->resources[resource]; //get the amount of the resource the player has
        this->resources[resource] = 0; //remove the resource from the player
        return amount; //return the amount of resources stolen
    }

    /**
     * @brief Returns the player
     * @return const Player& the player
     */
    const Player &Player::getPlayer()
    {
        return *this;
    }
/**
 * @brief This method is used to buy a settlement
 * @return true if the player can buy a settlement in terms of resources, false otherwise
 */
    bool Player::canBuySettelement()
    {
        if (this->resources[Consts::BRICK] >= 1 && this->resources[Consts::WOOD] >= 1 && this->resources[Consts::WHEAT] >= 1 && this->resources[Consts::SHEEP] >= 1)
        {
            return true;
        }
        cout << "You don't have enough resources to buy a settlement" << endl;
        return false;
    }

    /**
     * @brief This method is used to buy a settlement
     * @param id the id of the settlement to buy
     * @param firstRound if it's the first round of the game, no resources needed
     */
    void Player::buySettlement(size_t id, bool firstRound)
    {
        if (firstRound) //if it is the first round, the player can buy a settlement without resources
        {
            this->settlements.push_back(id); //add the settlement to the player
            this->addVictoryPoints(1); //add a victory point to the player
        }
        else if (canBuySettelement()) //if the player can buy a settlement in terms of resources
        {
            this->resources[Consts::BRICK]--; //remove the resources from the player
            this->resources[Consts::WOOD]--;
            this->resources[Consts::WHEAT]--;
            this->resources[Consts::SHEEP]--;
            this->settlements.push_back(id);//add the settlement to the player
            this->addVictoryPoints(1); //add a victory point to the player
            cout << "You bought a settlement!" << endl;
        }
    }
/**
 * @brief This method is used to upgrade a settlement to a city
 * @return true if the player can upgrade the settlement to a city in terms of resources, false otherwise
 */
    bool Player::canBuyCity()
    {
        if (this->resources[Consts::ORE] >= 3 && this->resources[Consts::WHEAT] >= 2) //check if the player has enough resources to buy a city and return true if so
        {
            return true;
        }
        cout << "You don't have enough resources to buy a city" << endl;
        return false; //return false if the player doesn't have enough resources
    }


    /**
     * @brief This method is used to upgrade a settlement to a city
     * @param id the id of the settlement to upgrade. Dosen't actually change the settelment itself, the board does this, the player just needs holds a list of the settelments and cities he has
     */
    void Player::buyCity(size_t id)
    {

        if (canBuyCity())
        { 
            this->resources[Consts::ORE] -= 3; //remove the resources from the player
            this->resources[Consts::WHEAT] -= 2;
            cout << "You bought a city!" << endl;
            this->addVictoryPoints(1); //add a victory point to the player
        }
    }

    /**
     * @brief This method is used to buy a road
     * @return true if the player can buy a road in terms of resources, false otherwise
     */
    bool Player::canBuyRoad()
    {
        if (this->resources[Consts::BRICK] >= 1 && this->resources[Consts::WOOD] >= 1)
        {
            return true;
        }
        cout << "You don't have enough resources to buy a road" << endl;
        return false;
    }

    /**
     * @brief This method is used to buy a road
     * @param id the id of the road to buy
     * @param firstRound if it's the first round of the game, no resources needed
     */
    void Player::buyRoad(size_t id, bool firstRound)
    {
        if (firstRound) //if it is the first round, the player can buy a road without resources
        {
            this->roads.push_back(id);
        }
        else if (canBuyRoad()) //if the player can buy a road in terms of resources
        {
            this->resources[Consts::BRICK]--; //remove the resources from the player
            this->resources[Consts::WOOD]--;
            this->roads.push_back(id);
            cout << "You bought a road!" << endl;
        }
    }

    /**
     * @brief This method is used to buy a development card
     * @return true if the player can buy a development card in terms of resources, false otherwise
     */
    bool Player::canBuyDevelopmentCard()
    {
        if (this->resources[Consts::ORE] >= 1 && this->resources[Consts::WHEAT] >= 1 && this->resources[Consts::SHEEP] >= 1)
        {
            return true;
        }
        return false;
    }

    /**
     * @brief This method is used to buy a development card
     * @param card the card to buy
     * The function removes the resources from the player and adds the card to the player's hand. This function is called by the game when the player buys a development card, and only if the player can buy a development card.
     */
    void Player::buyDevelopmentCard(DevelopmentCard *card) 
    { 
        if(!canBuyDevelopmentCard()){
            throw invalid_argument("Not enough resources to buy a development card");  
        }
        this->resources[Consts::ORE]--;
        this->resources[Consts::WHEAT]--;
        this->resources[Consts::SHEEP]--;
        this->developmentCards.push_back(card);
        cout << "You bought a development card! Card drawed: " << card->getDescription() << endl;
    }

    /**
     * @brief This method is used to trade resources with another player
     * @param player the player to trade with
     * @param resourcesToGive the resources to give
     * @param resourcesToTake the resources to take
     * @throw invalid_argument if the player doesn't have enough resources to trade
     */
    void Player::tradeResources(Player *player, vector<size_t> resourcesToGive, vector<size_t> resourcesToTake)
    {
        for (size_t i = 0; i < resourcesToGive.size(); i++) // check if the players has enough resources to trade
        {
            if (this->resources[i] < resourcesToGive[i] || player->resources[i] < resourcesToTake[i])
            {
                throw invalid_argument("Not enough resources to trade");
            }
        }
        for (size_t i = 0; i < resourcesToGive.size(); i++) // iterate over the resources to give and take and trade them
        {
            this->resources[i] -= resourcesToGive[i];   // remove the resources from the player who initiated the trade
            player->resources[i] -= resourcesToTake[i]; // remove the resources from the player who accepted the trade
            this->resources[i] += resourcesToTake[i];   // add the resources to the player who initiated the trade
            player->resources[i] += resourcesToGive[i]; // add the resources to the player who accepted the trade
        }
    }

    /**
     * @brief This method is used to trade development cards with another player
     * @param player the player to trade with
     * @param cardsToGive the cards to give
     * @param cardsToTake the cards to take
     * @throw invalid_argument if the player doesn't have enough development cards to trade
     */
    void Player::tradeDevelopmentCards(Player *player, vector<size_t> cardsToGive, vector<size_t> cardsToTake)
    {
        vector<size_t> availableToGive = {0, 0, 0, 0, 0};
        vector<size_t> availableToTake = {0, 0, 0, 0, 0};
        for (size_t i = 0; i < this->developmentCards.size(); i++) //counts the number of cards that avaliable to give and take from each type
        { // count the amount of each type of card in the player's hand
            if (this->developmentCards[i]->getDescription() == "Knight")
            {
                availableToGive[Consts::KNIGHT]++;
            }
            else if (this->developmentCards[i]->getDescription() == "VictoryPoint")
            {
                availableToGive[Consts::VICTORY_POINT]++;
            }
            else if (this->developmentCards[i]->getDescription() == "RoadBuilding")
            {
                availableToGive[Consts::ROAD_BUILDING]++;
            }
            else if (this->developmentCards[i]->getDescription() == "Monopoly")
            {
                availableToGive[Consts::MONOPOLY]++;
            }
            else if (this->developmentCards[i]->getDescription() == "YearOfPlenty")
            {
                availableToGive[Consts::YEAR_OF_PLENTY]++;
            }
        }
        for (size_t i = 0; i < player->developmentCards.size(); i++)
        { // count the amount of each type of card in the player's hand
            if (player->developmentCards[i]->getDescription() == "Knight")
            {
                availableToGive[Consts::KNIGHT]++;
            }
            else if (this->developmentCards[i]->getDescription() == "VictoryPoint")
            {
                availableToGive[Consts::VICTORY_POINT]++;
            }
            else if (this->developmentCards[i]->getDescription() == "RoadBuilding")
            {
                availableToGive[Consts::ROAD_BUILDING]++;
            }
            else if (this->developmentCards[i]->getDescription() == "Monopoly")
            {
                availableToGive[Consts::MONOPOLY]++;
            }
            else if (this->developmentCards[i]->getDescription() == "YearOfPlenty")
            {
                availableToGive[Consts::YEAR_OF_PLENTY]++;
            }
        }
        for (size_t i = 0; i < cardsToGive.size(); i++) //check if the players has teh cards to trade
        { // check if the players has enough cards to trade
            if (availableToGive[i] < cardsToGive[i] || availableToTake[i] < cardsToTake[i])
            {
                throw invalid_argument("Not enough development cards to trade");
            }
        }
        for (size_t i = 0; i < cardsToGive.size(); i++) 
        { // iterate over the cards to give and take and trade them

            for (size_t j = 0; j < cardsToGive[i]; j++)
            { // for each type of card, find the first card in the player's hand, that is of the same type and trade it
                size_t cardToGive = findCard(i); //no need to check return value, we check before that such card exists
                player->developmentCards.push_back(this->developmentCards[cardToGive]);
                this->developmentCards.erase(this->developmentCards.begin() + (long)cardToGive);
            }
        }
        for (size_t i = 0; i < cardsToTake.size(); i++) //do the same as above but for the other player
        {
            for (size_t j = 0; j < cardsToTake[i]; j++) //notice that because we find the first card of the type, we won't take a card we just got from the other player
            {
                size_t cardToTake = player->findCard(i);
                this->developmentCards.push_back(player->developmentCards[cardToTake]);
                player->developmentCards.erase(player->developmentCards.begin() + (long)cardToTake);
            }
        }
    }


    /**
     * @brief This method is used to print the resources of the player
     */
    void Player::printResources()
    {
        cout << "Player " << this->name << " has the following resources:" << endl;
        for (size_t i = 0; i < this->resources.size(); i++) //iterate over the resources and print the amount of each resource
        {
            cout << Consts::RESOURCES[i] << ": " << this->resources[i] << ", ";
        }
        cout << endl;
    }


    /**
     * @brief This method is used to print the development cards of the player
     */
    void Player::printDevelopmentCards()
    {
        cout << "Player " << this->name << " has the following development cards: ";
        for (size_t i = 0; i < this->developmentCards.size(); i++) //iterate over the development cards and print the description of each card
        {
            cout << i << ": " << this->developmentCards[i]->getDescription() << " ";
        }
        cout << endl;
    }


    /**
     * @brief This method is used to find a card in the player's hand
     * @param type the type of the card to find
     * @return size_t the index of the card in the player's hand
     */
    size_t Player::findCard(size_t type)
    { // returns the index of the first card in the player's hand with the given type
        for (size_t i = 0; i < this->developmentCards.size(); i++)
        {
            if (this->developmentCards[i]->getType() == type)
            {
                return i;
            }
        }
        return INT32_MAX; //if the card is not found, return a large number as an error
    }

    /**
     * @brief This method is used to check if the player has the longest army
     * @return size_t 2 if the player has the longest army, 0 otherwise
     */
    size_t Player::hasLongestArmy()
    {
        for (size_t i = 0; i < this->developmentCards.size(); i++) //iterate over the development cards and check if the player has 3 knight cards that been activated
        {
            if (this->developmentCards[i]->getDescription() == "Knight (used)")
            {
                return 2;
            }
        }
        return 0;
    }

} // namespace ariel
