#include "StaticEnemy.h"


void StaticEnemy::gotYelledAt() {
    int random_chance = Random::getInstance().randomInt(0,2);

    if (random_chance == 0) {
        if (position.getX() < 0)
            movement = Hiker::MOVING_LEFT;
        else
            movement = Hiker::MOVING_RIGHT;
    }

}

void StaticEnemy::update() {
    if (movement == Hiker::MOVING_RIGHT){
        position += {0.5,0};
        lane = 100;
    }
    else if (movement == Hiker::MOVING_LEFT){
        position -= {0.5,0};
        lane = 100;
    }
}



