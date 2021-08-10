#include "StaticEnemy.h"


void StaticEnemy::gotYelledAt() {
    int random_chance = Random::getInstance().randomInt(0,1);

    if (random_chance == 0) {
        if (position.getX() < 0)
            movement = Hiker::MOVING_LEFT;
        else
            movement = Hiker::MOVING_RIGHT;
    }

}

void StaticEnemy::update() {
    if (movement == Hiker::MOVING_RIGHT){
        position += {speed,0};
        lane = 100;
    }
    else if (movement == Hiker::MOVING_LEFT){
        position -= {speed,0};
        lane = 100;
    }
}



