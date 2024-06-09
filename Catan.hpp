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
    class Catan
    {
    private:
        vector<Player> players;
        size_t currentPlayer;
        Board board;
        vector<DevelopmentCard*> developmentCards;
        size_t cardCounter;
       
        void build();
        void trade();
        void buyDevelopmentCard();
        void playDevelopmentCard();
        void endTurn();
        size_t rollDice();
        void initDevelopmentCards();
        void rolledSeven();
        void shuffleVector(std::vector<DevelopmentCard*>& vec);
        void tradeResources();
        void tradeDevelopmentCards();
        void buildFirstRound();
        void buildFirstRoundHelper(size_t i);
        void collectResources(size_t diceRoll);
        void printResources();
    public:
        Catan(Player& p1, Player& p2, Player& p3);
        ~Catan();
        void ChooseStartingPlayer();
        const Board &getBoard();
        void printBoard(size_t mode);
        void PlayGame();
        bool checkWin();
        const Player& getCurrentPlayer();
        void init();
        bool getPlayerInput();
        Player& getPlayer(size_t index);
        void playRound();
        void roolDice(); 
    };
}