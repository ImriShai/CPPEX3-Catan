#include <string>
#include <vector>
#include <iostream>
#include "Player.hpp"
#include "Settelment.hpp"
enum TO_STRING_MODE {REGULAR = 0, BUILDING = 1};

using namespace std;
namespace ariel{
class Road {
private:
    std::string type;
    Player owner;
    vector<size_t> adjSettelments; 
    const size_t id;


public:
    Road(size_t id);

    ~Road();

    std::string getType() const;
    void setType(const std::string& type);

    std::string getOwner() const;
    void setOwner(const std::string& owner);

    std::vector<Road*> getAdjacents() const;
    void addAdjacent(Road* road);
    void removeAdjacent(Road* road);
    string toString(size_t mode); 

    // Other member functions specific to the Road class
};
}