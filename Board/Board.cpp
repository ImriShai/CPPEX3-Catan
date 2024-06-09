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
    void Board::printBoard(size_t mode, Player *builder) const
    {
        cout << "           " <<  settlements[0]->toString(mode,builder) << "     " <<  settlements[1] ->toString(mode, builder) << "      " <<  settlements[2] ->toString(mode, builder) << "\n"
         << "          " << roads[0]->toString(mode,builder) << "   " << roads[1]->toString(mode,builder) << "  " << roads[2]->toString(mode,builder) << "   " << roads[3]->toString(mode,builder) << "   " << roads[4]->toString(mode,builder) << "   " << roads[5]->toString(mode,builder) << "\n"
         << "        " <<  settlements[3] ->toString(mode, builder) << "    " <<  settlements[4] ->toString(mode, builder) << "       " <<  settlements[5] ->toString(mode, builder) << "      " <<  settlements[6] ->toString(mode, builder) << "\n"
         << "         " << roads[6]->toString(mode,builder) << " " <<  tiles[0]->getResource() <<"   " <<roads[7]->toString(mode,builder)  << "  " <<  tiles[1]->getResource() << "   " <<roads[8]->toString(mode,builder) <<"  "<<   tiles[2]->getResource() << "    " << roads[9]->toString(mode,builder) << "\n"
         << "        " <<  settlements[7] ->toString(mode, builder) << " " <<  tiles[0]->getNumber() << "  " <<  settlements[8] ->toString(mode, builder) << "   " <<  tiles[1]->getNumber() << " " <<  settlements[9] ->toString(mode, builder) << "  " <<  tiles[2]->getNumber() << "  " <<  settlements[10] ->toString(mode, builder) << "\n"
         << "       " << roads[10]->toString(mode,builder) << "   " << roads[11]->toString(mode,builder) << " " << roads[12]->toString(mode,builder) << "   " << roads[13]->toString(mode,builder) << "   " << roads[14]->toString(mode,builder) << "   " << roads[15]->toString(mode,builder) << "  " << roads[16]->toString(mode,builder) << "   " << roads[17]->toString(mode,builder) << " \n" //row5
         << "      " <<  settlements[11] ->toString(mode, builder) << "    " <<  settlements[12] ->toString(mode, builder) << "     " <<  settlements[13] ->toString(mode, builder) << "      " <<  settlements[14] ->toString(mode, builder) << "    " <<  settlements[15] ->toString(mode, builder) << "\n" //row6
         << "      " << roads[18]->toString(mode,builder) << "  " <<  tiles[3]->getResource()<< "  " << roads[19]->toString(mode,builder) << "  " <<  tiles[4]->getResource()<< "  " << roads[20]->toString(mode,builder) << "  " <<  tiles[5]->getResource()<<"  " << roads[21]->toString(mode,builder) << "  " <<  tiles[6]->getResource() << "  " << roads[22]->toString(mode,builder) << "\n" //row7
         << "      " <<  settlements[16] ->toString(mode, builder) << " " <<  tiles[3]->getNumber() << "  " <<  settlements[17] ->toString(mode, builder) << "  " <<  tiles[4]->getNumber() << "  " <<  settlements[18] ->toString(mode, builder) << "  " <<  tiles[5]->getNumber() << "  " <<  settlements[19] ->toString(mode, builder) << "  " <<  tiles[6]->getNumber() << "  " <<  settlements[20] ->toString(mode, builder) << "\n" //row8
         << "    " << roads[23]->toString(mode,builder) << "   " << roads[24]->toString(mode,builder) << "  " << roads[25]->toString(mode,builder) << "  " << roads[26]->toString(mode,builder) << "    " << roads[27]->toString(mode,builder) << "   " << roads[28]->toString(mode,builder) << " " << roads[29]->toString(mode,builder) << "   " << roads[30]->toString(mode,builder) << "  " << roads[31]->toString(mode,builder) << "   " << roads[32]->toString(mode,builder) << "\n" //row9 
         << "   " <<  settlements[21] ->toString(mode, builder) << "    " <<  settlements[22] ->toString(mode, builder) << "     " <<  settlements[23] ->toString(mode, builder) << "     " <<  settlements[24] ->toString(mode, builder) << "     " <<  settlements[25] ->toString(mode, builder) << "     " <<  settlements[26] ->toString(mode, builder) << "\n" // row10
         << "   " << roads[33]->toString(mode,builder) << "  " <<  tiles[7]->getResource()<< "  " << roads[34]->toString(mode,builder) << "  " <<  tiles[8]->getResource()<<"  " << roads[35]->toString(mode,builder) << "  " <<  tiles[9]->getResource()<<"   " << roads[36]->toString(mode,builder) << "  " <<  tiles[10]->getResource() <<"   " << roads[37]->toString(mode,builder) << "  " <<  tiles[11]->getResource() << "    " << roads[38]->toString(mode,builder) << "\n"//row11
         << "   " <<  settlements[27] ->toString(mode, builder) << "  " <<  tiles[7]->getNumber() << "  " <<  settlements[28] ->toString(mode, builder) << " " <<  tiles[8]->getNumber() << " " <<  settlements[29] ->toString(mode, builder) << "   " <<  tiles[9]->getNumber() << "  " <<  settlements[30] ->toString(mode, builder) << "  " <<  tiles[10]->getNumber() << "  " <<  settlements[31] ->toString(mode, builder) << "   " <<  tiles[11]->getNumber() << "  " <<  settlements[32] ->toString(mode, builder) << "\n"
         << "    " << roads[39]->toString(mode,builder) << "    " << roads[40]->toString(mode,builder) << " " << roads[41]->toString(mode,builder) << "   " << roads[42]->toString(mode,builder) << "   " << roads[43]->toString(mode,builder) << "  " << roads[44]->toString(mode,builder) << "   " << roads[45]->toString(mode,builder) << "  " << roads[46]->toString(mode,builder) << "   " << roads[47]->toString(mode,builder) << "   " << roads[48]->toString(mode,builder) << "\n"
         << "      " <<  settlements[33] ->toString(mode, builder) << "     " <<  settlements[34] ->toString(mode, builder) << "      " <<  settlements[35] ->toString(mode, builder) << "    " <<  settlements[36] ->toString(mode, builder) << "      " <<  settlements[37] ->toString(mode, builder) << "\n"
         << "      " << roads[49]->toString(mode,builder) << "  " <<  tiles[12]->getResource()<<"    " << roads[50]->toString(mode,builder) << "  " <<  tiles[13]->getResource()<<"   " << roads[51]->toString(mode,builder) << "  " <<  tiles[14]->getResource()<<" " << roads[52]->toString(mode,builder) << "    " <<  tiles[15]->getResource()<<" " << roads[53]->toString(mode,builder) << " \n" //looks good
         << "      " <<  settlements[38] ->toString(mode, builder) << "  " <<  tiles[12]->getNumber() << "  " <<  settlements[39] ->toString(mode, builder) << "   " <<  tiles[13]->getNumber() << "  " <<  settlements[40] ->toString(mode, builder) << "  " <<  tiles[14]->getNumber() << "  " <<  settlements[41] ->toString(mode, builder) << "   " <<  tiles[15]->getNumber() << " " <<  settlements[42] ->toString(mode, builder) << "\n"
         << "       " << roads[54]->toString(mode,builder) << "    " << roads[55]->toString(mode,builder) << "  " << roads[56]->toString(mode,builder) << "   " << roads[57]->toString(mode,builder) << "   " << roads[58]->toString(mode,builder) << "   " << roads[59]->toString(mode,builder) << "   " << roads[60]->toString(mode,builder) << "   " << roads[61]->toString(mode,builder) << "\n" //looksfine
         << "         " <<  settlements[43] ->toString(mode, builder) << "      " <<  settlements[44] ->toString(mode, builder) << "      " <<  settlements[45] ->toString(mode, builder) << "      " <<  settlements[46] ->toString(mode, builder) << "\n" //sofarsogood
         << "          " << roads[62]->toString(mode,builder) << "  " <<  tiles[16]->getResource()<<"  " << roads[63]->toString(mode,builder) << "  " <<  tiles[17]->getResource()<<"   " << roads[64]->toString(mode,builder) << "   " <<  tiles[18]->getResource()<<"  " << roads[65]->toString(mode,builder) << "  \n"
         << "          " <<  settlements[47] ->toString(mode, builder) << "  " <<  tiles[16]->getNumber() << "  " <<  settlements[48] ->toString(mode, builder) << "  " <<  tiles[17]->getNumber() << "  " <<  settlements[49] ->toString(mode, builder) << "   " <<  tiles[18]->getNumber() << " " <<  settlements[50] ->toString(mode, builder) << "\n"
         << "            " << roads[66]->toString(mode,builder)<<"  " << roads[67]->toString(mode,builder) << "   " << roads[68]->toString(mode,builder) << "  " << roads[69]->toString(mode,builder) << "   " << roads[70]->toString(mode,builder) << "    " << roads[71]->toString(mode,builder) << "   \n"
         << "            " <<  settlements[51] ->toString(mode, builder) << "      " <<  settlements[52] ->toString(mode, builder) << "      " <<  settlements[53] ->toString(mode, builder) << "\n";
      
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