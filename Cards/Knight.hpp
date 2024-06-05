#include "DevelopmentCard.hpp"
using namespace std;
namespace ariel
{
    class Knight : public DevelopmentCard {
       public:
        Knight();
        void useCard(ariel::Player&,Catan&) override;
    };
}