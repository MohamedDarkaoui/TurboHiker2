#ifndef TURBOHIKER_ABSTRACTFACTORY_H
#define TURBOHIKER_ABSTRACTFACTORY_H

#include <fstream>
#include "../../../ini_config/ini_configuration.h"
#include "../Entity/World.h"
#include "../Entity/Player.h"
#include "../Entity/StaticEnemy.h"
#include "../Entity/MovingEnemy.h"


class AbstractFactory {

public:

    virtual std::shared_ptr<Player> createPlayer() = 0;

    virtual std::set<std::shared_ptr<CompetingHiker>> createCompetingHikers(unsigned int player_lane) = 0;

    virtual std::set<std::shared_ptr<Enemy>> createStaticEnemies () = 0;
    
};


#endif //TURBOHIKER_ABSTRACTFACTORY_H
