#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <sstream> 
#include <unordered_map>

using namespace std;
namespace ariel
{
/**
 * @brief This class contains all the constants used in the game. 
 * Enums are used to represent the different types of resources, development cards, and modes of the game.
 * The class also contains a method to parse a string to a vector of resources and a method to get the index of a resource in the RESOURCES vector.
 * The class also contains a vector of resources, to map between number and string name, and a map of resource tiles.
 */
class Consts
{
    public:
    enum  TO_STRING_MODE {REGULAR = 0, BUILD_SETTLEMENT = 1, BUILD_ROAD = 2, BUILD_CITY = 3};
    enum  VALUE {NONE = 0, SETTELMENT = 1, CITY =2};
    enum  RESOURCE {BRICK = 0, WOOD = 1, WHEAT = 2, SHEEP = 3, ORE = 4, DESERT = 5};
    enum DEVELOPMENT_CARD {KNIGHT = 0, VICTORY_POINT = 1, ROAD_BUILDING = 2, MONOPOLY = 3, YEAR_OF_PLENTY = 4};
    static const size_t NUM_OF_PLAYERS = 3;
    static const string RED;
    static const string ORANGE;
    static const string BLUE;
    static const string WHITE;
    static const string NUMBER;
    static const string CITYEMOJI;
    static const string SETTELMENTEMOJI;
    static const vector<size_t> parseResource(const string resource);
    static const size_t getResourceIndex(const string resource);
    static const vector<string> RESOURCES;
     static const unordered_map<size_t, vector<char>> resourceTiles;
    
};
}