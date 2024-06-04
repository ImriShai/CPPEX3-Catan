#include <string>
#include <vector>
#include <iostream>
#include <Tile.hpp>
#include <stdexcept>
#include <Settelment.hpp>
#include <Road.hpp>
#include <memory>

using namespace std;
namespace ariel{
    class Board{
        private:
        vector<Tile*> tiles;
        vector<unique_ptr<Settlement>> settlements;
        vector<unique_ptr<Road>> roads;
        public:
        void printBoard();
       const Tile* getTile(char id); //id is the id of the tile
        void init();
    };
}