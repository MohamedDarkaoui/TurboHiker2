#ifndef TURBOHIKER_SFMLGAME_H
#define TURBOHIKER_SFMLGAME_H

#include <SFML/Graphics.hpp>
#include "../../logic-lib/Entity/World.h"
#include "../Transformation/Transformation.h"
#include "../../logic-lib/Entity/CompetingHiker.h"
#include "../../logic-lib/Clock/Clock.h"
#include "../EntityFactory/EntityFactory.h"
#include <memory>
#include "../SFMLEntities/SFMLPlayer.h"



class SFMLGame {
private:
    std::unique_ptr<sf::RenderWindow > window;

public:
    SFMLGame();

    void run();

    void handleEvent(sf::Event& event, Player& e);
};

#endif //TURBOHIKER_SFMLGAME_H
