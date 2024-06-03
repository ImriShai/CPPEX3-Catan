#include <string>
#include <vector>
#include <iostream>
#include <Tile.hpp>
#include <stdexcept>

using namespace std;
namespace ariel{
    class Board{
        private:
        vector<::Tile*> tiles;
        public:
        void printBoard();
        vector<Tile>& getTiles();
    };
}