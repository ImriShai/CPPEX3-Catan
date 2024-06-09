#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../Consts.hpp"
using namespace std;
namespace ariel
{
class Tile
{
    private:
    string number = "";             // Number on the tile
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
    string getNumber() const;
    string getResource() const;
    vector<size_t> &getSettelments() ;
    char getId() const;
    string getResourceType() const;


};
}

