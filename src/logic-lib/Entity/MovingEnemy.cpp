#include "MovingEnemy.h"

void MovingEnemy::gotYelledAt() {
    int random_chance = Random::getInstance().randomInt(0,1);

    if (random_chance == 0){
        acceleration = Hiker::SLOW_DOWN;
    }
}

void MovingEnemy::update() {
    if (acceleration == Hiker::SLOW_DOWN)
        position += {0, speed*slowDownFactor};
    else
        position += {0, speed};
}


