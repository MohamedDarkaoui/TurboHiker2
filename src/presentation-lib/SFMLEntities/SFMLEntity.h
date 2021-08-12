#ifndef TURBOHIKER_SFMLENTITY_H
#define TURBOHIKER_SFMLENTITY_H

#include <SFML/Graphics.hpp>
#include "../../logic-lib/Entity/Entity.h"

class AbstractFactory;

class SFMLEntity {
public:
    virtual void updateVisuals() {};

    virtual const sf::RectangleShape& getShape() const {};

    virtual void handleEvents(sf::Event &event, sf::RenderWindow& window) {}

    virtual void buildWorld (const std::shared_ptr<AbstractFactory>& factory){};

};


#endif //TURBOHIKER_SFMLENTITY_H
