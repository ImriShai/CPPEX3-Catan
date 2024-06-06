#include "Road.hpp"
using namespace std;
using namespace ariel;
Road::Road(size_t id) : id(id), owner(nullptr)
{
    vector<size_t> adjSett;
    string type;
    switch (id) // ADD type according to the id
    {
    case 1:
        adjSett = {1, 4};
        type = "/";
        break;
    case 2:
        adjSett = {1, 5};
        type = "\\";
        break;
    case 3:
        adjSett = {2, 5};
        type = "/";
        break;
    case 4:
        adjSett = {2, 6};
        type = "\\";
        break;
    case 5:
        adjSett = {3, 6};
        type = "/";
        break;
    case 6:
        adjSett = {3, 7};
        type = "\\";
        break;
    case 7:
        adjSett = {4, 8};
        type = "|";
        break;
    case 8:
        adjSett = {5, 9};
        type = "|";
        break;
    case 9:
        adjSett = {6, 10};
        type = "|";
        break;
    case 10:
        adjSett = {7, 11};
        type = "|";
        break;
    case 11:
        adjSett = {8, 12};
        type = "/";
        break;
    case 12:
        adjSett = {8, 13};
        type = "\\";
        break;
    case 13:
        adjSett = {9, 13};
        type = "/";
        break;
    case 14:
        adjSett = {9, 14};
        type = "\\";
        break;
    case 15:
        adjSett = {10, 14};
        type = "/";
        break;
    case 16:
        adjSett = {10, 15};
        type = "\\";
        break;
    case 17:
        adjSett = {11, 15};
        type = "/";
        break;
    case 18:
        adjSett = {11, 16};
        type = "\\";
        break;
    case 19:
        adjSett = {12, 17};
        type = "|";
        break;
    case 20:
        adjSett = {13, 18};
        type = "|";
        break;
    case 21:
        adjSett = {14, 19};
        type = "|";
        break;
    case 22:
        adjSett = {15, 20};
        type = "|";

        break;
    case 23:
        adjSett = {16, 21};
        type = "|";

        break;
    case 24:
        adjSett = {17, 22};
        type = "/";
        break;
    case 25:
        adjSett = {17, 23};
        type = "\\";
        break;
    case 26:
        adjSett = {18, 23};
        type = "/";
        break;
    case 27:
        adjSett = {18, 24};
        type = "\\";
        break;
    case 28:
        adjSett = {19, 24};
        type = "/";
        break;
    case 29:
        adjSett = {19, 25};
        type = "\\";
        break;
    case 30:
        adjSett = {20, 25};
        type = "/";
        break;
    case 31:
        adjSett = {20, 26};
        type = "\\";
        break;
    case 32:
        adjSett = {21, 26};
        type = "/";
        break;
    case 33:
        adjSett = {21, 27};
        type = "\\";
        break;
    case 34:
        adjSett = {22, 28};
        type = "|";

        break;
    case 35:
        adjSett = {23, 29};
        type = "|";

        break;
    case 36:
        adjSett = {24, 30};
        type = "|";

        break;
    case 37:
        adjSett = {25, 31};
        type = "|";

        break;
    case 38:
        adjSett = {26, 32};
        type = "|";

        break;
    case 39:
        adjSett = {27, 33};
        type = "|";

        break;
    case 40:
        adjSett = {28, 34};
        type = "\\";

        break;
    case 41:
        adjSett = {29, 34};
        type = "/";
        break;
    case 42:
        adjSett = {29, 35};
        type = "\\";
        break;
    case 43:
        adjSett = {30, 35};
        type = "/";
        break;
    case 44:
        adjSett = {30, 36};
        type = "\\";
        break;
    case 45:
        adjSett = {31, 36};
        type = "/";
        break;
    case 46:
        adjSett = {31, 37};
        type = "\\";
        break;
    case 47:
        adjSett = {32, 37};
        type = "/";
        break;
    case 48:
        adjSett = {32, 38};
        type = "\\";
        break;
    case 49:
        adjSett = {33, 38};
        type = "/";
        break;
    case 50:
        adjSett = {34, 39};
        type = "|";

        break;
    case 51:
        adjSett = {35, 40};
        type = "|";

        break;
    case 52:
        adjSett = {36, 41};
        type = "|";

        break;
    case 53:
        adjSett = {37, 42};
        type = "|";

        break;
    case 54:
        adjSett = {38, 43};
        type = "|";

        break;
    case 55:
        adjSett = {39, 44};
        type = "\\";
        break;
    case 56:
        adjSett = {40, 44};
        type = "/";
        break;
    case 57:
        adjSett = {40, 45};
        type = "\\";
        break;
    case 58:
        adjSett = {41, 45};
        type = "/";
        break;
    case 59:
        adjSett = {41, 46};
        type = "\\";
        break;
    case 60:
        adjSett = {42, 46};
        type = "/";
        break;
    case 61:
        adjSett = {42, 47};
        type = "\\";
        break;
    case 62:
        adjSett = {43, 47};
        type = "/";
        break;
    case 63:
        adjSett = {44, 48};
        type = "|";

        break;
    case 64:
        adjSett = {45, 49};
        type = "|";

        break;
    case 65:
        adjSett = {46, 50};
        type = "|";

        break;
    case 66:
        adjSett = {47, 51};
        type = "|";

        break;
    case 67:
        adjSett = {48, 52};
        type = "\\";
        break;
    case 68:
        adjSett = {49, 52};
        type = "/";
        break;
    case 69:
        adjSett = {49, 53};
        type = "\\";
        break;
    case 70:
        adjSett = {50, 53};
        type = "/";
        break;
    case 71:
        adjSett = {50, 54};
        type = "\\";
        break;
    case 72:
        adjSett = {51, 54};
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
string Road::toString(size_t mode)
{
    switch (mode)
    {
    case Consts::REGULAR:
        return this->getType();
        break;
    case Consts::BUILD_SETTLEMENT:
        return this->getType();
        break;
    case Consts::BUILD_ROAD:
        return to_string(this->id);
        break;
    default:
        throw invalid_argument("Invalid mode, not a valid mode.");
    }
}