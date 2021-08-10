
#include "CompetingHiker.h"

CompetingHiker::CompetingHiker(double speed, unsigned int lane) :
Hiker(speed, lane){
    collision = false;
}

void CompetingHiker::update() {

    if (movement != Hiker::STANDARD){
        position.setX(0);
        position += {lanePositionsX[lane],0};
        movement = Hiker::STANDARD;
    }

    double speedTEMP = speed;

    if (collision){
        speedTEMP /= 3;
    }

    if (acceleration == Hiker::NONE)
        position += {0,speedTEMP};
    else if (acceleration == Hiker::SPEED_UP)
        position += {0,1.5*speedTEMP};
    else
        position += {0,0.75*speedTEMP};
}

void CompetingHiker::moveLeft() {
    if (Hiker::movement == Hiker::STANDARD && lane > 0){
        movement = Hiker::MOVING_LEFT;
        lane --;
    }
}

void CompetingHiker::moveRight() {
    if (Hiker::movement == STANDARD && lane < 3){
        movement = Hiker::MOVING_RIGHT;
        lane++;
    }
}

void CompetingHiker::collide() {
    collision = true;
}

void CompetingHiker::stopColliding() {
    collision = false;
}

bool CompetingHiker::isColliding() const {
    return collision;
}

