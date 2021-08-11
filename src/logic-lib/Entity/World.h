#ifndef TURBOHIKER_WORLD_H
#define TURBOHIKER_WORLD_H

#include <set>
#include "Player.h"
#include "Enemy.h"
#include "../AbstractFactory/AbstractFactory.h"

class World : public Entity {

private:
    //std::set<std::shared_ptr<Entity>> entities;

    std::shared_ptr<Player> player;
    std::set<std::shared_ptr<CompetingHiker>> competing_hikers;
    std::set<std::shared_ptr<Enemy>> enemies;

public:
    explicit World() = default;

    ~World() override = default;

    void update() override;

    void addPlayer(const std::shared_ptr<Player>& p);

    void addCompetingHikers(const std::set<std::shared_ptr<CompetingHiker>>& competing);

    void addEnemies(const std::set<std::shared_ptr<Enemy>>& e);

    std::set<std::shared_ptr<Entity>> getEntities();

    const std::set<std::shared_ptr<CompetingHiker>> &getCompetingHikers() const;

    const std::shared_ptr<Player> &getPlayer() const;

    const std::set<std::shared_ptr<Enemy>> &getEnemies() const;

    void handleHikerCollisions();

    void handleHikerEnemyCollisions();

    void handleYelling();

    void handleEvents();

    void createCompetingHikers();

//    virtual void buildWorld() = 0;

};

#endif //TURBOHIKER_WORLD_H
