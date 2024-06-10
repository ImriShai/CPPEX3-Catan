#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "../Player.hpp"
#include "../Consts.hpp"

using namespace std;
namespace ariel{
class Road {
private:
    std::string type;
    const size_t id;
    Player* owner;
    vector<size_t> adjSettelments; 


public:
    Road(size_t id, vector<size_t> adjSettelments, string type);
    ~Road();
    string getType();
    void setType(const std::string& type);
   const Player* getOwner() const;
    void setOwner(Player* owner);
    const vector<size_t> &getAdjacents();
    string toString(size_t mode, Player* builder); 

    // Other member functions specific to the Road class
};
}