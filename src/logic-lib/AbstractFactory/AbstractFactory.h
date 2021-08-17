#ifndef TURBOHIKER_ABSTRACTFACTORY_H
#define TURBOHIKER_ABSTRACTFACTORY_H


#include <fstream>
#include "../../../ini_config/ini_configuration.h"

#include "../Entity/World.h"

class SFMLPlayer;
class SFMLCompetingHiker;
class SFMLStaticEnemy;
class SFMLMovingEnemy;
class SFMLWorld;
class SFMLGroundPlot;
class SFMLFinishLine;
class SFMLPassiveItem;
class SFMLActiveItem;

class AbstractFactory  {

public:

    virtual std::shared_ptr<SFMLPlayer> createPlayer() = 0;

    virtual std::shared_ptr<SFMLStaticEnemy> createStaticEnemy(unsigned int lane, double y_pos) = 0;

    virtual std::shared_ptr<SFMLMovingEnemy> createMovingEnemy(unsigned int lane, double y_pos, double speed) = 0;

    virtual std::set<std::shared_ptr<SFMLCompetingHiker>> createCompetingHikers(unsigned int player_lane) = 0;

    virtual std::set<std::shared_ptr<SFMLStaticEnemy>> createStaticEnemies() = 0;

    virtual std::set<std::shared_ptr<SFMLMovingEnemy>> createMovingEnemies() = 0;

    virtual std::set<std::shared_ptr<SFMLGroundPlot>> createGroundPlots() = 0;

    virtual std::set<std::shared_ptr<SFMLPassiveItem>> createPassiveItem() = 0;

    virtual std::set<std::shared_ptr<SFMLActiveItem>> createActiveItems() = 0;

    virtual std::shared_ptr<SFMLFinishLine> createFinishLine() = 0;

    virtual std::shared_ptr<SFMLWorld> createWorld() = 0;

};


#endif //TURBOHIKER_ABSTRACTFACTORY_H
