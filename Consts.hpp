#pragma once
#include <string>
using namespace std;
namespace ariel
{
class Consts
{
    public:
    enum  TO_STRING_MODE {REGULAR = 0, BUILD_SETTLEMENT = 1, BUILD_ROAD = 2};
    enum  VALUE {NONE = 0, SETTELMENT = 1, CITY =2};
    enum  RESOURCE {BRICK = 0, WOOD = 1, WHEAT = 2, SHEEP = 3, ORE = 4};
    enum DEVELOPMENT_CARD {KNIGHT = 0, VICTORY_POINT = 1, ROAD_BUILDING = 2, MONOPOLY = 3, YEAR_OF_PLENTY = 4};
    static const string RED;
    static const string ORANGE;
    static const string BLUE;
};
}