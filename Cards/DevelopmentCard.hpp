#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include "../Consts.hpp"


using namespace std;
namespace ariel
{
class Player;
class Catan;
class DevelopmentCard {
protected: 
    string discription;
    bool used;
    size_t type;
    size_t value;
public:
    virtual void useCard(Player& ,Catan&) = 0;
    // Add any common functionality or data members here
    virtual string getDiscription() const;
    virtual size_t getType() const;
    virtual size_t getValue() const;
    virtual bool isUsed() const;
    virtual void setUsed(bool flag);
    virtual ~DevelopmentCard() = default;
};
}