#include <string>
#include <vector>
#include <iostream>
#include "Player.hpp"
#include "Settelment.hpp"
namespace ariel{
class Road {
private:
    std::string type;
    Player owner;
    vector<size_t> adjSettelments; 
    size_t id;


public:
    Road(size_t id, const std::string& type, const Player& owner);

    ~Road();

    std::string getType() const;
    void setType(const std::string& type);

    std::string getOwner() const;
    void setOwner(const std::string& owner);

    std::vector<Road*> getAdjacents() const;
    void addAdjacent(Road* road);
    void removeAdjacent(Road* road);

    // Other member functions specific to the Road class
};
}