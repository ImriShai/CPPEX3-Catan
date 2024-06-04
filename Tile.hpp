#include <iostream>
#include <string>
#include <vector>
using namespace std;
namespace ariel
{
class Tile
{
    private:
    size_t number;                 // Number on the tile
    string resource;            // Resource type on the tile
    const char id;                    // ID of the tile
    vector<size_t> roads;       // Vector of roads on the tile
    vector<size_t> settelments; // Vector of settelments on the tile
public:
    // Constructor
    Tile(char id);

    // Destructor
    ~Tile();

    // Getter and setter methods for tile properties
    size_t getNumber() const;
    void setNumber(int number);
    string getResource() const;
    void setSetellmentType(int index, int type);
    void setRoadOwner(int index);
    vector<size_t> &getSettelments() const;
    vector<size_t> &getRoads() const;
    char getId() const;


};
}

