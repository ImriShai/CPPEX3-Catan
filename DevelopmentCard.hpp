#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include "Consts.hpp"
using namespace std;
namespace ariel
{
class DevelopmentCard {
protected: 
    string discription;
    bool used;
    size_t id;
    size_t value;
public:
    virtual void useCard(Player& owner) = 0;
    // Add any common functionality or data members here
    virtual string getDiscription() const;
    virtual size_t getId() const;
    virtual size_t getValue() const;
    virtual bool isUsed() const;
    virtual void setUsed(bool flag);
    virtual ~DevelopmentCard() = default;
};
}