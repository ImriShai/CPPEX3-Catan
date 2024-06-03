#include "Settelment.hpp"
using namespace std;

    ariel::Settement::Settlement(int value, const std::string& type, size_t id, const Player& owner)
        : value(value), type(type), id(id), owner(owner) {
            switch (id)
            {
            case 1:
                vector<size_t> adjSett = {4,5};
                vector<size_t> adjRoads = {1,2};
                break;
            case 2:
                vector<size_t> adjSett = {5,6};
                vector<size_t> adjRoads = {3,4};
                break;  
            case 3:
                vector<size_t> adjSett = {6,7};
                vector<size_t> adjRoads = {5,6};
                break; 
            case 4:
                vector<size_t> adjSett = {1,8};
                vector<size_t> adjRoads = {1,7};
                break;
            case 5:
                vector<size_t> adjSett = {1,2,9};
                vector<size_t> adjRoads = {2,3,8};
                break;
            case 6:
                vector<size_t> adjSett = {2,3,10};
                vector<size_t> adjRoads = {4,5,9};
                break;
            case 7:
                vector<size_t> adjSett = {3,11};
                vector<size_t> adjRoads = {6,10};
                break;  
            case 8:
                vector<size_t> adjSett = {4,12,13};
                vector<size_t> adjRoads = {7,11,12};
                break;
            case 9:
                vector<size_t> adjSett = {5,13,14};
                vector<size_t> adjRoads = {8,13,14};
                break;
            case 10:
                vector<size_t> adjSett = {6,14,15};
                vector<size_t> adjRoads = {9,15,16};
                break;
            case 11:
                vector<size_t> adjSett = {7,15,16};
                vector<size_t> adjRoads = {10,17,18};
                break;
            case 12:
                vector<size_t> adjSett = {8,17};
                vector<size_t> adjRoads = {11,19};
                break;
            case 13:
                vector<size_t> adjSett = {8,9,18};
                vector<size_t> adjRoads = {12,13,20};
                break;
            case 14:
                vector<size_t> adjSett = {9,10,19};
                vector<size_t> adjRoads = {14,15,21};
                break;
            case 15:
                vector<size_t> adjSett = {10,11,20};
                vector<size_t> adjRoads = {16,17,22};
                break;
            case 16:
                vector<size_t> adjSett = {11,21};
                vector<size_t> adjRoads = {18,23};
                break;
            case 17:   
                vector<size_t> adjSett = {12,22,23};
                vector<size_t> adjRoads = {19,24,25};
                break;
            case 18:
                vector<size_t> adjSett = {13,23,24};
                vector<size_t> adjRoads = {20,26,27};
                break;
            case 19:
                vector<size_t> adjSett = {14,24,25};
                vector<size_t> adjRoads = {21,28,29};
                break;
            case 20:
                vector<size_t> adjSett = {15,25,26};
                vector<size_t> adjRoads = {22,30,31};
                break; 
            case 21:
                vector<size_t> adjSett = {16,26,27};
                vector<size_t> adjRoads = {23,32,33};
                break;  
            case 22:
                vector<size_t> adjSett = {17,28};
                vector<size_t> adjRoads = {24,34};
                break;
            case 23:
                vector<size_t> adjSett = {17,18,29};
                vector<size_t> adjRoads = {25,26,35};
                break;
            case 24:
                vector<size_t> adjSett = {18,19,30};
                vector<size_t> adjRoads = {27,28,36};
                break;
            case 25:
                vector<size_t> adjSett = {19,20,31};
                vector<size_t> adjRoads = {29,30,37};
                break;
            case 26:
                vector<size_t> adjSett = {20,21,32};
                vector<size_t> adjRoads = {31,32,38};
                break;
            case 27:
                vector<size_t> adjSett = {21,33};
                vector<size_t> adjRoads = {33,39};
                break;
            case 28:
                vector<size_t> adjSett = {22,34};
                vector<size_t> adjRoads = {34,40};
                break;
            case 29:
                vector<size_t> adjSett = {23,34,35};
                vector<size_t> adjRoads = {35,41,42};
                break;
            case 30:
                vector<size_t> adjSett = {24,35,36};
                vector<size_t> adjRoads = {36,43,44};
                break;
            case 31:
                vector<size_t> adjSett = {25,36,37};
                vector<size_t> adjRoads = {37,45,46};
                break;
            case 32:
                vector<size_t> adjSett = {26,37,38};
                vector<size_t> adjRoads = {38,47,48};
                break;
            case 33:
                vector<size_t> adjSett = {27,38};
                vector<size_t> adjRoads = {39,49};
                break;
            case 34:
                vector<size_t> adjSett = {28,29,39};
                vector<size_t> adjRoads = {40,41,50};
                break;
            case 35:
                vector<size_t> adjSett = {29,30,40};
                vector<size_t> adjRoads = {42,43,51};
                break;
            case 36:
                vector<size_t> adjSett = {30,31,41};
                vector<size_t> adjRoads = {44,45,52};
                break;
            case 37:
                vector<size_t> adjSett = {31,32,42};
                vector<size_t> adjRoads = {46,47,53};
                break;
            case 38:
                vector<size_t> adjSett = {32,33,43};
                vector<size_t> adjRoads = {48,49,54};
                break;
            case 39:
                vector<size_t> adjSett = {34,44};
                vector<size_t> adjRoads = {50,55};
                break;
            case 40:
                vector<size_t> adjSett = {35,44,45};
                vector<size_t> adjRoads = {51,56,57};
                break;

            case 41:
                vector<size_t> adjSett = {36,45,46};
                vector<size_t> adjRoads = {52,58,59};
                break;
            case 42:
                vector<size_t> adjSett = {37,46,47};
                vector<size_t> adjRoads = {53,60,61};
                break;
            case 43:
                vector<size_t> adjSett = {38,47};
                vector<size_t> adjRoads = {54,62};
                break;
            case 44:
                vector<size_t> adjSett = {39,40,48};
                vector<size_t> adjRoads = {55,56,63};
                break;
            case 45:
                vector<size_t> adjSett = {40,41,49};
                vector<size_t> adjRoads = {57,58,64};
                break;
            case 46:
                vector<size_t> adjSett = {41,42,50};
                vector<size_t> adjRoads = {59,60,65};
                break;  
            case 47:
                vector<size_t> adjSett = {42,43,51};
                vector<size_t> adjRoads = {61,62,66};
                break;
            case 48:
                vector<size_t> adjSett = {44,52};
                vector<size_t> adjRoads = {63,67};
                break;
            case 49:
                vector<size_t> adjSett = {45,52,53};
                vector<size_t> adjRoads = {64,68,69};
                break;
            case 50:
                vector<size_t> adjSett = {46,53,54};
                vector<size_t> adjRoads = {65,70,71};
                break;
            case 51:
                vector<size_t> adjSett = {47,54};
                vector<size_t> adjRoads = {66,72};
                break;
            case 52:
                vector<size_t> adjSett = {48,49};
                vector<size_t> adjRoads = {67,68};
                break;
            case 53:
                vector<size_t> adjSett = {49,50};
                vector<size_t> adjRoads = {69,70};
                break;
            case 54:
                vector<size_t> adjSett = {50,51};
                vector<size_t> adjRoads = {71,72};
                break;
            default:
                throw std::invalid_argument("Invalid id, not a valid settelment id.");
            }
        }

    // Getters
    int getValue() const { return value; }
    std::string getType() const { return type; }
    size_t getId() const { return id; }
    const Player& getOwner() const { return owner; }

    // Setters
    void setValue(int newValue) { value = newValue; }
    void setType(const std::string& newType) { type = newType; }
    void setId(size_t newId) { id = newId; }
    
    void setOwner(const Player& newOwner) { owner = newOwner};
