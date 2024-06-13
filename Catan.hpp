#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <chrono>
#include "Player.hpp"
#include "Board/Board.hpp"
#include "Consts.hpp"
#include "Cards/DevelopmentCard.hpp"
#include "Cards/Knight.hpp"
#include "Cards/Monopoly.hpp"
#include "Cards/RoadBuilding.hpp"
#include "Cards/YearOfPlenty.hpp"
#include "Cards/VictoryPoint.hpp"




using namespace std;
namespace ariel

{

    /*
    * @brief This class represents the main game of Catan
    */
     class Catan
    {
    private:
        friend class Knight;  //set as friend to allow access to private members and methods
        friend class Monopoly;
        friend class RoadBuilding;
        friend class YearOfPlenty;
        friend class VictoryPoint;
        friend class Test;

        
        vector<Player> players;
        size_t currentPlayer;
        Board board;
        vector<DevelopmentCard*> developmentCards;
        size_t cardCounter;
       
        // void build();
        // void trade();
        // void buyDevelopmentCard();
        // void playDevelopmentCard();
        // void endTurn();
        // void initDevelopmentCards();
        // void rolledSeven();
        // void shuffleVector(std::vector<DevelopmentCard*>& vec, size_t seed = 0);
        // void tradeResources();
        // void tradeDevelopmentCards();
        // void buildFirstRound();
        // void buildFirstRoundHelper(size_t i);
        // void collectResources(size_t diceRoll);
        // void printResources();
        // void ChooseStartingPlayer();
        // const Board &getBoard();
        // void printBoard(size_t mode);
        // bool checkWin();
        // const Player& getCurrentPlayer();
        // bool getPlayerInput();
        // Player& getPlayer(size_t index);
        // void playRound();
        // void roolDice();
    public:
        void build();  //for testing
        void trade();
        void buyDevelopmentCard();
        void playDevelopmentCard();
        void endTurn();
        void initDevelopmentCards();
        void rolledSeven();
        void shuffleVector(std::vector<DevelopmentCard*>& vec, size_t seed = 0);
        void tradeResources();
        void tradeDevelopmentCards();
        void buildFirstRound();
        void buildFirstRoundHelper(size_t i);
        void collectResources(size_t diceRoll);
        void printResources();
        void ChooseStartingPlayer();
        const Board &getBoard();
        void printBoard(size_t mode);
        bool checkWin();
        const Player& getCurrentPlayer();
        bool getPlayerInput();
        Player& getPlayer(size_t index);
        void playRound();
        void roolDice(); 


        Catan(Player& p1, Player& p2, Player& p3);
        ~Catan();
       
        void PlayGame();
    };
}