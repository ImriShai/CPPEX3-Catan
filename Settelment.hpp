#include <string>
#include <iostream>
#include "Player.hpp"
using namespace std;
namespace ariel{
class Settlement {
private:
    int value;
    string type;
    int id;
    Player owner;

public:
    // Constructor
    Settlement(int value, const std::string& type, int id, const Player& owner)
        : value(value), type(type), id(id), owner(owner) {}

    // Getters
    int getValue() const { return value; }
    std::string getType() const { return type; }
    int getId() const { return id; }
    const Player& getOwner() const { return owner; }

    // Setters
    void setValue(int newValue) { value = newValue; }
    void setType(const std::string& newType) { type = newType; }
    void setId(int newId) { id = newId; }
    
};
}