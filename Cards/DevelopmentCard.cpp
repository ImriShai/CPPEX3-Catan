#include "DevelopmentCard.hpp"
using namespace std;
namespace ariel
{
    // Add any common functionality or data members here

    string DevelopmentCard::getDiscription() const
    {
        return this->discription;
    }
    size_t DevelopmentCard::getType() const
    {
        return this->type;
    }
    size_t DevelopmentCard::getValue() const
    {
        return this->value;
    }
    bool DevelopmentCard::isUsed() const
    {
        return this->used;
    }
    void DevelopmentCard::setUsed(bool flag)
    {
        this->used = flag;
    }

}