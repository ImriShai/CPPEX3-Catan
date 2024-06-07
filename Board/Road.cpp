#include "Road.hpp"
using namespace std;
using namespace ariel;
Road::Road(size_t id) 
{
    this->id = id;
    this->owner = nullptr;
    switch (id) // ADD type according to the id
    {
    case 1:
        adjSettelments = {1, 4};
        type = "/";
        break;
    case 2:
        adjSettelments = {1, 5};
        type = "\\";
        break;
    case 3:
        adjSettelments = {2, 5};
        type = "/";
        break;
    case 4:
        adjSettelments = {2, 6};
        type = "\\";
        break;
    case 5:
        adjSettelments = {3, 6};
        type = "/";
        break;
    case 6:
        adjSettelments = {3, 7};
        type = "\\";
        break;
    case 7:
        adjSettelments = {4, 8};
        type = "|";
        break;
    case 8:
        adjSettelments = {5, 9};
        type = "|";
        break;
    case 9:
        adjSettelments = {6, 10};
        type = "|";
        break;
    case 10:
        adjSettelments = {7, 11};
        type = "|";
        break;
    case 11:
        adjSettelments = {8, 12};
        type = "/";
        break;
    case 12:
        adjSettelments = {8, 13};
        type = "\\";
        break;
    case 13:
        adjSettelments = {9, 13};
        type = "/";
        break;
    case 14:
        adjSettelments = {9, 14};
        type = "\\";
        break;
    case 15:
        adjSettelments = {10, 14};
        type = "/";
        break;
    case 16:
        adjSettelments = {10, 15};
        type = "\\";
        break;
    case 17:
        adjSettelments = {11, 15};
        type = "/";
        break;
    case 18:
        adjSettelments = {11, 16};
        type = "\\";
        break;
    case 19:
        adjSettelments = {12, 17};
        type = "|";
        break;
    case 20:
        adjSettelments = {13, 18};
        type = "|";
        break;
    case 21:
        adjSettelments = {14, 19};
        type = "|";
        break;
    case 22:
        adjSettelments = {15, 20};
        type = "|";

        break;
    case 23:
        adjSettelments = {16, 21};
        type = "|";

        break;
    case 24:
        adjSettelments = {17, 22};
        type = "/";
        break;
    case 25:
        adjSettelments = {17, 23};
        type = "\\";
        break;
    case 26:
        adjSettelments = {18, 23};
        type = "/";
        break;
    case 27:
        adjSettelments = {18, 24};
        type = "\\";
        break;
    case 28:
        adjSettelments = {19, 24};
        type = "/";
        break;
    case 29:
        adjSettelments = {19, 25};
        type = "\\";
        break;
    case 30:
        adjSettelments = {20, 25};
        type = "/";
        break;
    case 31:
        adjSettelments = {20, 26};
        type = "\\";
        break;
    case 32:
        adjSettelments = {21, 26};
        type = "/";
        break;
    case 33:
        adjSettelments = {21, 27};
        type = "\\";
        break;
    case 34:
        adjSettelments = {22, 28};
        type = "|";

        break;
    case 35:
        adjSettelments = {23, 29};
        type = "|";

        break;
    case 36:
        adjSettelments = {24, 30};
        type = "|";

        break;
    case 37:
        adjSettelments = {25, 31};
        type = "|";

        break;
    case 38:
        adjSettelments = {26, 32};
        type = "|";

        break;
    case 39:
        adjSettelments = {27, 33};
        type = "|";

        break;
    case 40:
        adjSettelments = {28, 34};
        type = "\\";

        break;
    case 41:
        adjSettelments = {29, 34};
        type = "/";
        break;
    case 42:
        adjSettelments = {29, 35};
        type = "\\";
        break;
    case 43:
        adjSettelments = {30, 35};
        type = "/";
        break;
    case 44:
        adjSettelments = {30, 36};
        type = "\\";
        break;
    case 45:
        adjSettelments = {31, 36};
        type = "/";
        break;
    case 46:
        adjSettelments = {31, 37};
        type = "\\";
        break;
    case 47:
        adjSettelments = {32, 37};
        type = "/";
        break;
    case 48:
        adjSettelments = {32, 38};
        type = "\\";
        break;
    case 49:
        adjSettelments = {33, 38};
        type = "/";
        break;
    case 50:
        adjSettelments = {34, 39};
        type = "|";

        break;
    case 51:
        adjSettelments = {35, 40};
        type = "|";

        break;
    case 52:
        adjSettelments = {36, 41};
        type = "|";

        break;
    case 53:
        adjSettelments = {37, 42};
        type = "|";

        break;
    case 54:
        adjSettelments = {38, 43};
        type = "|";

        break;
    case 55:
        adjSettelments = {39, 44};
        type = "\\";
        break;
    case 56:
        adjSettelments = {40, 44};
        type = "/";
        break;
    case 57:
        adjSettelments = {40, 45};
        type = "\\";
        break;
    case 58:
        adjSettelments = {41, 45};
        type = "/";
        break;
    case 59:
        adjSettelments = {41, 46};
        type = "\\";
        break;
    case 60:
        adjSettelments = {42, 46};
        type = "/";
        break;
    case 61:
        adjSettelments = {42, 47};
        type = "\\";
        break;
    case 62:
        adjSettelments = {43, 47};
        type = "/";
        break;
    case 63:
        adjSettelments = {44, 48};
        type = "|";

        break;
    case 64:
        adjSettelments = {45, 49};
        type = "|";

        break;
    case 65:
        adjSettelments = {46, 50};
        type = "|";

        break;
    case 66:
        adjSettelments = {47, 51};
        type = "|";

        break;
    case 67:
        adjSettelments = {48, 52};
        type = "\\";
        break;
    case 68:
        adjSettelments = {49, 52};
        type = "/";
        break;
    case 69:
        adjSettelments = {49, 53};
        type = "\\";
        break;
    case 70:
        adjSettelments = {50, 53};
        type = "/";
        break;
    case 71:
        adjSettelments = {50, 54};
        type = "\\";
        break;
    case 72:
        adjSettelments = {51, 54};
        type = "/";
        break;
    default:
        throw invalid_argument("Invalid id, not a valid road id.");
    }
}

Road::~Road()
{
}

std::string Road::getType()
{
    return this->type;
}
const Player *Road::getOwner() const
{
    return owner;
}
void Road::setType(const std::string &type)
{
    this->type = type;
}
void Road::setOwner(Player *owner)
{
    if (this->owner != nullptr)
    {
        throw invalid_argument("Road already has an owner");
    }
    this->owner = owner;
}
const vector<size_t> &Road::getAdjacents()
{
    return this->adjSettelments;
}
string Road::toString(size_t mode, Player *builder)
{
    switch (mode)
    {
    case Consts::REGULAR:
        return this->getType();
        break;
    case Consts::BUILD_SETTLEMENT:
        return this->getType();
        break;
    case Consts::BUILD_CITY:
        return this->getType();
        break;
    case Consts::BUILD_ROAD:
        if (this->getOwner() != nullptr)
        {
            return this->getType();
        }
        return to_string(this->id);
        break;
    default:
        throw invalid_argument("Invalid mode, not a valid mode.");
    }
}