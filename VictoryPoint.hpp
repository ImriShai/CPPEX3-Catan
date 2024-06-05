#include "DevelopmentCard.hpp"
namespace ariel
{
class VictoryPoint : public DevelopmentCard {
public:
    // Constructor
    VictoryPoint();

    // Override the useCard() method
    void useCard() override;
    
};
}