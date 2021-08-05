#include "World.h"

void World::update() {
    //update all entities
    for (auto& hiker : hikers){
        hiker->update();

        bool in_lane = false;
        double hiker_x = hiker->getPosition().getX();
        if (lane_positions.find(hiker_x) != lane_positions.end())
            in_lane = true;

        if (hiker->getMovement() != Hiker::STANDARD && in_lane)
            hiker->moveStraight();
    }

}
