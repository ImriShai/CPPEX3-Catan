#include "Consts.hpp"
const std::string ariel::Consts::RED = "/033[1;31m";
const std::string ariel::Consts::BLUE = "/033[1;34m";
const std::string ariel::Consts::ORANGE = "/033[1;33m";
const std::string ariel::Consts::WHITE = "/033[0m";

static bool isValidNumber(const std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

const std::vector<size_t> ariel::Consts::parseResource(const std::string resource)
{

    std::vector<size_t> result;
    std::istringstream iss(resource);
    std::string token;

    while (iss >> token) {
        if (!isValidNumber(token)) {
            throw std::invalid_argument("Input string contains non-numeric characters.");
        }
        result.push_back((size_t)std::stoi(token));
    }

    // Ensure the vector has exactly 5 elements
    if (result.size() != 5) {
        throw std::invalid_argument("Input string must contain exactly 5 numbers.");
    }

    return result;
}
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
    } else {
        throw std::invalid_argument("Invalid resource name.");
    }
}
const std::vector<std::string> ariel::Consts::RESOURCES = {"BRICK", "WOOD", "WHEAT", "SHEEP", "ORE"};

const std::unordered_map<size_t, std::vector<char>> ariel::Consts::resourceTiles = {
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
    

