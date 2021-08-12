#ifndef TURBOHIKER_WORLD_H
#define TURBOHIKER_WORLD_H

#include <set>
#include "Player.h"
#include "StaticEnemy.h"
#include "MovingEnemy.h"

class AbstractFactory;

class World : public Entity {

private:
    std::shared_ptr<Player> player;
    std::set<std::shared_ptr<CompetingHiker>> competing_hikers;
    std::set<std::shared_ptr<Enemy>> enemies;

    double top;
    double height;
    double left;
    double width;

public:
    World(double top, double height, double left, double width) : top(top), height(height), left(left), width(width) {}

    ~World() override = default;

    void update() override;

    void addPlayer(const std::shared_ptr<Player>& p);

    void addCompetingHiker(const std::shared_ptr<CompetingHiker>& competing);

    void addEnemy(const std::shared_ptr<Enemy>& e);

    std::set<std::shared_ptr<Entity>> getEntities();

    const std::set<std::shared_ptr<CompetingHiker>> &getCompetingHikers() const;

    const std::shared_ptr<Player> &getPlayer() const;

    const std::set<std::shared_ptr<Enemy>> &getEnemies() const;

    void handleHikerCollisions();

    void handleHikerEnemyCollisions();

    void handleYelling();

    void handleEvents();

    virtual void buildWorld(const std::shared_ptr<AbstractFactory>& factory);

};

#endif //TURBOHIKER_WORLD_H
