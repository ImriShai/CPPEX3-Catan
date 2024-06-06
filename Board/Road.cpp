#include "Road.hpp"
using namespace std;
using namespace ariel;
    Road::Road(size_t id): id(id), owner(nullptr) {
         vector<size_t> adjSett;
        switch (id) //ADD type according to the id
        {
        case 1:
             adjSett = {1,4};
            break;
        case 2:
             adjSett = {1,5};
            break;
        case 3:
             adjSett = {2,5};
            break;
        case 4:
             adjSett = {2,6};
            break;
        case 5:
             adjSett = {3,6};
            break;
        case 6:
             adjSett = {3,7};
            break;
        case 7:
             adjSett = {4,8};
            break;
        case 8:
             adjSett = {5,9};
            break;
        case 9:
             adjSett = {6,10};
            break;
        case 10:
             adjSett = {7,11};
            break;
        case 11:
             adjSett = {8,12};
            break;
        case 12:
             adjSett = {8,13};
            break;
        case 13:
             adjSett = {9,13};
            break;
        case 14:
             adjSett = {9,14};
            break;
        case 15:
             adjSett = {10,14};
            break;
        case 16:
             adjSett = {10,15};
            break;
        case 17:
             adjSett = {11,15};
            break;  
        case 18:
             adjSett = {11,16};
            break;  
        case 19:
             adjSett = {12,17};
            break;
        case 20:
             adjSett = {13,18};
            break;
        case 21:
             adjSett = {14,19};
            break;
        case 22:
             adjSett = {15,20};
            break;
        case 23:
             adjSett = {16,21};
            break;
        case 24:
             adjSett = {17,22};
            break;
        case 25:
             adjSett = {17,23};
            break;  
        case 26:
             adjSett = {18,23};
            break;
        case 27:
             adjSett = {18,24};
            break;
        case 28:
             adjSett = {19,24};
            break;
        case 29:
             adjSett = {19,25};
            break;
        case 30:
             adjSett = {20,25};
            break;
        case 31:
             adjSett = {20,26};
            break;
        case 32:
             adjSett = {21,26};
            break;
        case 33:
             adjSett = {21,27};
            break;
        case 34:
             adjSett = {22,28};
            break;
        case 35:
             adjSett = {23,29};
            break;
        case 36:
             adjSett = {24,30};
            break;
        case 37:
             adjSett = {25,31};
            break;
        case 38:
             adjSett = {26,32};
            break;
        case 39:
             adjSett = {27,33};
            break;
        case 40:
             adjSett = {28,34};
            break;
        case 41:
             adjSett = {29,34};
            break;
        case 42:
             adjSett = {29,35};
            break;
        case 43:
             adjSett = {30,35};
            break;
        case 44:
             adjSett = {30,36};
            break;
        case 45:
             adjSett = {31,36};
            break;
        case 46:
             adjSett = {31,37};
            break;
        case 47:
             adjSett = {32,37};
            break;
        case 48:
             adjSett = {32,38};
            break;
        case 49:
             adjSett = {33,38};
            break;
        case 50:
             adjSett = {34,39};
            break;
        case 51:
             adjSett = {35,40};
            break;
        case 52:
             adjSett = {36,41};
            break;  
        case 53:
             adjSett = {37,42};
            break;  
        case 54:
             adjSett = {38,43};
            break;
        case 55:
             adjSett = {39,44};
            break;
        case 56:
             adjSett = {40,44};
            break;
        case 57:
             adjSett = {40,45};
            break;
        case 58:
             adjSett = {41,45};
            break;  
        case 59:
             adjSett = {41,46};
            break;
        case 60:
             adjSett = {42,46};
            break;
        case 61:
             adjSett = {42,47};
            break;
        case 62: 
             adjSett = {43,47};
            break;
        case 63:
             adjSett = {44,48};
            break;
        case 64:
             adjSett = {45,49};
            break;  
        case 65:
             adjSett = {46,50};
            break;
        case 66:
             adjSett = {47,51};
            break;
        case 67:
             adjSett = {48,52};
            break;
        case 68:
             adjSett = {49,52};
            break;
        case 69:
             adjSett = {49,53};
            break;
        case 70:
             adjSett = {50,53};
            break;
        case 71:
             adjSett = {50,54};
            break;
        case 72:
             adjSett = {51,54};
            break;
        default:
        throw invalid_argument("Invalid id, not a valid road id.");
        }
    }

    Road::~Road(){

    }

    std::string Road::getType() {
        return this->type;
    }
    const Player* Road::getOwner() const {
        return owner;
    }   
    void Road::setType(const std::string& type) {
        this->type = type;
    }
    void Road::setOwner(Player* owner) {
        if(this->owner != nullptr){
            throw invalid_argument("Road already has an owner");
        }
        this->owner = owner;
    }
    const vector<size_t> &Road::getAdjacents(){
        return this->adjSettelments;
    }
    string Road::toString(size_t mode){
        switch (mode)
        {
        case Consts::REGULAR:
            return this->getType();
            break;
        case Consts::BUILD_SETTLEMENT:
            return this->getType();
            break;
        case Consts::BUILD_ROAD:
            return to_string(this->id);
            break;
        default:
           throw invalid_argument("Invalid mode, not a valid mode.");
        }
    }