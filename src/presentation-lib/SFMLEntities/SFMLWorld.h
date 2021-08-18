#ifndef TURBOHIKER_SFMLWORLD_H
#define TURBOHIKER_SFMLWORLD_H

#include "../../logic-lib/Entity/World.h"
#include "../EntityFactory/EntityFactory.h"

namespace SFML{

class SFMLWorld : public TurboHiker::World {
private:

public:
    SFMLWorld(TurboHiker::Position2D position, std::pair<double, double> &size,
              std::shared_ptr<TurboHiker::AbstractFactory>& factory);

    void buildWorld() override;

    const std::set<std::shared_ptr<SFMLCompetingHiker>>& getSFMLCompetingHikers() const;

    const std::shared_ptr<SFMLPlayer> &getSFMLPlayer() const;

    const std::set<std::shared_ptr<SFMLStaticEnemy>>& getSFMLStaticEnemies() const;

    const std::set<std::shared_ptr<SFMLMovingEnemy>>& getSFMLMovingEnemies() const;

    std::set<std::shared_ptr<SFMLEntity>> getSFMLEntities() const;

    const std::set<std::shared_ptr<SFMLGroundPlot>>& getSFMLGroundPlot() const;

    const std::set<std::shared_ptr<SFMLPassiveItem>>& getSFMLPassiveItems() const;

    const std::set<std::shared_ptr<SFMLActiveItem>>& getSFMLActiveItems() const;

    const std::shared_ptr<SFMLFinishLine> &getSFMLFinishLine() const;

    void spawnMovingEnemy(unsigned int lane, double y_pos, double speedFactor) override;

    void spawnStaticEnemy(unsigned int lane, double y_pos) override;

    void update() override;

};
}

#endif //TURBOHIKER_SFMLWORLD_H
