#ifndef TURBOHIKER_ENTITYFACTORY_H
#define TURBOHIKER_ENTITYFACTORY_H

#include "../../../ini_config/ini_configuration.h"
#include "../../logic-lib/AbstractFactory/AbstractFactory.h"
#include "../SFMLEntities/SFMLPlayer.h"
#include "../SFMLEntities/SFMLWorld.h"
#include "../SFMLEntities/SFMLCompetingHiker.h"
#include "../SFMLEntities/SFMLStaticEnemy.h"

class EntityFactory : public AbstractFactory {
private:
    ini::Configuration configuration;
public:
    explicit EntityFactory(const std::string& path_to_config_file);

    std::shared_ptr<SFMLPlayer> createPlayer() override;

    std::set<std::shared_ptr<SFMLCompetingHiker>> createCompetingHikers(unsigned int player_lane) override;

    std::set<std::shared_ptr<SFMLStaticEnemy>> createStaticEnemies() override;

    std::shared_ptr<SFMLWorld> createWorld() override;
};


#endif //TURBOHIKER_ENTITYFACTORY_H
