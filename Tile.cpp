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
        

        break;
    case 'B':
        id = 'B';
        number = 2;
        resource = "🐑";
        break;
    case 'C':
        id = 'C';
        number = 9;
        resource = "🪵";
        break;
    case 'D':
        id = 'D';
        number = 12;
        resource = "🌾";
        break;
    case 'E':
        id = 'E';
        number = 6;
        resource = "🧱";
        break;
    case 'F':
        id = 'F';
        number = 4;
        resource = "🐑";
        break;
    case 'G':
        id = 'G';
        number = 10;
        resource = "🧱";
        break;
    case 'H':
        id = 'H';
        number = 9;
        resource = "🌾";
        break;
    case 'I':
        id = 'I';
        number = 11;
        resource = "🪵";
        break;
    case 'J':
        id = 'J';
        number = 0;
        resource = "🏜️";
        break;
    case 'K':
        id = 'K';
        number = 3;
        resource = "🪵";
        break;
    case 'L':
        id = 'L';
        number = 8;
        resource = "🪨";
        break;
    case 'M':
        id = 'M';
        number = 8;
        resource = "🪵";
        break;
    case 'N':
        id = 'N';
        number = 3;
        resource = "🪨";
        break;
    case 'O':
        id = 'O';
        number = 4;
        resource = "🌾";
        break;
    case 'P':
        id = 'P';
        number = 5;
        resource = "🐑";
        break;
    case 'Q':
        id = 'Q';
        number = 5;
        resource = "🧱";
        break;
    case 'R':
        id = 'R';
        number = 6;
        resource = "🌾";
        break;
    case 'S':
        id = 'S';
        number = 11;
        resource = "🐑";
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
void ariel::Tile::setNumber(int number)
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
