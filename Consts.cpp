#include "Consts.hpp"
//using escape sequences to color the output
const std::string ariel::Consts::RED = "\033[31m";
const std::string ariel::Consts::BLUE = "\033[34m";
const std::string ariel::Consts::ORANGE = "\033[33m";
const std::string ariel::Consts::WHITE = "\033[0m";
const std::string ariel::Consts::NUMBER = "\033[42m";
const std::string ariel::Consts::CITYEMOJI = "🏙";
const std::string ariel::Consts::SETTELMENTEMOJI = "🏘";


//check that the string contains only numbers, and represent a valid integer
static bool isValidNumber(const std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

/*
* @brief This method parses a string to a vector of resources.
* The string must contain exactly 5 numbers, separated by spaces.
* @param resource the string to parse
* @return a vector of size_t containing the parsed numbers
*/
const std::vector<size_t> ariel::Consts::parseResource(const std::string resource)
{

    std::vector<size_t> result;
    std::istringstream iss(resource);
    std::string token;

    while (iss >> token) { //split the string by spaces and checks if the token is a valid number
        if (!isValidNumber(token)) {
            throw std::invalid_argument("Input string contains non-numeric characters.");
        }
        result.push_back((size_t)std::stoi(token)); //convert the token to an integer and add it to the result vector
    }

   
    if (result.size() != 5) { //check that the result vecotr contains exactly 5 numbers
        throw std::invalid_argument("Input string must contain exactly 5 numbers.");
    }

    return result;
}

/*
* @brief This method returns the index of a resource in the RESOURCES vector.
* @param resource the name of the resource
* @return the index of the resource in the RESOURCES vector
* @throw invalid_argument if the resource name is invalid
*/
const size_t ariel::Consts::getResourceIndex(const std::string resource)
{
    if (resource == "BRICK") {
        return Consts::RESOURCE::BRICK;
    } else if (resource == "WOOD") {
        return Consts::RESOURCE::WOOD;
    } else if (resource == "WHEAT") {
        return Consts::RESOURCE::WHEAT;
    } else if (resource == "SHEEP") {
        return Consts::RESOURCE::SHEEP;
    } else if (resource == "ORE") {
        return Consts::RESOURCE::ORE;
    } else if(resource == "DESERT"){
        return Consts::RESOURCE::DESERT;
    }
    else {
        throw std::invalid_argument("Invalid resource name.");
    }
}
const std::vector<std::string> ariel::Consts::RESOURCES = {"BRICK", "WOOD", "WHEAT", "SHEEP", "ORE"}; //vector of resource names, with respect to the Enum RESOURCE

const std::unordered_map<size_t, std::vector<char>> ariel::Consts::resourceTiles = { //map between the number of the tile, and the id of the actual tiles that has that number
           {2, {'B'}},
           {3, {'K', 'N'}},
           {4, {'F', 'O'}},
           {5, {'P','Q'}},
           {6, {'E', 'R'}},
           {8, {'L','M'}},
           {9, {'C','H'}},
           {10, {'A','G'}},
           {11, {'I','S'}},
           {12, {'D'}}};
    

