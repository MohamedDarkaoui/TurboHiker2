#ifndef TURBOHIKER_SFMLWORLD_H
#define TURBOHIKER_SFMLWORLD_H

#include "../../logic-lib/Entity/World.h"
#include "../EntityFactory/EntityFactory.h"

class SFMLWorld : public World {
private:

public:
    SFMLWorld(Position2D position, std::pair<double, double> &size);

    void buildWorld(const std::shared_ptr<AbstractFactory>& factory) override;

    const std::set<std::shared_ptr<SFMLCompetingHiker>>& getSFMLCompetingHikers() const;

    const std::shared_ptr<SFMLPlayer> &getSFMLPlayer() const;

    const std::set<std::shared_ptr<SFMLStaticEnemy>>& getSFMLStaticEnemies() const;

    const std::set<std::shared_ptr<SFMLMovingEnemy>>& getSFMLMovingEnemies() const;

    std::set<std::shared_ptr<SFMLEntity>> getSFMLEntities() const;

    const std::set<std::shared_ptr<SFMLGroundPlot>>& getSFMLGroundPlot() const;

    const std::shared_ptr<SFMLFinishLine> &getSFMLFinishLine() const;

    void update() override;

};


#endif //TURBOHIKER_SFMLWORLD_H
