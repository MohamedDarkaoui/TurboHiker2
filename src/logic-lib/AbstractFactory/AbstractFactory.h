#ifndef TURBOHIKER_ABSTRACTFACTORY_H
#define TURBOHIKER_ABSTRACTFACTORY_H


#include <fstream>
#include "../../../ini_config/ini_configuration.h"

#include "../Entity/World.h"

class SFMLPlayer;
class SFMLCompetingHiker;
class SFMLStaticEnemy;
class SFMLWorld;

class AbstractFactory  {

public:

    virtual std::shared_ptr<SFMLPlayer> createPlayer() = 0;

    virtual std::set<std::shared_ptr<SFMLCompetingHiker>> createCompetingHikers(unsigned int player_lane) = 0;

    virtual std::set<std::shared_ptr<SFMLStaticEnemy>> createStaticEnemies() = 0;

    virtual std::shared_ptr<SFMLWorld> createWorld() = 0;
    
};


#endif //TURBOHIKER_ABSTRACTFACTORY_H
