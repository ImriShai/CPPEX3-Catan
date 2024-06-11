#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include "Cards/DevelopmentCard.hpp"

using namespace std;
namespace ariel
{
/**
 * @brief This class represents a player in the game of Catan.
 */
class Player
{
    private:
        string name;
        size_t age;
        vector<size_t> resources = {0,0,0,0,0}; // {BRICK, WOOD, WHEAT, SHEEP, ORE}
        vector<size_t> settlements;
        vector<size_t> roads;
        vector<DevelopmentCard*> developmentCards;
        size_t victoryPoints;
        string color;
        size_t findCard(size_t type);
        void upgradeToCity(size_t id);// the id of the settlement to upgrade

    public:
        Player(string name, size_t age);
        Player();
        bool canBuySettelement();
        void buySettlement(size_t id, bool firstRound = false);
        bool canBuyCity();
        void buyCity(size_t id);// the id of the settlement to check 
        bool canBuyRoad();
        void buyRoad(size_t id, bool firstRound = false);
        bool canBuyDevelopmentCard();
        void buyDevelopmentCard(DevelopmentCard* card);
        const vector<DevelopmentCard*>& getDevelopmentCards() ;
        size_t getVictoryPointCards();
        
        string getName() const;
        const vector<size_t> &getResources() const;
        const vector<size_t> &getSettelments() const;
        const vector<size_t> &getRoads() const;
        size_t getVictoryPoints();
        void addResource(size_t resource, size_t amount);
        void removeResource(size_t resource, size_t amount);
        void addVictoryPoints(size_t amount);
        void setColor(string color);
        string getColor();
        ~Player();
        size_t getAge() const ;
        const Player& getPlayer();
        size_t getNumResources() const;
        string stealRandomResource() ;//for knight card
        size_t stealResource(size_t resource);//for momopoly card
        void tradeResources(Player* player,vector<size_t> resourcesToGive, vector<size_t> resourcesToTake);
        void printResources();
        void printDevelopmentCards();
        void tradeDevelopmentCards(Player* player, vector<size_t> cardsToGive, vector<size_t> cardsToTake);
        size_t hasLongestArmy() ;

};

} // namespace ariel
