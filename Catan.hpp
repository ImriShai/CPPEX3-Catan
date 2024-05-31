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
        Player p1;
        Player p2;
        Player p3;
        Board board;

    public:
        Catan(Player p1, Player p2, Player p3);
        void ChooseStartingPlayer();
        Board getBoard();
    };
}