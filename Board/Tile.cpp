#include "Tile.hpp"
// Constructor implementation

ariel::Tile::Tile(char id):id(id)
{
    switch (id)
    {
    case 'A':
        id = 'A';
        number = 10;
        resource = "🪨";
        resourceType = "ORE";
        break;
    case 'B':
        id = 'B';
        number = 2;
        resource = "🐑";
        resourceType = "SHEEP";
        break;
    case 'C':
        id = 'C';
        number = 9;
        resource = "🪵";
        resourceType = "WOOD";
        break;
    case 'D':
        id = 'D';
        number = 12;
        resource = "🌾";
        resourceType = "WHEAT";
        break;
    case 'E':
        id = 'E';
        number = 6;
        resource = "🧱";
        resourceType = "BRICK";
        break;
    case 'F':
        id = 'F';
        number = 4;
        resource = "🐑";
        resourceType = "SHEEP";
        break;
    case 'G':
        id = 'G';
        number = 10;
        resource = "🧱";
        resourceType = "BRICK";
        break;
    case 'H':
        id = 'H';
        number = 9;
        resource = "🌾";
        resourceType = "WHEAT";
        break;
    case 'I':
        id = 'I';
        number = 11;
        resource = "🪵";
        resourceType = "WOOD";
        break;
    case 'J':
        id = 'J';
        number = 0;
        resource = "🏜️";
        resourceType = "DESERT";
        break;
    case 'K':
        id = 'K';
        number = 3;
        resource = "🪵";
        resourceType = "WOOD";
        break;
    case 'L':
        id = 'L';
        number = 8;
        resource = "🪨";
        resourceType = "ORE";
        break;
    case 'M':
        id = 'M';
        number = 8;
        resource = "🪵";
        resourceType = "WOOD";

        break;
    case 'N':
        id = 'N';
        number = 3;
        resource = "🪨";
        resourceType = "ORE";
        break;
    case 'O':
        id = 'O';
        number = 4;
        resource = "🌾";
        resourceType = "WHEAT";
        break;
    case 'P':
        id = 'P';
        number = 5;
        resource = "🐑";
        resourceType = "SHEEP";
        break;
    case 'Q':
        id = 'Q';
        number = 5;
        resource = "🧱";
        resourceType = "BRICK";
        break;
    case 'R':
        id = 'R';
        number = 6;
        resource = "🌾";
        resourceType = "WHEAT";
        break;
    case 'S':
        id = 'S';
        number = 11;
        resource = "🐑";
        resourceType = "SHEEP";
        break;
    }
}

// Destructor implementation
ariel::Tile::~Tile()
{
}

// Getter method for number
size_t ariel::Tile::getNumber() const
{
    return number;
}

// Setter method for number
void ariel::Tile::setNumber(size_t number)
{
    this->number = number;
}

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
 
