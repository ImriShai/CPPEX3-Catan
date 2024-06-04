#include <DevelopmentCard.hpp>
namespace ariel
{
    // Add any common functionality or data members here
    virtual Player& getOwner() const{
        return this->owner;
    
    }
    virtual void setOwner(const Player& owner){
        this->owner = owner;
    }
    virtual string getDiscription() const{
        return this->discription;
    }
    virtual size_t getId() const{
        return this->id;
    }
    virtual size_t getValue() const{
        return this->value;
    }

}