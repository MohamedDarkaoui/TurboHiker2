#ifndef TURBOHIKER_ENTITYFACTORY_H
#define TURBOHIKER_ENTITYFACTORY_H

#include <fstream>
#include "../../../ini_config/ini_configuration.h"
#include "../Entity/Entity.h"
#include "../Entity/World.h"


class EntityFactory {
private:
    ini::Configuration configuration;
public:
    explicit EntityFactory(const std::string& path);

    std::shared_ptr<Player> createPlayer();

    std::vector<std::shared_ptr<CompetingHiker>> createCompetingHikers(unsigned int player_lane);
    
};


#endif //TURBOHIKER_ENTITYFACTORY_H
