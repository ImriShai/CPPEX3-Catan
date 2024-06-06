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
        Tile* getTile(char id) const;
        Settlement* getSettlement(size_t id) const;
        const Road* getRoad(size_t id) const;
        void placeRoad(size_t id, Player* owner) const;
        void placeSettlement(size_t id, Player* owner) const;
        bool checkValidLocation(size_t id, size_t mode, Player* owner, bool firstRound = false) const;
        void placeCity(size_t id, Player* owner) const;
        ~Board();

        };
}