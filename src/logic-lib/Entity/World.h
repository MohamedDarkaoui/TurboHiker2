#ifndef TURBOHIKER_WORLD_H
#define TURBOHIKER_WORLD_H

#include <set>
#include "Player.h"
#include "StaticEnemy.h"
#include "MovingEnemy.h"

class AbstractFactory;

class World  {

private:
    std::shared_ptr<Player> player;
    std::set<std::shared_ptr<CompetingHiker>> competing_hikers;
    std::set<std::shared_ptr<StaticEnemy>> static_enemies;
    std::set<std::shared_ptr<MovingEnemy>> moving_enemies;

    double top;
    double height;
    double left;
    double width;

public:
    World(double top, double height, double left, double width) : top(top), height(height), left(left), width(width) {}


    virtual void update();

    void addPlayer(const std::shared_ptr<Player>& p);

    void addCompetingHiker(const std::shared_ptr<CompetingHiker>& competing);

    void addStaticEnemy(const std::shared_ptr<StaticEnemy>& static_enemy);

    void addMovingEnemy(const std::shared_ptr<MovingEnemy>& moving_enemy);

    std::set<std::shared_ptr<Entity>> getEntities() const;

    std::set<std::shared_ptr<Enemy>> getEnemies() const;

    const std::shared_ptr<Player> &getPlayer() const;

    const std::set<std::shared_ptr<CompetingHiker>> &getCompetingHikers() const;

    const std::set<std::shared_ptr<StaticEnemy>> &getStaticEnemies() const;

    const std::set<std::shared_ptr<MovingEnemy>> &getMovingEnemies() const;

    void handleHikerCollisions();

    void handleHikerEnemyCollisions();

    void handleYelling();

    void handleEvents();

    virtual void buildWorld(const std::shared_ptr<AbstractFactory>& factory);

};

#endif //TURBOHIKER_WORLD_H
