#include "Consts.hpp"
const std::string ariel::Consts::RED = "/033[1;31m";
const std::string ariel::Consts::BLUE = "/033[1;34m";
const std::string ariel::Consts::ORANGE = "/033[1;33m";
const std::vector<size_t> ariel::Consts::parseResource(const std::string resource)
{

    std::vector<size_t> result;
    std::istringstream iss(resource);
    std::string token;

    while (iss >> token) {
        if (!isValidNumber(token)) {
            throw std::invalid_argument("Input string contains non-numeric characters.");
        }
        result.push_back(std::stoi(token));
    }

    // Ensure the vector has exactly 5 elements
    if (result.size() != 5) {
        throw std::invalid_argument("Input string must contain exactly 5 numbers.");
    }

    return result;
}
static bool isValidNumber(const std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}
