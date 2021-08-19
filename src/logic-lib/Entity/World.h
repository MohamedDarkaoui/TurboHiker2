#ifndef TURBOHIKER_WORLD_H
#define TURBOHIKER_WORLD_H

#include <set>
#include "Player.h"
#include "StaticEnemy.h"
#include "MovingEnemy.h"
#include "GroundPlot.h"
#include "../Score/Score.h"
#include "FinishLine.h"
#include "PassiveItem.h"
#include "ActiveItem.h"

namespace TurboHiker{

class AbstractFactory;

class World : public Entity {

private:
    std::shared_ptr<Player> player;
    std::set<std::shared_ptr<CompetingHiker>> competing_hikers;
    std::set<std::shared_ptr<StaticEnemy>> static_enemies;
    std::set<std::shared_ptr<MovingEnemy>> moving_enemies;
    std::set<std::shared_ptr<GroundPlot>> ground;
    std::set<std::shared_ptr<PassiveItem>> passive_items;
    std::set<std::shared_ptr<ActiveItem>> active_items;
    std::shared_ptr<FinishLine> finish_line;
    std::shared_ptr<AbstractFactory> factory;

public:
    /**
     * simple constructor
     * @param position: the initial position of the 'camera'
     * @param size: the size of the world (width x height)
     * @param factory: the abstract factory that creates entities
     */
    World(Position2D position, std::pair<double, double> &size, std::shared_ptr<AbstractFactory>& factory);

    /**
     * default destructor
     */
    ~World() override = default;

    /**
     * updates the world and all its composite entities
     */
    void update() override;

    /**
     * checks for competingHiker-competingHiker collision and handles them
     */
    void handleHikerCollisions();

    /**
     * checks for competingHiker-enemy collisions and handles them
     */
    void handleHikerEnemyCollisions();

    /**
     * checks for item collecting
     */
    void handleCollectingItem();

    /**
     * handles the yelling of the player
     */
    void handleYelling();

    /**
     * handles the usage of the active collectable items
     */
    void handleRewardUsage();

    /**
     * handles all events
     */
    void handleEvents();

    /**
     * makes sure the 'camera' follows the player
     */
    void trackPlayer();

    /**
     * removes unnecessary entities from the world
     */
    void checkToDestroyEntities();

    /**
     * spawns a moving enemy in a given position
     * @param lane: the lane where the enemy will spawn
     * @param y_pos: the y-coordinate of the enemy
     * @param speedFactor: its seed-up factor
     */
    virtual void spawnMovingEnemy(unsigned int lane, double y_pos, double speedFactor);

    /**
     * spawns a static enemy in a given position
     * @param lane: the lane where the enemy will spawn
     * @param y_pos: the y-coordinate of the enemy
     * @param speedFactor: its seed-up factor
     */
    virtual void spawnStaticEnemy(unsigned int lane, double y_pos);

    /**
     * creates all the entities in the world
     */
    virtual void buildWorld();

    /**
     * simple setter of the player
     * @param p: the player
     */
    void addPlayer(const std::shared_ptr<Player>& p);

    /**
     * adds a competing hiker to the set of competing hikers
     * @param competing: the competing hiker
     */
    void addCompetingHiker(const std::shared_ptr<CompetingHiker>& competing);

    /**
     * adds a static enemy to the set of static enemies
     * @param static_enemy: the static enemy
     */
    void addStaticEnemy(const std::shared_ptr<StaticEnemy>& static_enemy);

    /**
     * adds a moving enemy to the set of moving enemies
     * @param moving_enemy: the moving enemy
     */
    void addMovingEnemy(const std::shared_ptr<MovingEnemy>& moving_enemy);

    /**
     * adds ground to the world
     * @param groundPlot: the ground plot
     */
    void addGRoundPlot(const std::shared_ptr<GroundPlot>& groundPlot);

    /**
     * adds a passive item to the set of passive items
     * @param passiveItem: the passive item
     */
    void addPassiveItem(const std::shared_ptr<PassiveItem>& passiveItem);

    /**
     * adds an active item to the set of active items
     * @param activeItem: the active item
     */
    void addActiveItem(const std::shared_ptr<ActiveItem>& activeItem);

    /**
     * simple setter of the finish line
     * @param finishLine: the finish line
     */
    void addFinishLine(const std::shared_ptr<FinishLine>& finishLine);

    /////////////   Getters  /////////////
    std::set<std::shared_ptr<Entity>> getEntities() const;
    std::set<std::shared_ptr<Enemy>> getEnemies() const;
    std::set<std::shared_ptr<CollectableItem>> getItems() const;
    const std::shared_ptr<Player>& getPlayer() const;
    const std::set<std::shared_ptr<CompetingHiker>>& getCompetingHikers() const;
    const std::set<std::shared_ptr<StaticEnemy>>& getStaticEnemies() const;
    const std::set<std::shared_ptr<MovingEnemy>>& getMovingEnemies() const;
    const std::set<std::shared_ptr<GroundPlot>>& getGround() const;
    const std::set<std::shared_ptr<PassiveItem>>& getPassiveItems() const;
    const std::set<std::shared_ptr<ActiveItem>>& getActiveItems() const;
    const std::shared_ptr<FinishLine>& getFinishLine() const;
    const std::shared_ptr<AbstractFactory>& getFactory() const;
    ///////////////////////////////////////

    /**
     * controls the competing hikers, giving them random movements
     */
    void controlCompetingHikers();

    /**
     * controls the competing hikers when they are about to collide with something, giving them a random chance to dodge
     * @param competingHiker: the controlled competing hiker
     */
    void controlHikerAtCollision(const std::shared_ptr<CompetingHiker>& competingHiker);

};
}
#endif //TURBOHIKER_WORLD_H
