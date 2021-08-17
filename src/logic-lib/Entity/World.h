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
    World(Position2D position, std::pair<double, double> &size, std::shared_ptr<AbstractFactory>& factory);

    void update() override;

    void handleHikerCollisions();

    void handleHikerEnemyCollisions();

    void handleCollectingItem();

    void handleYelling();

    void handleRewardUsage();

    void handleEvents();

    void trackPlayer();

    void checkToDestroyEntities();

    virtual void spawnMovingEnemy(unsigned int lane, double y_pos, double speedFactor);

    virtual void spawnStaticEnemy(unsigned int lane, double y_pos);

    virtual void buildWorld();

    void addPlayer(const std::shared_ptr<Player>& p);

    void addCompetingHiker(const std::shared_ptr<CompetingHiker>& competing);

    void addStaticEnemy(const std::shared_ptr<StaticEnemy>& static_enemy);

    void addMovingEnemy(const std::shared_ptr<MovingEnemy>& moving_enemy);

    void addGRoundPlot(const std::shared_ptr<GroundPlot>& groundPlot);

    void addPassiveItem(const std::shared_ptr<PassiveItem>& passiveItem);

    void addActiveItem(const std::shared_ptr<ActiveItem>& activeItem);

    void addFinishLine(const std::shared_ptr<FinishLine>& finishLine);

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

};

#endif //TURBOHIKER_WORLD_H
