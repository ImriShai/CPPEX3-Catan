#include "Settelment.hpp"
using namespace std;
namespace ariel{
    Settlement::Settlement(size_t id )
        : value(Consts::VALUE::NONE), type("🟫"), id(id) ,owner(nullptr) {
            vector<size_t> adjSett;
            vector<size_t> adjRoads;
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
                // ... rest of the cases
                default:
                    throw std::invalid_argument("Invalid id, not a valid settelment id.");
            }
        }

    // Gettersw
    int Settlement::getValue() const { return value; }
    std::string Settlement::getType() const { return type; }
    size_t Settlement::getId() const { return id; }
    const Player& Settlement::getOwner() const { return *owner; }

    // Setters
    void Settlement::setValue(int newValue) { value = newValue; }
    void Settlement::setType(const std::string& newType) { type = newType; }
    
    void Settlement::setOwner(Player* newOwner) { owner = newOwner;}
    string Settlement::toString(size_t mode){
        switch (mode)
        {
        case Consts::REGULAR:
            return this->getType();
            break;
        case Consts::BUILD_SETTLEMENT:
            return to_string(this->getId());
            break;
        case Consts::BUILD_ROAD:
            return this->getType();
            break;
        default:
           throw invalid_argument("Invalid mode, not a valid mode.");
        }
    }
}