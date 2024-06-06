#include "Tile.hpp"
// Constructor implementation

ariel::Tile::Tile(char id):id(id)
{

    switch (id)
    {
    case 'A':
        number = 10;
        resource = "🪨";
        resourceType = "ORE";
        settelments = {1,4,5,8,9,13};

        break;
    case 'B':
        number = 2;
        resource = "🐑";
        resourceType = "SHEEP";
        settelments = {2,5,6,10,14};
        break;
    case 'C':

        number = 9;
        resource = "🪵";
        resourceType = "WOOD";
        settelments = {3,6,7,10,11,15};
        break;
    case 'D':
        number = 12;
        resource = "🌾";
        resourceType = "WHEAT";
        settelments = {8,12,13,17,18,23};
        break;
    case 'E':
        number = 6;
        resource = "🧱";
        resourceType = "BRICK";
        settelments = {9,13,14,18,19,24};
        break;
    case 'F':
        number = 4;
        resource = "🐑";
        resourceType = "SHEEP";
        settelments = {10,14,15,19,20,25};
        break;
    case 'G':
        number = 10;
        resource = "🧱";
        resourceType = "BRICK";
        settelments = {11,15,16,20,21,26};
        break;
    case 'H':
        number = 9;
        resource = "🌾";
        resourceType = "WHEAT";
        settelments = {17,22,23,28,29,34};
        break;
    case 'I':
        number = 11;
        resource = "🪵";
        resourceType = "WOOD";
        settelments = {18,23,24,29,30,35};
        break;
    case 'J':
        number = 0;
        resource = "🏜️";
        resourceType = "DESERT";
        settelments = {19,24,25,30,31,36};
        break;
    case 'K':
        number = 3;
        resource = "🪵";
        resourceType = "WOOD";
        settelments = {20,25,26,31,32,37};
        break;
    case 'L':
        number = 8;
        resource = "🪨";
        resourceType = "ORE";
        settelments = {21,26,27,32,33,38};
        break;
    case 'M':
        number = 8;
        resource = "🪵";
        resourceType = "WOOD";
        settelments = {29,34,35,39,40,44};

        break;
    case 'N':
        number = 3;
        resource = "🪨";
        resourceType = "ORE";
        settelments = {30,35,36,40,41,45};
        break;
    case 'O':
        number = 4;
        resource = "🌾";
        resourceType = "WHEAT";
        settelments = {31,36,37,41,42,46};
        break;
    case 'P':
        number = 5;
        resource = "🐑";
        resourceType = "SHEEP";
        settelments = {32,37,38,42,43,47};
        break;
    case 'Q':
        number = 5;
        resource = "🧱";
        resourceType = "BRICK";
        settelments = {40,44,45,48,49,52};
        break;
    case 'R':
        number = 6;
        resource = "🌾";
        resourceType = "WHEAT";
        settelments = {41,45,46,49,50,53};
        break;
    case 'S':
        number = 11;
        resource = "🐑";
        resourceType = "SHEEP";
        settelments = {42,46,47,50,51,54};
        break;
    }
}

// Destructor implementation
vector<size_t>& ariel::Tile::getSettelments()
{
    return settelments;
}

// Setter method for number


// Getter method for resource
std::string ariel::Tile::getResource() const
{
    return resource;
}

 char ariel::Tile::getId() const{
        return id;
 }
 string ariel::Tile::getResourceType() const{
     return resourceType;
 }
 ariel::Tile::~Tile(){

 }
 
