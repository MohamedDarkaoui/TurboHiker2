#ifndef TURBOHIKER_WORLD_H
#define TURBOHIKER_WORLD_H

#include <set>
#include "Player.h"
#include "StaticEnemy.h"
#include "MovingEnemy.h"
#include "GroundPlot.h"

class AbstractFactory;

class World : public Entity {

private:
    std::shared_ptr<Player> player;
    std::set<std::shared_ptr<CompetingHiker>> competing_hikers;
    std::set<std::shared_ptr<StaticEnemy>> static_enemies;
    std::set<std::shared_ptr<MovingEnemy>> moving_enemies;
    std::set<std::shared_ptr<GroundPlot>> ground;


public:
    World(Position2D position, std::pair<double, double> &size);

    void update() override;

    void handleHikerCollisions();

    void handleHikerEnemyCollisions();

    void handleYelling();

    void handleEvents();

    void trackPlayer();

    virtual void buildWorld(const std::shared_ptr<AbstractFactory>& factory);

    void addPlayer(const std::shared_ptr<Player>& p);

    void addCompetingHiker(const std::shared_ptr<CompetingHiker>& competing);

    void addStaticEnemy(const std::shared_ptr<StaticEnemy>& static_enemy);

    void addMovingEnemy(const std::shared_ptr<MovingEnemy>& moving_enemy);

    void addGRoundPlot(const std::shared_ptr<GroundPlot>& groundPlot);

    std::set<std::shared_ptr<Entity>> getEntities() const;

    std::set<std::shared_ptr<Enemy>> getEnemies() const;

    const std::shared_ptr<Player>& getPlayer() const;

    const std::set<std::shared_ptr<CompetingHiker>>& getCompetingHikers() const;

    const std::set<std::shared_ptr<StaticEnemy>>& getStaticEnemies() const;

    const std::set<std::shared_ptr<MovingEnemy>>& getMovingEnemies() const;

    const std::set<std::shared_ptr<GroundPlot>>& getGround() const;

};

#endif //TURBOHIKER_WORLD_H
