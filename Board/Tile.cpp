#include "Tile.hpp"
// Constructor implementation

ariel::Tile::Tile(char id):id(id)
{

    switch (id)
    {
    case 'A':
        number = Consts::NUMBER + "10" + Consts::WHITE ;
        resource = "🪨";
        resourceType = "ORE";
        settelments = {1,4,5,8,9,13};

        break;
    case 'B':
        number = Consts::NUMBER + "2" + Consts::WHITE;
        resource = "🐑";
        resourceType = "SHEEP";
        settelments = {2,5,6,10,14};
        break;
    case 'C':

        number = Consts::NUMBER + "9" + Consts::WHITE;
        resource = "🪵";
        resourceType = "WOOD";
        settelments = {3,6,7,10,11,15};
        break;
    case 'D':
        number = Consts::NUMBER + "12" + Consts::WHITE;
        resource = "🌾";
        resourceType = "WHEAT";
        settelments = {8,12,13,17,18,23};
        break;
    case 'E':
        number = Consts::NUMBER + "6" + Consts::WHITE;
        resource = "🧱";
        resourceType = "BRICK";
        settelments = {9,13,14,18,19,24};
        break;
    case 'F':
        number = Consts::NUMBER + "4" + Consts::WHITE;
        resource = "🐑";
        resourceType = "SHEEP";
        settelments = {10,14,15,19,20,25};
        break;
    case 'G':
        number = Consts::NUMBER + "10" + Consts::WHITE;
        resource = "🧱";
        resourceType = "BRICK";
        settelments = {11,15,16,20,21,26};
        break;
    case 'H':
        number = Consts::NUMBER + "9" + Consts::WHITE;
        resource = "🌾";
        resourceType = "WHEAT";
        settelments = {17,22,23,28,29,34};
        break;
    case 'I':
        number = Consts::NUMBER + "11" + Consts::WHITE;
        resource = "🪵";
        resourceType = "WOOD";
        settelments = {18,23,24,29,30,35};
        break;
    case 'J':
        number = "";
        resource = "🏜️";
        resourceType = "DESERT";
        settelments = {19,24,25,30,31,36};
        break;
    case 'K':
        number = Consts::NUMBER + "3" + Consts::WHITE;
        resource = "🪵";
        resourceType = "WOOD";
        settelments = {20,25,26,31,32,37};
        break;
    case 'L':
        number = Consts::NUMBER + "8" + Consts::WHITE;
        resource = "🪨";
        resourceType = "ORE";
        settelments = {21,26,27,32,33,38};
        break;
    case 'M':
        number = Consts::NUMBER + "8" + Consts::WHITE;
        resource = "🪵";
        resourceType = "WOOD";
        settelments = {29,34,35,39,40,44};

        break;
    case 'N':
        number = Consts::NUMBER + "3" + Consts::WHITE;
        resource = "🪨";
        resourceType = "ORE";
        settelments = {30,35,36,40,41,45};
        break;
    case 'O':
        number = Consts::NUMBER + "4" + Consts::WHITE;
        resource = "🌾";
        resourceType = "WHEAT";
        settelments = {31,36,37,41,42,46};
        break;
    case 'P':
        number = Consts::NUMBER + "5" + Consts::WHITE;
        resource = "🐑";
        resourceType = "SHEEP";
        settelments = {32,37,38,42,43,47};
        break;
    case 'Q':
        number = Consts::NUMBER + "5" + Consts::WHITE;
        resource = "🧱";
        resourceType = "BRICK";
        settelments = {40,44,45,48,49,52};
        break;
    case 'R':
        number = Consts::NUMBER + "6" + Consts::WHITE;
        resource = "🌾";
        resourceType = "WHEAT";
        settelments = {41,45,46,49,50,53};
        break;
    case 'S':
        number = Consts::NUMBER + "11" + Consts::WHITE;
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
    string ariel::Tile::getNumber() const{
        return number;
    }
 ariel::Tile::~Tile(){

 }
 
