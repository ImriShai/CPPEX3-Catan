#include "Board.hpp"
using namespace std;
namespace ariel
{
    Board::Board()
    {
        for (size_t i = 0; i < 19; i++)
        {
            tiles[i] = new Tile('A' + i);
        }
        for (size_t i = 0; i < 54; i++)
        {
            settlements[i] = new Settlement(i + 1);
        }
        for (size_t i = 0; i < 72; i++)
        {
            roads[i] = new Road(i + 1);
        }
    }
    void Board::printBoard(size_t mode)
    {
        // for(Tile* t : tiles){
        //     cout<<t->getTileType()<<" ";
        // }
        // cout<<endl;
    }
    const Road *Board::getRoad(size_t id) const
    {
        if (id < 1 || id > 72)
        {
            throw invalid_argument("id must be between 1 and 72");
        }
        return roads[id - 1];
    }
    Settlement *Board::getSettlement(size_t id) const
    {
        if (id < 1 || id > 54)
        {
            throw invalid_argument("id must be between 1 and 54");
        }
        return settlements[id - 1];
    }

    Tile *Board::getTile(char id) const
    {
        if (id < 'A' || id > 'S')
        {
            throw invalid_argument("id must be between A and S");
        }
        return tiles[id - 'A'];
    }
    Board::~Board()
    {
        for (int i = 0; i < 19; i++)
        {
            delete tiles[i];
        }
        for (int i = 0; i < 54; i++)
        {
            delete settlements[i];
        }
        for (int i = 0; i < 72; i++)
        {
            delete roads[i];
        }
    }
    void Board::placeRoad(size_t id, Player *owner) const
    {
        roads[id - 1]->setOwner(owner);
        roads[id - 1]->setType(owner->getColor() + roads[id - 1]->getType() + Consts::WHITE); // set the color of the road by the owner
    }

    void Board::placeSettlement(size_t id, Player *owner) const
    {
        settlements[id - 1]->setOwner(owner);
        settlements[id - 1]->setType(owner->getColor()+ Consts::SETTELMENTEMOJI + Consts::WHITE);
    }
    void Board::placeCity(size_t id, Player *owner) const
    {
        settlements[id - 1]->setType(owner->getColor() + Consts::CITYEMOJI + Consts::WHITE);
    }
    bool Board::checkValidLocation(size_t id, size_t mode, Player *owner, bool firstRound) const
    {
        vector<size_t> adjSett;
        vector<size_t> adjRoads;
         switch (mode)
        {
        case Consts::BUILD_SETTLEMENT:
            adjSett = settlements[id - 1]->getAdjSett();
            adjRoads = settlements[id - 1]->getAdjRoads();
            if (id < 1 || id > 54)
            {
                return false;
            }
            if (settlements[id - 1]->getOwner() != nullptr)
            {
                cout << "settlement already exists" << endl;
                return false;
            }

            for (size_t i = 0; i < adjSett.size(); i++)
            {
                if (settlements[adjRoads[i] - 1]->getOwner() != nullptr)
                { // if there is a settlement in the adjacent settlements
                    cout << "adjacent settlement already exists" << endl;
                    return false;
                }
            }

            for (size_t i = 0; i < adjRoads.size(); i++)
            {
                if (firstRound || roads[adjRoads[i] - 1]->getOwner() == owner)
                { // a settlement can be built on the first round without a road nearby, otherwise a road must be nearby
                    return true;
                }
            }
            cout << "no road nearby" << endl;
            return false;
            break;
        case Consts::BUILD_ROAD:
            if (id < 1 || id > 72)
            {
                return false;
            }
            if (roads[id - 1]->getOwner() != nullptr)
            {
                return false;
            }
            adjSett = roads[id - 1]->getAdjacents();

            for (size_t adj : adjSett)
            {
                cout << owner->getName() << endl;
                // cout << settlements[adj-1]->getOwner()->getName() << endl;
                cout << settlements[adj - 1]->getId() << endl;
                if (settlements[adj - 1]->getOwner() == owner)
                { // to build a road, there must be a settlement of the player nearby
                    return true;
                }
            }
            cout << "no settlement nearby" << endl;
            return false;
        case Consts::BUILD_CITY:
            if (id < 1 || id > 54)
            {
                return false;
            }
            if (settlements[id - 1]->getOwner() != owner)
            {
                return false;
                cout << "This is not your settlement" << endl;
            }
            return true;
            break;
        default:
            throw invalid_argument("Invalid mode, not a valid mode.");
        }
    }

}