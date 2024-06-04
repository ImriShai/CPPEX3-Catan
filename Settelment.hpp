#include <string>
#include <iostream>
#include <vector>
#include "Road.hpp"
enum  TO_STRING_MODE {REGULAR = 0, BUILDING = 1};
enum  VALUE {NONE = 0, SETTELMENT = 1, CITY =2};
using namespace std;
namespace ariel{
class Settlement {
private:
    size_t value;
    string type;
    const size_t id;
    Player owner;
    vector<size_t> adjSett;
    vector<size_t> adjRoads;


public:
    // Constructor
    Settlement(size_t id);
         

    // Getters
    int getValue() const;
    std::string getType() const;
    size_t getId() const;
    const Player& getOwner() const;

    // Setters
    void setValue(int newValue);
    void setType(const std::string& newType);

    void setOwner(const Player& newOwner);
    string toString(size_t mode);
    
};
}