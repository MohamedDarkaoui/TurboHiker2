
#ifndef TURBOHIKER_SFMLCOMPETINGHIKER_H
#define TURBOHIKER_SFMLCOMPETINGHIKER_H


#include "../../logic-lib/Entity/CompetingHiker.h"
#include "SFMLEntity.h"

class SFMLCompetingHiker : public CompetingHiker, public SFMLEntity{
public:
    SFMLCompetingHiker(double speed, unsigned int lane);

    void updateVisuals() override {};

    const sf::RectangleShape&  getShape() const override;
};


#endif //TURBOHIKER_SFMLCOMPETINGHIKER_H
