#include "MovingEnemy.h"

void TurboHiker::MovingEnemy::gotYelledAt() {
    int random_chance = Random::getInstance().randomInt(0,1);

    if (random_chance == 0){
        setAcceleration(Hiker::SLOW_DOWN);
    }
}

void TurboHiker::MovingEnemy::update() {
    if (getAcceleration() == Hiker::SLOW_DOWN)
        position += {0, getSpeed()/getSpeedUpFactor()};
    else
        position += {0, getSpeed()};
}

TurboHiker::MovingEnemy::MovingEnemy(unsigned int lane, std::pair<double, double> &size, std::vector<double> &lanePositionsX,
                         double speed, double speedUpFactor) :
                         Enemy(lane, size, lanePositionsX, speed, speedUpFactor){}


