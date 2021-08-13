#ifndef TURBOHIKER_SFMLWORLD_H
#define TURBOHIKER_SFMLWORLD_H


#include "../../logic-lib/Entity/World.h"
#include "../EntityFactory/EntityFactory.h"

class SFMLWorld : public World {
public:
    SFMLWorld(double top, double height, double left, double width);

    void buildWorld(const std::shared_ptr<AbstractFactory>& factory) override;

    const std::set<std::shared_ptr<SFMLCompetingHiker>> &getSFMLCompetingHikers() const;

    const std::shared_ptr<SFMLPlayer> &getSFMLPlayer() const;

    const std::set<std::shared_ptr<SFMLStaticEnemy>> &getSFMLStaticEnemies() const;

    const std::set<std::shared_ptr<SFMLMovingEnemy>> &getSFMLMovingEnemies() const;

    void update() override;



};


#endif //TURBOHIKER_SFMLWORLD_H
