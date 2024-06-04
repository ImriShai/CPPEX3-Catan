#include "Road.hpp"

    ariel::Road::Road(size_t id): id(id) owner(nullptr) {
        switch (id) //ADD type according to the id
        {
        case 1:
            vector<size_t> adjSett = {1,4};
            break;
        case 2:
            vector<size_t> adjSett = {1,5};
            break;
        case 3:
            vector<size_t> adjSett = {2,5};
            break;
        case 4:
            vector<size_t> adjSett = {2,6};
            break;
        case 5:
            vector<size_t> adjSett = {3,6};
            break;
        case 6:
            vector<size_t> adjSett = {3,7};
            break;
        case 7:
            vector<size_t> adjSett = {4,8};
            break;
        case 8:
            vector<size_t> adjSett = {5,9};
            break;
        case 9:
            vector<size_t> adjSett = {6,10};
            break;
        case 10:
            vector<size_t> adjSett = {7,11};
            break;
        case 11:
            vector<size_t> adjSett = {8,12};
            break;
        case 12:
            vector<size_t> adjSett = {8,13};
            break;
        case 13:
            vector<size_t> adjSett = {9,13};
            break;
        case 14:
            vector<size_t> adjSett = {9,14};
            break;
        case 15:
            vector<size_t> adjSett = {10,14};
            break;
        case 16:
            vector<size_t> adjSett = {10,15};
            break;
        case 17:
            vector<size_t> adjSett = {11,15};
            break;  
        case 18:
            vector<size_t> adjSett = {11,16};
            break;  
        case 19:
            vector<size_t> adjSett = {12,17};
            break;
        case 20:
            vector<size_t> adjSett = {13,18};
            break;
        case 21:
            vector<size_t> adjSett = {14,19};
            break;
        case 22:
            vector<size_t> adjSett = {15,20};
            break;
        case 23:
            vector<size_t> adjSett = {16,21};
            break;
        case 24:
            vector<size_t> adjSett = {17,22};
            break;
        case 25:
            vector<size_t> adjSett = {17,23};
            break;  
        case 26:
            vector<size_t> adjSett = {18,23};
            break;
        case 27:
            vector<size_t> adjSett = {18,24};
            break;
        case 28:
            vector<size_t> adjSett = {19,24};
            break;
        case 29:
            vector<size_t> adjSett = {19,25};
            break;
        case 30:
            vector<size_t> adjSett = {20,25};
            break;
        case 31:
            vector<size_t> adjSett = {20,26};
            break;
        case 32:
            vector<size_t> adjSett = {21,26};
            break;
        case 33:
            vector<size_t> adjSett = {21,27};
            break;
        case 34:
            vector<size_t> adjSett = {22,28};
            break;
        case 35:
            vector<size_t> adjSett = {23,29};
            break;
        case 36:
            vector<size_t> adjSett = {24,30};
            break;
        case 37:
            vector<size_t> adjSett = {25,31};
            break;
        case 38:
            vector<size_t> adjSett = {26,32};
            break;
        case 39:
            vector<size_t> adjSett = {27,33};
            break;
        case 40:
            vector<size_t> adjSett = {28,34};
            break;
        case 41:
            vector<size_t> adjSett = {29,34};
            break;
        case 42:
            vector<size_t> adjSett = {29,35};
            break;
        case 43:
            vector<size_t> adjSett = {30,35};
            break;
        case 44:
            vector<size_t> adjSett = {30,36};
            break;
        case 45:
            vector<size_t> adjSett = {31,36};
            break;
        case 46:
            vector<size_t> adjSett = {31,37};
            break;
        case 47:
            vector<size_t> adjSett = {32,37};
            break;
        case 48:
            vector<size_t> adjSett = {32,38};
            break;
        case 49:
            vector<size_t> adjSett = {33,38};
            break;
        case 50:
            vector<size_t> adjSett = {34,39};
            break;
        case 51:
            vector<size_t> adjSett = {35,40};
            break;
        case 52:
            vector<size_t> adjSett = {36,41};
            break;  
        case 53:
            vector<size_t> adjSett = {37,42};
            break;  
        case 54:
            vector<size_t> adjSett = {38,43};
            break;
        case 55:
            vector<size_t> adjSett = {39,44};
            break;
        case 56:
            vector<size_t> adjSett = {40,44};
            break;
        case 57:
            vector<size_t> adjSett = {40,45};
            break;
        case 58:
            vector<size_t> adjSett = {41,45};
            break;  
        case 59:
            vector<size_t> adjSett = {41,46};
            break;
        case 60:
            vector<size_t> adjSett = {42,46};
            break;
        case 61:
            vector<size_t> adjSett = {42,47};
            break;
        case 62: 
            vector<size_t> adjSett = {43,47};
            break;
        case 63:
            vector<size_t> adjSett = {44,48};
            break;
        case 64:
            vector<size_t> adjSett = {45,49};
            break;  
        case 65:
            vector<size_t> adjSett = {46,50};
            break;
        case 66:
            vector<size_t> adjSett = {47,51};
            break;
        case 67:
            vector<size_t> adjSett = {48,52};
            break;
        case 68:
            vector<size_t> adjSett = {49,52};
            break;
        case 69:
            vector<size_t> adjSett = {49,53};
            break;
        case 70:
            vector<size_t> adjSett = {50,53};
            break;
        case 71:
            vector<size_t> adjSett = {50,54};
            break;
        case 72:
            vector<size_t> adjSett = {51,54};
            break;
        default:
        throw invalid_argument("Invalid id, not a valid road id.");
        }
    }

    ~Road();

    std::string getType() const;
    void setType(const std::string& type);

    std::string getOwner() const;
    void setOwner(const std::string& owner);

    std::vector<Road*> getAdjacents() const;
    void addAdjacent(Road* road);
    void removeAdjacent(Road* road);
    string toString(size_t mode);

    // Other member functions specific to the Road class
};
}