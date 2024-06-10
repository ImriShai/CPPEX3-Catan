#pragma once
#include <vector>
#include <memory>
#include "Settelment.hpp"
#include "Road.hpp"
#include "Tile.hpp"
#include "../Consts.hpp"
using namespace std;
namespace ariel{
    /**
     * @brief A class that is responsible for creating the pieces of the game
     * This class implements the singleton design pattern and the factory design pattern
    */
    class PiecesFactory{
        public:
        PiecesFactory(const PiecesFactory&) = delete;
        PiecesFactory& operator=(const PiecesFactory&) = delete;


        // Static method to get the single instance of the class
        static PiecesFactory* getInstance();

        static Settlement* createSettlement(size_t id);
        static Road* createRoad(size_t id);
        static Tile* createTile(char id);
        static void deleteInstance();

        private:
        static PiecesFactory* instance;
        PiecesFactory() {};
    };
}