
#include "CompetingHiker.h"

CompetingHiker::CompetingHiker(double speed, unsigned int lane) :
Hiker(speed, lane){
    collision = false;
    collision_slow_duration = 40;
    slowed_for = 0;
}

void CompetingHiker::update() {

    if (movement != Hiker::STANDARD){
        position.setX(0);
        position += {lanePositionsX[lane],0};
        movement = Hiker::STANDARD;
    }

    double speedTEMP = speed;

    if (collision && slowed_for < collision_slow_duration){
        speedTEMP /= 3;
        slowed_for++;
    }
    else if (collision && slowed_for == collision_slow_duration){
        collision = false;
        slowed_for = 0;
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

int CompetingHiker::getSlowedFor() const {
    return slowed_for;
}

int CompetingHiker::getCollisionSlowDuration() const {
    return collision_slow_duration;
}

void CompetingHiker::setSlowedFor(int slowedFor) {
    slowed_for = slowedFor;
}

