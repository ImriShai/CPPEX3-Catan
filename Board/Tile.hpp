#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
namespace ariel
{
class Tile
{
    private:
    size_t number = 0;             // Number on the tile
    string resource = "";         // Resource type on the tile
    string resourceType = "";    // Resource type on the tile
    const char id;                 // ID of the tile
    vector<size_t> settelments = {}; // Vector of settelments on the tile
public:
    // Constructor
    Tile(char id);

    // Destructor
    ~Tile();

    // Getter and setter methods for tile properties
    size_t getNumber() const;
    string getResource() const;
    vector<size_t> &getSettelments() ;
    char getId() const;
    string getResourceType() const;


};
}

