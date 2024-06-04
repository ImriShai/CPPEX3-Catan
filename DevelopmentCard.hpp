#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include "Player.hpp"
using namespace std;
namespace ariel
{
class DevelopmentCard {
private: 
    Player owner;
    string discription;
    bool isUsed;
    size_t id;
    size_t value;
public:
    virtual void use() = 0;
    // Add any common functionality or data members here
    virtual Player& getOwner() const;
    virtual void setOwner(const Player& owner);
    virtual string getDiscription() const;
    virtual size_t getId() const;
    virtual size_t getValue() const;
};
}