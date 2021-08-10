#include "World.h"
#include <iostream>
void World::update() {
    //update all entities
    for (auto& entity : entities){
        entity->update();
    }
    handleEvents();
}

void World::addEntity(const std::shared_ptr<Entity>& entity) {
    entities.insert(entity);
}

void World::createCompetingHikers() {

    std::shared_ptr<Player> player = std::make_shared<Player>(Player({-1.5,-3}, 0.05));
    std::shared_ptr<CompetingHiker> comp = std::make_shared<CompetingHiker>(CompetingHiker({-0.5,-3}, 0.05));
    std::shared_ptr<CompetingHiker> competitor = std::make_shared<CompetingHiker>(CompetingHiker({1.5,2}, 0));
    std::shared_ptr<StaticEnemy> e = std::make_shared<StaticEnemy>(StaticEnemy({0.5,4},0.05));

    addPlayer(player);
    addCompetingHiker(comp);
    addCompetingHiker(competitor);
    addEnemyHiker(e);

    entities.insert(player);
    entities.insert(comp);
    entities.insert(competitor);
    entities.insert(e);
}











