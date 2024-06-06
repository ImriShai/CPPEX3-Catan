#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <algorithm>
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
        unordered_map<size_t, vector<char>> resourceTiles = {
           {2, {'B'}},
           {3, {'K', 'N'}},
           {4, {'F', 'O'}},
           {5, {'P','Q'}},
           {6, {'E', 'R'}},
           {8, {'L','M'}},
           {9, {'C','H'}},
           {10, {'A','G'}},
           {11, {'I','S'}},
           {12, {'D'}}};
        void build();
        void trade();
        void buyDevelopmentCard();
        void playDevelopmentCard();
        void endTurn();
        size_t rollDice();
        void initDevelopmentCards();


    public:
        Catan(Player& p1, Player& p2, Player& p3);
        ~Catan();
        void ChooseStartingPlayer();
        const Board &getBoard();
        void printBoard(size_t mode);
        void start();
        bool checkWin();
        const Player& getCurrentPlayer();
        void init();
        void getPlayerInput();
        Player& getPlayer(size_t index);



    };
}