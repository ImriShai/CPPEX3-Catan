#include "DevelopmentCard.hpp"
using namespace std;
namespace ariel
{
    // Add any common functionality or data members here


/**
 * @brief This function returns the description of the card
 * @return string the description of the card
 
 */
    string DevelopmentCard::getDescription() const
    {
        return this->description;
    }

/**
 * @brief This function returns the type of the card    
 * @return size_t the type of the card, as defined in the consts.hpp file
 */
    size_t DevelopmentCard::getType() const
    {
        return this->type;
    }


/**
 * @brief This function returns the value of the card
 * @return size_t the value of the card
  */
    size_t DevelopmentCard::getValue() const
    {
        return this->value;
    }

/**
 * @brief This function returns whether the card has been used or not
 * @return bool true if the card has been used, false otherwise
 */
    bool DevelopmentCard::isUsed() const
    {
        return this->used;
    }

/**
 * @brief This function sets the used flag of the card
 * @param flag the value to set the used flag to
 * @throw invalid_argument if the card has already been used and used flag is being set to false
 */
    void DevelopmentCard::setUsed(bool flag)
    {
        if(flag == false && this->used == true){
            throw invalid_argument("This card has already been used");
        }
        this->used = flag;
    }

}