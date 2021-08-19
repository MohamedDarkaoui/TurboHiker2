#ifndef TURBOHIKER_SFMLGAME_H
#define TURBOHIKER_SFMLGAME_H

#include <SFML/Graphics.hpp>
#include "../../logic-lib/Entity/World.h"
#include "../Transformation/Transformation.h"
#include "../../logic-lib/Entity/CompetingHiker.h"
#include "../../logic-lib/Clock/Clock.h"
#include "../EntityFactory/EntityFactory.h"
#include "../SFMLEntities/SFMLGroundPlot.h"
#include <memory>
#include "../SFMLEntities/SFMLPlayer.h"

namespace SFML{

class SFMLGame {
private:
    std::unique_ptr<sf::RenderWindow > window;

public:
    SFMLGame();

    void run(const std::string& config_path);

    void displayScoreScreen(const std::set<std::shared_ptr<TurboHiker::CompetingHiker>>& competingHikers,
                            const std::shared_ptr<TurboHiker::Player>& player, const sf::Font& font);
};
}
#endif //TURBOHIKER_SFMLGAME_H
