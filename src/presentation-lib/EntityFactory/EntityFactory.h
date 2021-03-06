#ifndef TURBOHIKER_ENTITYFACTORY_H
#define TURBOHIKER_ENTITYFACTORY_H

#include "../../../ini_config/ini_configuration.h"
#include "../../logic-lib/AbstractFactory/AbstractFactory.h"
#include "../SFMLEntities/SFMLPlayer.h"
#include "../SFMLEntities/SFMLWorld.h"
#include "../SFMLEntities/SFMLCompetingHiker.h"
#include "../SFMLEntities/SFMLStaticEnemy.h"
#include "../SFMLEntities/SFMLMovingEnemy.h"
#include "../SFMLEntities/SFMLGroundPlot.h"
#include "../SFMLEntities/SFMLFinishLine.h"
#include "../SFMLEntities/SFMLPassiveItem.h"
#include "../SFMLEntities/SFMLActiveItem.h"
#include "../SFMLEntities/SFMLBomb.h"
#include <fstream>

namespace SFML {

class EntityFactory : public TurboHiker::AbstractFactory {
private:
    ini::Configuration configuration;
    std::string path;
public:
    /**
     * simple constructor
     * @param path_to_config_file: the path to the ini config file
     */
    explicit EntityFactory(const std::string& path_to_config_file);

    /**
     * default destructor
     */
    ~EntityFactory() override = default;

    /**
     * reads the size of an entity from a config file
     * @return the size of an entity
     */
    std::pair<double,double> readSize(const std::string& entityName);

    ////////////////    create a shared pointer to a new corresponding entity and return it     ////////////////

    std::shared_ptr<SFMLPlayer> createPlayer() override;

    std::shared_ptr<SFMLStaticEnemy> createStaticEnemy(unsigned int lane, double y_pos) override;

    std::shared_ptr<SFMLMovingEnemy> createMovingEnemy(unsigned int lane, double y_pos, double speed) override;

    std::set<std::shared_ptr<SFMLCompetingHiker>> createCompetingHikers(unsigned int player_lane) override;

    std::set<std::shared_ptr<SFMLStaticEnemy>> createStaticEnemies() override;

    std::set<std::shared_ptr<SFMLMovingEnemy>> createMovingEnemies() override;

    std::set<std::shared_ptr<SFMLGroundPlot>> createGroundPlots() override;

    std::set<std::shared_ptr<SFMLPassiveItem>> createPassiveItem() override;

    std::set<std::shared_ptr<SFMLActiveItem>> createActiveItems() override;

    std::shared_ptr<SFMLFinishLine> createFinishLine() override;

    std::shared_ptr<SFML::SFMLBomb> createBomb() override;

    std::shared_ptr<SFMLWorld> createWorld() override;

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
};
}

#endif //TURBOHIKER_ENTITYFACTORY_H
