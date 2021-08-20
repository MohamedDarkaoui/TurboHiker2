#ifndef TURBOHIKER_SFMLWORLD_H
#define TURBOHIKER_SFMLWORLD_H

#include "../../logic-lib/Entity/World.h"
#include "../EntityFactory/EntityFactory.h"

namespace SFML{

class SFMLWorld : public TurboHiker::World {
private:

public:
    /**
     * simple constructor
     * @param position: the initial position of the 'camera'
     * @param size: the size of the world (width x height)
     * @param factory: the abstract factory that creates entities
     */
    SFMLWorld(TurboHiker::Position2D position, std::pair<double, double> &size,
              std::shared_ptr<TurboHiker::AbstractFactory>& factory);

    /**
     * default destructor
     */
    ~SFMLWorld() override = default;

    /**
     * creates all the entities in the world
     */
    void buildWorld() override;

    ////////////////    getters     ////////////////
    const std::set<std::shared_ptr<SFMLCompetingHiker>>& getSFMLCompetingHikers() const;
    const std::shared_ptr<SFMLPlayer> &getSFMLPlayer() const;
    const std::set<std::shared_ptr<SFMLStaticEnemy>>& getSFMLStaticEnemies() const;
    const std::set<std::shared_ptr<SFMLMovingEnemy>>& getSFMLMovingEnemies() const;
    std::set<std::shared_ptr<SFMLEntity>> getSFMLEntities() const;
    const std::set<std::shared_ptr<SFMLGroundPlot>>& getSFMLGroundPlot() const;
    const std::set<std::shared_ptr<SFMLPassiveItem>>& getSFMLPassiveItems() const;
    const std::set<std::shared_ptr<SFMLActiveItem>>& getSFMLActiveItems() const;
    const std::shared_ptr<SFMLFinishLine> &getSFMLFinishLine() const;
    const std::set<std::shared_ptr<SFMLBomb>>& getSFMLBombs() const;
    ////////////////////////////////////////////////

    /**
     * spawns a moving enemy in a given position
     * @param lane: the lane where the enemy will spawn
     * @param y_pos: the y-coordinate of the enemy
     * @param speedFactor: its seed-up factor
     */
    void spawnMovingEnemy(unsigned int lane, double y_pos, double speedFactor) override;

    /**
     * spawns a static enemy in a given position
     * @param lane: the lane where the enemy will spawn
     * @param y_pos: the y-coordinate of the enemy
     * @param speedFactor: its seed-up factor
     */
    void spawnStaticEnemy(unsigned int lane, double y_pos) override;

    /**
     * spawns a bomb
     */
    void spawnBomb() override;

    /**
     * updates the world and all its composite entities
     */
    void update() override;

};
}

#endif //TURBOHIKER_SFMLWORLD_H
