#include "World.h"
#include <iostream>
void World::update() {
    //update all entities
    for (auto& hiker : hikers){
        hiker->update();

        double hiker_y = hiker->getPosition().getY();
        int target_lane = hiker->getLane();


        if (hiker->getMovement() != Hiker::STANDARD){
            hiker->setPosition({lane_positions[target_lane],hiker_y});
            hiker->moveStraight();
        }
    }
}

void World::addHiker(const std::shared_ptr<Hiker>& hiker) {
    hikers.insert(hiker);
}





