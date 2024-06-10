#include "Tile.hpp"
// Constructor implementation


/**
 * @brief Construct a new Tile:: Tile object
 * Construct a new Tile object with the given id, number, resource, resourceType and settelments
*/
ariel::Tile::Tile(char id, string number, string resource, string resourceType, vector<size_t> settelments   ):id(id)
{
    this->number = number;
    this->resource = resource;
    this->resourceType = resourceType;
    this->settelments = settelments;
}

/**
 * @brief Get the Tile Settelments vector
 * @return vector<size_t>& the vector of settelments on the tile
*/
vector<size_t>& ariel::Tile::getSettelments()
{
    return settelments;
}

/**
 * @brief Get the Tile Number
 * @return string the number on the tile
*/
 string ariel::Tile::getNumber() const{
        return number;
    }

/**
 * @brief Get the Tile Resource
 * @return string the resource emoji on the tile

*/
std::string ariel::Tile::getResource() const
{
    return resource;
}

/**
 * @brief Get the Tile Id
 * @return char the id of the tile
 * */
 char ariel::Tile::getId() const{
        return id;
 }

    /**
    * @brief Get the Tile Resource Type
    * @return string the resource name on the tile
    */
 string ariel::Tile::getResourceType() const{
     return resourceType;
 }

/**
 * @brief Destroy the Tile:: Tile object
*/
 ariel::Tile::~Tile(){

 }
 
