#ifndef TURBOHIKER_SFMLGAME_H
#define TURBOHIKER_SFMLGAME_H

#include "../EventHandler/EventHandler.h"
#include "../../logic-lib/Entity/World.h"
#include "../Transformation/Transformation.h"
#include <memory>




class SFMLGame {
private:
    std::unique_ptr<sf::RenderWindow > window;

public:
    SFMLGame();

    void run();

    void handleEvent(sf::Event& event, Hiker& e);
};

#endif //TURBOHIKER_SFMLGAME_H
