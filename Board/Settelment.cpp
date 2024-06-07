#include "Settelment.hpp"
using namespace std;
namespace ariel{
    Settlement::Settlement(size_t id){
            this->id = id;
            this->owner = nullptr;
            this->type = "🟫";
            this->value = 1;
            switch (id)
            {
                case 1:
                adjSett = {4,5};
                 adjRoads = {1,2};
                break;
            case 2:
                  adjSett = {5,6};
                  adjRoads = {3,4};
                break;  
            case 3:
                  adjSett = {6,7};
                  adjRoads = {5,6};
                break; 
            case 4:
                  adjSett = {1,8};
                  adjRoads = {1,7};
                break;
            case 5:
                  adjSett = {1,2,9};
                  adjRoads = {2,3,8};
                break;
            case 6:
                  adjSett = {2,3,10};
                  adjRoads = {4,5,9};
                break;
            case 7:
                  adjSett = {3,11};
                  adjRoads = {6,10};
                break;  
            case 8:
                  adjSett = {4,12,13};
                  adjRoads = {7,11,12};
                break;
            case 9:
                  adjSett = {5,13,14};
                  adjRoads = {8,13,14};
                break;
            case 10:
                  adjSett = {6,14,15};
                  adjRoads = {9,15,16};
                break;
            case 11:
                  adjSett = {7,15,16};
                  adjRoads = {10,17,18};
                break;
            case 12:
                  adjSett = {8,17};
                  adjRoads = {11,19};
                break;
            case 13:
                  adjSett = {8,9,18};
                  adjRoads = {12,13,20};
                break;
            case 14:
                  adjSett = {9,10,19};
                  adjRoads = {14,15,21};
                break;
            case 15:
                  adjSett = {10,11,20};
                  adjRoads = {16,17,22};
                break;
            case 16:
                  adjSett = {11,21};
                  adjRoads = {18,23};
                break;
            case 17:   
                  adjSett = {12,22,23};
                  adjRoads = {19,24,25};
                break;
            case 18:
                  adjSett = {13,23,24};
                  adjRoads = {20,26,27};
                break;
            case 19:
                  adjSett = {14,24,25};
                  adjRoads = {21,28,29};
                break;
            case 20:
                  adjSett = {15,25,26};
                  adjRoads = {22,30,31};
                break; 
            case 21:
                  adjSett = {16,26,27};
                  adjRoads = {23,32,33};
                break;  
            case 22:
                  adjSett = {17,28};
                  adjRoads = {24,34};
                break;
            case 23:
                  adjSett = {17,18,29};
                  adjRoads = {25,26,35};
                break;
            case 24:
                  adjSett = {18,19,30};
                  adjRoads = {27,28,36};
                break;
            case 25:
                  adjSett = {19,20,31};
                  adjRoads = {29,30,37};
                break;
            case 26:
                  adjSett = {20,21,32};
                  adjRoads = {31,32,38};
                break;
            case 27:
                  adjSett = {21,33};
                  adjRoads = {33,39};
                break;
            case 28:
                  adjSett = {22,34};
                  adjRoads = {34,40};
                break;
            case 29:
                  adjSett = {23,34,35};
                  adjRoads = {35,41,42};
                break;
            case 30:
                  adjSett = {24,35,36};
                  adjRoads = {36,43,44};
                break;
            case 31:
                  adjSett = {25,36,37};
                  adjRoads = {37,45,46};
                break;
            case 32:
                  adjSett = {26,37,38};
                  adjRoads = {38,47,48};
                break;
            case 33:
                  adjSett = {27,38};
                  adjRoads = {39,49};
                break;
            case 34:
                  adjSett = {28,29,39};
                  adjRoads = {40,41,50};
                break;
            case 35:
                  adjSett = {29,30,40};
                  adjRoads = {42,43,51};
                break;
            case 36:
                  adjSett = {30,31,41};
                  adjRoads = {44,45,52};
                break;
            case 37:
                  adjSett = {31,32,42};
                  adjRoads = {46,47,53};
                break;
            case 38:
                  adjSett = {32,33,43};
                  adjRoads = {48,49,54};
                break;
            case 39:
                  adjSett = {34,44};
                  adjRoads = {50,55};
                break;
            case 40:
                  adjSett = {35,44,45};
                  adjRoads = {51,56,57};
                break;

            case 41:
                  adjSett = {36,45,46};
                  adjRoads = {52,58,59};
                break;
            case 42:
                  adjSett = {37,46,47};
                  adjRoads = {53,60,61};
                break;
            case 43:
                  adjSett = {38,47};
                  adjRoads = {54,62};
                break;
            case 44:
                  adjSett = {39,40,48};
                  adjRoads = {55,56,63};
                break;
            case 45:
                  adjSett = {40,41,49};
                  adjRoads = {57,58,64};
                break;
            case 46:
                  adjSett = {41,42,50};
                  adjRoads = {59,60,65};
                break;  
            case 47:
                  adjSett = {42,43,51};
                  adjRoads = {61,62,66};
                break;
            case 48:
                  adjSett = {44,52};
                  adjRoads = {63,67};
                break;
            case 49:
                  adjSett = {45,52,53};
                  adjRoads = {64,68,69};
                break;
            case 50:
                  adjSett = {46,53,54};
                  adjRoads = {65,70,71};
                break;
            case 51:
                  adjSett = {47,54};
                  adjRoads = {66,72};
                break;
            case 52:
                  adjSett = {48,49};
                  adjRoads = {67,68};
                break;
            case 53:
                  adjSett = {49,50};
                  adjRoads = {69,70};
                break;
            case 54:
                  adjSett = {50,51};
                  adjRoads = {71,72};
                break;
                // ... rest of the cases
                default:
                    throw std::invalid_argument("Invalid id, not a valid settelment id.");
            }
        }

    // Gettersw
    size_t Settlement::getValue() const { return value; }
    std::string Settlement::getType() const { return type; }
    size_t Settlement::getId() const { return id; }
     Player* Settlement::getOwner() const { return owner; }
    const vector<size_t> &Settlement::getAdjSett() { return adjSett; }
    const vector<size_t> &Settlement::getAdjRoads() { return adjRoads; }
    // Setters
    void Settlement::setValue(size_t newValue) { value = newValue; }
    void Settlement::setType(const std::string& newType) { type = newType; }
    
    void Settlement::setOwner(Player* newOwner) { owner = newOwner;}
    string Settlement::toString(size_t mode, Player* builder){
        switch (mode)
        {
        case Consts::REGULAR:
            return this->getType();
            break;
        case Consts::BUILD_SETTLEMENT:
           if(this->getOwner() != nullptr){
            return this->getType();
           }
            return to_string(this->getId());
            break;
        case Consts::BUILD_CITY:
            if(this->getOwner() == builder){
                return to_string(this->getId());
            }
            return this->getType();
            break;
        case Consts::BUILD_ROAD:
            return this->getType();
            break;
        default:
           throw invalid_argument("Invalid mode, not a valid mode.");
        }
    }
}