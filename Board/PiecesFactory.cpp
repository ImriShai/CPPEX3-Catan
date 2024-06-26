#include "PiecesFactory.hpp"
using namespace std;
namespace ariel
{
    
    PiecesFactory *PiecesFactory::instance = nullptr; // Initialize the instance to nullptr

/**
 * @brief Destroy the PiecesFactory object
*/
    void PiecesFactory::deleteInstance()
    {
        delete instance;
    }


   
/**
 * @brief Create a new PiecesFactory object or returns the existing one. This is a singleton class
*/
    PiecesFactory *PiecesFactory::getInstance()
    {
        if(instance == nullptr)
        {
           instance = new PiecesFactory();
        }
        return instance;
    }
/**
 * @brief Create a new Tile object by id
*/
    Tile *PiecesFactory::createTile(char id)
    {
        string type;
        vector<size_t> settelments;
        string number;
        string resource;
        string resourceType;
        switch (id)
        {

        case 'A':
            number = Consts::NUMBER + "10" + Consts::WHITE;
            resource = "🪨";
            resourceType = "ORE";
            settelments = {1, 4, 5, 8, 9, 13};

            break;
        case 'B':
            number = Consts::NUMBER + "2" + Consts::WHITE;
            resource = "🐑";
            resourceType = "SHEEP";
            settelments = {2, 5, 6, 10, 14};
            break;
        case 'C':

            number = Consts::NUMBER + "9" + Consts::WHITE;
            resource = "🪵";
            resourceType = "WOOD";
            settelments = {3, 6, 7, 10, 11, 15};
            break;
        case 'D':
            number = Consts::NUMBER + "12" + Consts::WHITE;
            resource = "🌾";
            resourceType = "WHEAT";
            settelments = {8, 12, 13, 17, 18, 23};
            break;
        case 'E':
            number = Consts::NUMBER + "6" + Consts::WHITE;
            resource = "🧱";
            resourceType = "BRICK";
            settelments = {9, 13, 14, 18, 19, 24};
            break;
        case 'F':
            number = Consts::NUMBER + "4" + Consts::WHITE;
            resource = "🐑";
            resourceType = "SHEEP";
            settelments = {10, 14, 15, 19, 20, 25};
            break;
        case 'G':
            number = Consts::NUMBER + "10" + Consts::WHITE;
            resource = "🧱";
            resourceType = "BRICK";
            settelments = {11, 15, 16, 20, 21, 26};
            break;
        case 'H':
            number = Consts::NUMBER + "9" + Consts::WHITE;
            resource = "🌾";
            resourceType = "WHEAT";
            settelments = {17, 22, 23, 28, 29, 34};
            break;
        case 'I':
            number = Consts::NUMBER + "11" + Consts::WHITE;
            resource = "🪵";
            resourceType = "WOOD";
            settelments = {18, 23, 24, 29, 30, 35};
            break;
        case 'J':
            number = "";
            resource = "🏜️";
            resourceType = "DESERT";
            settelments = {19, 24, 25, 30, 31, 36};
            break;
        case 'K':
            number = Consts::NUMBER + "3" + Consts::WHITE;
            resource = "🪵";
            resourceType = "WOOD";
            settelments = {20, 25, 26, 31, 32, 37};
            break;
        case 'L':
            number = Consts::NUMBER + "8" + Consts::WHITE;
            resource = "🪨";
            resourceType = "ORE";
            settelments = {21, 26, 27, 32, 33, 38};
            break;
        case 'M':
            number = Consts::NUMBER + "8" + Consts::WHITE;
            resource = "🪵";
            resourceType = "WOOD";
            settelments = {29, 34, 35, 39, 40, 44};

            break;
        case 'N':
            number = Consts::NUMBER + "3" + Consts::WHITE;
            resource = "🪨";
            resourceType = "ORE";
            settelments = {30, 35, 36, 40, 41, 45};
            break;
        case 'O':
            number = Consts::NUMBER + "4" + Consts::WHITE;
            resource = "🌾";
            resourceType = "WHEAT";
            settelments = {31, 36, 37, 41, 42, 46};
            break;
        case 'P':
            number = Consts::NUMBER + "5" + Consts::WHITE;
            resource = "🐑";
            resourceType = "SHEEP";
            settelments = {32, 37, 38, 42, 43, 47};
            break;
        case 'Q':
            number = Consts::NUMBER + "5" + Consts::WHITE;
            resource = "🧱";
            resourceType = "BRICK";
            settelments = {40, 44, 45, 48, 49, 52};
            break;
        case 'R':
            number = Consts::NUMBER + "6" + Consts::WHITE;
            resource = "🌾";
            resourceType = "WHEAT";
            settelments = {41, 45, 46, 49, 50, 53};
            break;
        case 'S':
            number = Consts::NUMBER + "11" + Consts::WHITE;
            resource = "🐑";
            resourceType = "SHEEP";
            settelments = {42, 46, 47, 50, 51, 54};
            break;
        default:
            throw invalid_argument("Invalid tile id");
            break;
        }
        return new Tile(id, number, resource, resourceType, settelments);
    }
/**
 * @brief Create a new Road object by id
*/
     Road *PiecesFactory::createRoad(size_t id)
    {
        vector<size_t> adjSettelments;
        string type;
        switch (id) // ADD type according to the id
        {
        case 1:
            adjSettelments = {1, 4};
            type = "/";
            break;
        case 2:
            adjSettelments = {1, 5};
            type = "\\";
            break;
        case 3:
            adjSettelments = {2, 5};
            type = "/";
            break;
        case 4:
            adjSettelments = {2, 6};
            type = "\\";
            break;
        case 5:
            adjSettelments = {3, 6};
            type = "/";
            break;
        case 6:
            adjSettelments = {3, 7};
            type = "\\";
            break;
        case 7:
            adjSettelments = {4, 8};
            type = "|";
            break;
        case 8:
            adjSettelments = {5, 9};
            type = "|";
            break;
        case 9:
            adjSettelments = {6, 10};
            type = "|";
            break;
        case 10:
            adjSettelments = {7, 11};
            type = "|";
            break;
        case 11:
            adjSettelments = {8, 12};
            type = "/";
            break;
        case 12:
            adjSettelments = {8, 13};
            type = "\\";
            break;
        case 13:
            adjSettelments = {9, 13};
            type = "/";
            break;
        case 14:
            adjSettelments = {9, 14};
            type = "\\";
            break;
        case 15:
            adjSettelments = {10, 14};
            type = "/";
            break;
        case 16:
            adjSettelments = {10, 15};
            type = "\\";
            break;
        case 17:
            adjSettelments = {11, 15};
            type = "/";
            break;
        case 18:
            adjSettelments = {11, 16};
            type = "\\";
            break;
        case 19:
            adjSettelments = {12, 17};
            type = "|";
            break;
        case 20:
            adjSettelments = {13, 18};
            type = "|";
            break;
        case 21:
            adjSettelments = {14, 19};
            type = "|";
            break;
        case 22:
            adjSettelments = {15, 20};
            type = "|";

            break;
        case 23:
            adjSettelments = {16, 21};
            type = "|";

            break;
        case 24:
            adjSettelments = {17, 22};
            type = "/";
            break;
        case 25:
            adjSettelments = {17, 23};
            type = "\\";
            break;
        case 26:
            adjSettelments = {18, 23};
            type = "/";
            break;
        case 27:
            adjSettelments = {18, 24};
            type = "\\";
            break;
        case 28:
            adjSettelments = {19, 24};
            type = "/";
            break;
        case 29:
            adjSettelments = {19, 25};
            type = "\\";
            break;
        case 30:
            adjSettelments = {20, 25};
            type = "/";
            break;
        case 31:
            adjSettelments = {20, 26};
            type = "\\";
            break;
        case 32:
            adjSettelments = {21, 26};
            type = "/";
            break;
        case 33:
            adjSettelments = {21, 27};
            type = "\\";
            break;
        case 34:
            adjSettelments = {22, 28};
            type = "|";

            break;
        case 35:
            adjSettelments = {23, 29};
            type = "|";

            break;
        case 36:
            adjSettelments = {24, 30};
            type = "|";

            break;
        case 37:
            adjSettelments = {25, 31};
            type = "|";

            break;
        case 38:
            adjSettelments = {26, 32};
            type = "|";

            break;
        case 39:
            adjSettelments = {27, 33};
            type = "|";

            break;
        case 40:
            adjSettelments = {28, 34};
            type = "\\";

            break;
        case 41:
            adjSettelments = {29, 34};
            type = "/";
            break;
        case 42:
            adjSettelments = {29, 35};
            type = "\\";
            break;
        case 43:
            adjSettelments = {30, 35};
            type = "/";
            break;
        case 44:
            adjSettelments = {30, 36};
            type = "\\";
            break;
        case 45:
            adjSettelments = {31, 36};
            type = "/";
            break;
        case 46:
            adjSettelments = {31, 37};
            type = "\\";
            break;
        case 47:
            adjSettelments = {32, 37};
            type = "/";
            break;
        case 48:
            adjSettelments = {32, 38};
            type = "\\";
            break;
        case 49:
            adjSettelments = {33, 38};
            type = "/";
            break;
        case 50:
            adjSettelments = {34, 39};
            type = "|";

            break;
        case 51:
            adjSettelments = {35, 40};
            type = "|";

            break;
        case 52:
            adjSettelments = {36, 41};
            type = "|";

            break;
        case 53:
            adjSettelments = {37, 42};
            type = "|";

            break;
        case 54:
            adjSettelments = {38, 43};
            type = "|";

            break;
        case 55:
            adjSettelments = {39, 44};
            type = "\\";
            break;
        case 56:
            adjSettelments = {40, 44};
            type = "/";
            break;
        case 57:
            adjSettelments = {40, 45};
            type = "\\";
            break;
        case 58:
            adjSettelments = {41, 45};
            type = "/";
            break;
        case 59:
            adjSettelments = {41, 46};
            type = "\\";
            break;
        case 60:
            adjSettelments = {42, 46};
            type = "/";
            break;
        case 61:
            adjSettelments = {42, 47};
            type = "\\";
            break;
        case 62:
            adjSettelments = {43, 47};
            type = "/";
            break;
        case 63:
            adjSettelments = {44, 48};
            type = "|";

            break;
        case 64:
            adjSettelments = {45, 49};
            type = "|";
            break;
        case 65:
            adjSettelments = {46, 50};
            type = "|";
            break;
        case 66:
            adjSettelments = {47, 51};
            type = "|";
            break;
        case 67:
            adjSettelments = {48, 52};
            type = "\\";
            break;
        case 68:
            adjSettelments = {49, 52};
            type = "/";
            break;
        case 69:
            adjSettelments = {49, 53};
            type = "\\";
            break;
        case 70:
            adjSettelments = {50, 53};
            type = "/";
            break;
        case 71:
            adjSettelments = {50, 54};
            type = "\\";
            break;
        case 72:
            adjSettelments = {51, 54};
            type = "/";
            break;
        default:
            throw invalid_argument("Invalid id, not a valid road id.");
        }
        return new Road(id, adjSettelments, type);
    }

/**
 * @brief Create a new Settlement object by id
 */
     Settlement *PiecesFactory::createSettlement(size_t id)
    {
        vector<size_t> adjSett;
        vector<size_t> adjRoads;
        switch (id)
        {
        case 1:
            adjSett = {4, 5};
            adjRoads = {1, 2};
            break;
        case 2:
            adjSett = {5, 6};
            adjRoads = {3, 4};
            break;
        case 3:
            adjSett = {6, 7};
            adjRoads = {5, 6};
            break;
        case 4:
            adjSett = {1, 8};
            adjRoads = {1, 7};
            break;
        case 5:
            adjSett = {1, 2, 9};
            adjRoads = {2, 3, 8};
            break;
        case 6:
            adjSett = {2, 3, 10};
            adjRoads = {4, 5, 9};
            break;
        case 7:
            adjSett = {3, 11};
            adjRoads = {6, 10};
            break;
        case 8:
            adjSett = {4, 12, 13};
            adjRoads = {7, 11, 12};
            break;
        case 9:
            adjSett = {5, 13, 14};
            adjRoads = {8, 13, 14};
            break;
        case 10:
            adjSett = {6, 14, 15};
            adjRoads = {9, 15, 16};
            break;
        case 11:
            adjSett = {7, 15, 16};
            adjRoads = {10, 17, 18};
            break;
        case 12:
            adjSett = {8, 17};
            adjRoads = {11, 19};
            break;
        case 13:
            adjSett = {8, 9, 18};
            adjRoads = {12, 13, 20};
            break;
        case 14:
            adjSett = {9, 10, 19};
            adjRoads = {14, 15, 21};
            break;
        case 15:
            adjSett = {10, 11, 20};
            adjRoads = {16, 17, 22};
            break;
        case 16:
            adjSett = {11, 21};
            adjRoads = {18, 23};
            break;
        case 17:
            adjSett = {12, 22, 23};
            adjRoads = {19, 24, 25};
            break;
        case 18:
            adjSett = {13, 23, 24};
            adjRoads = {20, 26, 27};
            break;
        case 19:
            adjSett = {14, 24, 25};
            adjRoads = {21, 28, 29};
            break;
        case 20:
            adjSett = {15, 25, 26};
            adjRoads = {22, 30, 31};
            break;
        case 21:
            adjSett = {16, 26, 27};
            adjRoads = {23, 32, 33};
            break;
        case 22:
            adjSett = {17, 28};
            adjRoads = {24, 34};
            break;
        case 23:
            adjSett = {17, 18, 29};
            adjRoads = {25, 26, 35};
            break;
        case 24:
            adjSett = {18, 19, 30};
            adjRoads = {27, 28, 36};
            break;
        case 25:
            adjSett = {19, 20, 31};
            adjRoads = {29, 30, 37};
            break;
        case 26:
            adjSett = {20, 21, 32};
            adjRoads = {31, 32, 38};
            break;
        case 27:
            adjSett = {21, 33};
            adjRoads = {33, 39};
            break;
        case 28:
            adjSett = {22, 34};
            adjRoads = {34, 40};
            break;
        case 29:
            adjSett = {23, 34, 35};
            adjRoads = {35, 41, 42};
            break;
        case 30:
            adjSett = {24, 35, 36};
            adjRoads = {36, 43, 44};
            break;
        case 31:
            adjSett = {25, 36, 37};
            adjRoads = {37, 45, 46};
            break;
        case 32:
            adjSett = {26, 37, 38};
            adjRoads = {38, 47, 48};
            break;
        case 33:
            adjSett = {27, 38};
            adjRoads = {39, 49};
            break;
        case 34:
            adjSett = {28, 29, 39};
            adjRoads = {40, 41, 50};
            break;
        case 35:
            adjSett = {29, 30, 40};
            adjRoads = {42, 43, 51};
            break;
        case 36:
            adjSett = {30, 31, 41};
            adjRoads = {44, 45, 52};
            break;
        case 37:
            adjSett = {31, 32, 42};
            adjRoads = {46, 47, 53};
            break;
        case 38:
            adjSett = {32, 33, 43};
            adjRoads = {48, 49, 54};
            break;
        case 39:
            adjSett = {34, 44};
            adjRoads = {50, 55};
            break;
        case 40:
            adjSett = {35, 44, 45};
            adjRoads = {51, 56, 57};
            break;

        case 41:
            adjSett = {36, 45, 46};
            adjRoads = {52, 58, 59};
            break;
        case 42:
            adjSett = {37, 46, 47};
            adjRoads = {53, 60, 61};
            break;
        case 43:
            adjSett = {38, 47};
            adjRoads = {54, 62};
            break;
        case 44:
            adjSett = {39, 40, 48};
            adjRoads = {55, 56, 63};
            break;
        case 45:
            adjSett = {40, 41, 49};
            adjRoads = {57, 58, 64};
            break;
        case 46:
            adjSett = {41, 42, 50};
            adjRoads = {59, 60, 65};
            break;
        case 47:
            adjSett = {42, 43, 51};
            adjRoads = {61, 62, 66};
            break;
        case 48:
            adjSett = {44, 52};
            adjRoads = {63, 67};
            break;
        case 49:
            adjSett = {45, 52, 53};
            adjRoads = {64, 68, 69};
            break;
        case 50:
            adjSett = {46, 53, 54};
            adjRoads = {65, 70, 71};
            break;
        case 51:
            adjSett = {47, 54};
            adjRoads = {66, 72};
            break;
        case 52:
            adjSett = {48, 49};
            adjRoads = {67, 68};
            break;
        case 53:
            adjSett = {49, 50};
            adjRoads = {69, 70};
            break;
        case 54:
            adjSett = {50, 51};
            adjRoads = {71, 72};
            break;

        default:
            throw std::invalid_argument("Invalid id, not a valid settelment id.");
        }
        return new Settlement(id, adjSett, adjRoads);
    }

}
