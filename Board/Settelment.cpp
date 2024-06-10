#include "Settelment.hpp"
using namespace std;
namespace ariel{
  /**
   * @brief Construct a new Settlement:: Settlement object
   * Construct a new Settlement object with the given id, adjacent settlements and adjacent roads
  */
    Settlement::Settlement(size_t id, vector<size_t> adjSett, vector<size_t> adjRoads) : id(id){
            this->owner = nullptr;
            this->type = "🟫";
            this->value = 1;
            this-> adjSett = adjSett;
            this-> adjRoads = adjRoads;
        }

    // Gettersw


    /**
     * @brief Get the Value object, the value represents the number of points the settlement is worth, and the number of resources it produces
     * @return size_t 
     */
    size_t Settlement::getValue() const {
       return value;
        }
    /**
     * @brief Get the Type object, the type represents the type of the settlement
     * @return std::string the type of the settlement, either "🟫" for none, "🏘" for settlement or "🏙️" for city
     */
    std::string Settlement::getType() const { 
      return type; 
      }
    /**
     * @brief Get the Id object, the id represents the unique id of the settlement
     * @return size_t 
     */
    size_t Settlement::getId() const { return id; }
    /**
     * @brief Get the Owner object, the owner represents the player that owns the settlement
     * @return Player* 
     */
     Player* Settlement::getOwner() const { return owner; }

    /**
     * @brief Get the Adj Sett object, the adjSett represents the adjacent settlements to the settlement
     * @return const vector<size_t>& 
     */
    const vector<size_t> &Settlement::getAdjSett() { return adjSett; }

    /**
     * @brief Get the Adj Roads object, the adjRoads represents the adjacent roads to the settlement
     * @return const vector<size_t>& 
     */
    const vector<size_t> &Settlement::getAdjRoads() { return adjRoads; }
    // Setters
    /**
     * @brief Set the Value object, the value represents the number of points the settlement is worth, and the number of resources it produces
     * @param size_t newValue 
     */
    void Settlement::setValue(size_t newValue) { value = newValue; }

    /**
     * @brief Set the Type object, the type represents the type of the settlement
     * @param const std::string &newType 
     */
    void Settlement::setType(const std::string& newType) { type = newType; }
    
    /**
     * @brief Set the Owner object, the owner represents the player that owns the settlement
     * @param Player* newOwner 
     */
    void Settlement::setOwner(Player* newOwner) {
       owner = newOwner;
       
    }

    /**
     * @brief Convert the settlement to a string
     * @param size_t mode the mode for the string conversion, can be REGULAR, BUILD_SETTLEMENT, BUILD_CITY or BUILD_ROAD for different purposes
     * @param Player* builder the player that is building the settlement
     * @return string 
     * @throw invalid_argument if the mode is not valid
     */
    string Settlement::toString(size_t mode, Player* builder){
        switch (mode)
        {
        case Consts::REGULAR:
            return this->getType();
            break;
        case Consts::BUILD_SETTLEMENT:
           if(this->getOwner() != nullptr){
            return this->getType();
           }
            return to_string(this->getId());
            break;
        case Consts::BUILD_CITY:
            if(this->getOwner() == builder){
                return to_string(this->getId());
            }
            return this->getType();
            break;
        case Consts::BUILD_ROAD:
            return this->getType();
            break;
        default:
           throw invalid_argument("Invalid mode, not a valid mode.");
        }
    }
}