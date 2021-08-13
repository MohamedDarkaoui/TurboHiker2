
#include "CompetingHiker.h"

CompetingHiker::CompetingHiker(unsigned int lane, std::pair<double, double> &size, std::vector<double>& lanePositionsX, double speed,
                               double speedUpFactor) :
        Hiker(lane,size,lanePositionsX,speed,speedUpFactor) {
    collision = false;
    collision_slow_duration = 40;
    slowed_for = 0;
}

void CompetingHiker::update() {

    if (getMovement() != Hiker::STANDARD){
        position.setX(0);
        position += {getLanePositionsX()[getLane()],0};
        setMovement(Hiker::STANDARD);
    }

    double speedTEMP = getSpeed();

    if (collision && slowed_for < collision_slow_duration){
        speedTEMP /= 3;
        slowed_for++;
    }
    else if (collision && slowed_for == collision_slow_duration){
        collision = false;
        slowed_for = 0;
    }

    if (getAcceleration() == Hiker::NONE)
        position += {0,speedTEMP};
    else if (getAcceleration() == Hiker::SPEED_UP)
        position += {0,getSpeedUpFactor()*speedTEMP};
    else
        position += {0,speedTEMP/getSpeedUpFactor()};
}

void CompetingHiker::moveLeft() {
    if (getMovement() == Hiker::STANDARD && getLane() > 0){
        setMovement(Hiker::MOVING_LEFT);
        setLane(getLane() - 1);
    }
}

void CompetingHiker::moveRight() {
    if (getMovement() == STANDARD && getLane() < 3){
        setMovement(Hiker::MOVING_RIGHT);
        setLane(getLane()+1);
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

