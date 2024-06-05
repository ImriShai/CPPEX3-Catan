#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <memory>
#include "Tile.hpp"
#include "Settelment.hpp"
#include "Road.hpp"
#include "../Consts.hpp"
using namespace std;
namespace ariel{
    class Board{
        private:
        Tile* tiles[19];
        Settlement* settlements[54];
        Road* roads[72];

        public:
        Board();
        void printBoard(size_t mode);
        void init();
        const Tile* getTile(char id);
        const Settlement* getSettlement(size_t id);
        const Road* getRoad(size_t id);
        ~Board();
        };
}