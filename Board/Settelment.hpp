#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Road.hpp"
#include "../Player.hpp"
#include "../Consts.hpp"
using namespace std;
namespace ariel{
class Settlement {
private:
    size_t value;
    string type;
    const size_t id;
    Player* owner;
    vector<size_t> adjSett;
    vector<size_t> adjRoads;
public:
    // Constructor
    Settlement(size_t id);
         

    // Getters
    size_t getValue() const;
    std::string getType() const;
    size_t getId() const;
     Player* getOwner() const;

    // Setters
    void setValue(size_t newValue);
    void setType(const std::string& newType);

    void setOwner(Player* newOwner);
    string toString(size_t mode);
    
};
}