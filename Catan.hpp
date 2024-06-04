#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include "Player.hpp"
#include "Board.hpp"
using namespace std;
namespace ariel
{
    class Catan
    {
    private:
        vector<Player> players;
        Board board;
        size_t currentPlayer;
        vector<size_t> availableResources = {19, 19, 19, 19, 19}; // {wood, brick, wheat, sheep, ore}
        unordered_map<size_t, vector<char>> resourceTiles = {
           {2, {'B'}},
           {3, {'K', 'N'}},
           {4, {'F', 'O'}},
           {5, {'P','Q'}},
           {6, {'E', 'R'}},
           {8, {'L','M'}},
           {9, {'C','H'}},
           {10, {'A','G'}},
           {11, {'I','S'}}
           {12, {'D'}}}


    public:
        Catan(Player p1, Player p2, Player p3);
        void ChooseStartingPlayer();
        const Board &getBoard();
        void printBoard();
        void start();
        bool checkWin();
        const Player &getCurrentPlayer();
        void init();
    };
}