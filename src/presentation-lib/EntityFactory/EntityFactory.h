#ifndef TURBOHIKER_ENTITYFACTORY_H
#define TURBOHIKER_ENTITYFACTORY_H

#include "../../../ini_config/ini_configuration.h"
#include "../../logic-lib/AbstractFactory/AbstractFactory.h"

class EntityFactory : AbstractFactory{
private:
    ini::Configuration configuration;
public:
    explicit EntityFactory(const std::string& path);

    std::shared_ptr<Player> createPlayer() override;

    std::set<std::shared_ptr<CompetingHiker>> createCompetingHikers(unsigned int player_lane) override;

    std::set<std::shared_ptr<Enemy>> createStaticEnemies() override;

};


#endif //TURBOHIKER_ENTITYFACTORY_H
