#include "World.h"
#include <iostream>
void World::update() {
    //update all entities
    for (auto& entity : entities){
        entity->update();
    }
}

void World::addEntity(const std::shared_ptr<Entity>& entity) {
    entities.insert(entity);
}






