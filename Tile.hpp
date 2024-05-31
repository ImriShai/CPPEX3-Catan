#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Tile
{
public:
    // Constructor
    Tile(char id);

    // Destructor
    ~Tile();

    // Getter and setter methods for tile properties
    int getNumber() const;
    void setNumber(int number);
    string getResource() const;
    void setSetellmentType(int index, int type);
    void setRoadOwner(int index);
    vector<string> &getSettelments() const;
    vector<string> &getRoads() const;

private:
    int number;                 // Number on the tile
    string resource;            // Resource type on the tile
    char id;                    // ID of the tile
    vector<string> roads;       // Vector of roads on the tile
    vector<string> settelments; // Vector of settelments on the tile
};

// Constructor implementation
Tile::Tile(char id)
{
    switch (id)
    {
    case 'A':
        id = 'A';
        number = 10;
        resource = "🪨";
        roads = vector<string>(3);
        settelments = vector<string>(2, "◽");

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
Tile::~Tile()
{
}

// Getter method for number
int Tile::getNumber() const
{
    return number;
}

// Setter method for number
void Tile::setNumber(int number)
{
    this->number = number;
}

// Getter method for resource
std::string Tile::getResource() const
{
    return resource;
}
