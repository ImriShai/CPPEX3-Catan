#include "DevelopmentCard.hpp"
using namespace std;
namespace ariel
{
    class Monopoly : public DevelopmentCard {
       public:
        Monopoly();
        void useCard(Player& player, Catan& game);
    };
}