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
        void printRow1(size_t mode, Player* builder) const;
        void printRow2(size_t mode, Player* builder) const;
        void printRow3(size_t mode, Player* builder) const;
        void printRow4(size_t mode, Player* builder) const;
        void printRow5(size_t mode, Player* builder) const;
        void printRow6(size_t mode, Player* builder) const;
        void printRow7(size_t mode, Player* builder) const;
        void printRow8(size_t mode, Player* builder) const;
        void printRow9(size_t mode, Player* builder) const; 
        void printRow10(size_t mode, Player* builder) const;
        void printRow11(size_t mode, Player* builder) const;
        void printRow12(size_t mode, Player* builder) const;
        void printRow13(size_t mode, Player* builder) const;
        void printRow14(size_t mode, Player* builder) const;
        void printRow15(size_t mode, Player* builder) const;
        void printRow16(size_t mode, Player* builder) const;
        void printRow17(size_t mode, Player* builder) const;
        void printRow18(size_t mode, Player* builder) const;
        void printRow19(size_t mode, Player* builder) const;
        void printRow20(size_t mode, Player* builder) const;
        void printRow21(size_t mode, Player* builder) const;
        void printRow22(size_t mode, Player* builder) const;
        void printRow23(size_t mode, Player* builder) const;
        void printRow24(size_t mode, Player* builder) const;
        

        public:
        Board();
        void printBoard(size_t mode, Player* builder) const;
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