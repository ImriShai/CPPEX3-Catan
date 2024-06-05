#include "DevelopmentCard.hpp"
namespace ariel
{
class Monopoly : public DevelopmentCard {
public:
    // Constructor
    Monopoly();

    // Override the useCard() method
    void useCard() override;
};
}