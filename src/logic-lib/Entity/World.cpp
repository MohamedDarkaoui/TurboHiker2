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
    std::shared_ptr<CompetingHiker> player = std::make_shared<CompetingHiker>(CompetingHiker({-1.5,-3}, 0.05));
    std::shared_ptr<CompetingHiker> competitor = std::make_shared<CompetingHiker>(CompetingHiker({1.5,2}, 0));
    addCompetingHiker(player);
    addCompetingHiker(competitor);
    entities.insert(player);
    entities.insert(competitor);
}











