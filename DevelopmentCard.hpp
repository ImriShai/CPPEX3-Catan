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
    int id;

public:
    virtual void use() = 0;
    // Add any common functionality or data members here
};
}