#ifndef TURBOHIKER_ABSTRACTFACTORY_H
#define TURBOHIKER_ABSTRACTFACTORY_H

#include <memory>
#include <set>

namespace SFML {
    class SFMLPlayer;
    class SFMLCompetingHiker;
    class SFMLStaticEnemy;
    class SFMLMovingEnemy;
    class SFMLWorld;
    class SFMLGroundPlot;
    class SFMLFinishLine;
    class SFMLPassiveItem;
    class SFMLActiveItem;
}

namespace TurboHiker{
class AbstractFactory  {

public:

    /**
     * default destructor
     */
    virtual ~AbstractFactory() = default;

    /////////// creates the corresponding entity and returns it ///////////

    virtual std::shared_ptr<SFML::SFMLPlayer> createPlayer() = 0;

    virtual std::shared_ptr<SFML::SFMLStaticEnemy> createStaticEnemy(unsigned int lane, double y_pos) = 0;

    virtual std::shared_ptr<SFML::SFMLMovingEnemy> createMovingEnemy(unsigned int lane, double y_pos, double speed) = 0;

    virtual std::set<std::shared_ptr<SFML::SFMLCompetingHiker>> createCompetingHikers(unsigned int player_lane) = 0;

    virtual std::set<std::shared_ptr<SFML::SFMLStaticEnemy>> createStaticEnemies() = 0;

    virtual std::set<std::shared_ptr<SFML::SFMLMovingEnemy>> createMovingEnemies() = 0;

    virtual std::set<std::shared_ptr<SFML::SFMLGroundPlot>> createGroundPlots() = 0;

    virtual std::set<std::shared_ptr<SFML::SFMLPassiveItem>> createPassiveItem() = 0;

    virtual std::set<std::shared_ptr<SFML::SFMLActiveItem>> createActiveItems() = 0;

    virtual std::shared_ptr<SFML::SFMLFinishLine> createFinishLine() = 0;

    virtual std::shared_ptr<SFML::SFMLWorld> createWorld() = 0;

    ///////////////////////////////////////////////////////////////////////////
};
}

#endif //TURBOHIKER_ABSTRACTFACTORY_H
