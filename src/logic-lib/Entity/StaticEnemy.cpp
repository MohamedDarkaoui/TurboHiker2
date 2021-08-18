#include "StaticEnemy.h"

TurboHiker::StaticEnemy::StaticEnemy(unsigned int lane, std::pair<double, double> &size,
                         std::vector<double> &lanePositionsX, double speed) :
                         Enemy(lane, size, lanePositionsX, speed,0) {}

void TurboHiker::StaticEnemy::gotYelledAt() {
    int random_chance = Random::getInstance().randomInt(0,2);

    if (random_chance == 0) {
        if (position.getX() < 0)
            setMovement(Hiker::MOVING_LEFT);
        else
            setMovement(Hiker::MOVING_RIGHT);
    }

}

void TurboHiker::StaticEnemy::update() {
    if (getMovement() == Hiker::MOVING_RIGHT){
        position += {getSpeed(),0};
        setLane(100);
    }
    else if (getMovement() == Hiker::MOVING_LEFT){
        position -= {getSpeed(),0};
        setLane(100);
    }
}





