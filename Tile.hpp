#include <iostream>
#include <string>
#include <vector>
using namespace std;
namespace ariel
{
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
    char getId() const;

private:
    int number;                 // Number on the tile
    string resource;            // Resource type on the tile
    char id;                    // ID of the tile
    vector<string> roads;       // Vector of roads on the tile
    vector<string> settelments; // Vector of settelments on the tile
};
}

