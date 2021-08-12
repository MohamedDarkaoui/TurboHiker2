#ifndef TURBOHIKER_SFMLSTATICENEMY_H
#define TURBOHIKER_SFMLSTATICENEMY_H


#include "../../logic-lib/Entity/StaticEnemy.h"
#include "SFMLEntity.h"

class SFMLStaticEnemy : public StaticEnemy, public SFMLEntity{


public:
    SFMLStaticEnemy(unsigned int lane);

    void updateVisuals() override {};

    const sf::RectangleShape&  getShape() const override;
};


#endif //TURBOHIKER_SFMLSTATICENEMY_H
