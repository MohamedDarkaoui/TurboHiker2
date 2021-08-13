#include "MovingEnemy.h"

void MovingEnemy::gotYelledAt() {
    int random_chance = Random::getInstance().randomInt(0,1);

    if (random_chance == 0){
        setAcceleration(Hiker::SLOW_DOWN);
    }
}

void MovingEnemy::update() {
    if (getAcceleration() == Hiker::SLOW_DOWN)
        position += {0, getSpeed()/getSpeedUpFactor()};
    else
        position += {0, getSpeed()};
}

MovingEnemy::MovingEnemy(unsigned int lane, std::pair<double, double> &size, std::vector<double> &lanePositionsX,
                         double speed, double speedUpFactor) :
                         Enemy(lane, size, lanePositionsX, speed, speedUpFactor){}


