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

/**
 * @brief This class is an Abstract class representing a development card in the game.
*/
class DevelopmentCard {
protected: 
    string description;
    bool used;
    size_t type;
    size_t value;
public:
    virtual void useCard(Player& ,Catan&) = 0;
    // Add any common functionality or data members here
    virtual string getDescription() const;
    virtual size_t getType() const;
    virtual size_t getValue() const;
    virtual bool isUsed() const;
    virtual void setUsed(bool flag);
    virtual ~DevelopmentCard() = default;
};
}