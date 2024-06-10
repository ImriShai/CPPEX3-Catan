#include "Road.hpp"
using namespace std;
using namespace ariel;
/**
 * @brief Construct a new Road:: Road object
 * Construct a new Road object with the given id
*/
Road::Road(size_t id, vector<size_t> adjSettelments, string type) : id(id) 
{
    this->owner = nullptr;
    this->adjSettelments = adjSettelments;
    this->type = type;
}
/**
* @brief Destroy the Road:: Road object
* Destroy the Road object
*/
Road::~Road()
{
}

/**
 * @brief Get the Type object
 * @return string 
 */
std::string Road::getType()
{
    return this->type;
}

/**
 * @brief Get the Owner object
 * @return const Player* 
 */
const Player *Road::getOwner() const
{
    return owner;
}

/**
 * @brief Set the Type object
 * @param const std::string &type 
 */
void Road::setType(const std::string &type)
{
    this->type = type;
}

/**
 * @brief Set the Owner object
 * @param Player *owner 
 * @throw invalid_argument if the road already has an owner
 */
void Road::setOwner(Player *owner)
{
    if (this->owner != nullptr)
    {
        throw invalid_argument("Road already has an owner");
    }
    this->owner = owner;
}

/**
 * @brief Get the Adjacents object
 * @return const vector<size_t>& 
 */
const vector<size_t> &Road::getAdjacents()
{
    return this->adjSettelments;
}

/**
 * @brief Convert the road to a string. The mode determines how the road is converted, for different porpuses.
 * @param size_t mode 
 * @param Player *builder 
 * @return string 
 * @throw invalid_argument if the mode is not valid
 */
string Road::toString(size_t mode, Player *builder)
{
    switch (mode)
    {
    case Consts::REGULAR:
        return this->getType();
        break;
    case Consts::BUILD_SETTLEMENT:
        return this->getType();
        break;
    case Consts::BUILD_CITY:
        return this->getType();
        break;
    case Consts::BUILD_ROAD:
        if (this->getOwner() != nullptr)
        {
            return this->getType();
        }
        return to_string(this->id);
        
        break;
    default:
        throw invalid_argument("Invalid mode, not a valid mode.");
    }
}