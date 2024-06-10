#include "DevelopmentCard.hpp"
using namespace std;
namespace ariel
{
    /**
     * @brief This class represents a Knight card in the game
     * 
     */
    class Knight : public DevelopmentCard {
       public:
        Knight();
        void useCard(ariel::Player&,Catan&) override;
    };
}