#include "DevelopmentCard.hpp"
using namespace std;
namespace ariel
{
    /**
     * @brief This class represents a Monopoly card in the game
     * 
     */
    class Monopoly : public DevelopmentCard {
       public:
        Monopoly();
        void useCard(Player& player, Catan& game);
    };
}