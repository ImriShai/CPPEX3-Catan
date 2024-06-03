#include <string>
#include <iostream>
#include <vector>
#include "Road.hpp"
using namespace std;
namespace ariel{
class Settlement {
private:
    int value;
    string type;
    size_t id;
    Player owner;
    vector<size_t> adjSett;
    vector<size_t> adjRoads;


public:
    // Constructor
    Settlement(int value, const std::string& type, size_t id, const Player& owner);
         

    // Getters
    int getValue() const;
    std::string getType() const;
    size_t getId() const;
    const Player& getOwner() const;

    // Setters
    void setValue(int newValue);
    void setType(const std::string& newType);
    void setId(size_t newId);
    void setOwner(const Player& newOwner);
    
};
}