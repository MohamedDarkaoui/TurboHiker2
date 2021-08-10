#include <cassert>
#include "Hiker.h"


Hiker::Hiker(double speed, unsigned int lane) : speed(speed), lane(lane) {

    lanePositionsX = {-1.5,-0.5,0.5,1.5};
    position = {0,0};
    position.setY(lanePositionsX[lane]);

    assert (position.getY() != 0);
    this->acceleration = Hiker::NONE;
    this->movement = Hiker::STANDARD;
}

const Position2D &Hiker::getPosition() const {
    return position;
}

unsigned int Hiker::getLane() const {
    return lane;
}

void Hiker::update() {
    if (acceleration == Hiker::NONE)
        position += {0,speed};
    else if (acceleration == Hiker::SPEED_UP)
        position += {0,1.5*speed};
    else
        position += {0,0.75*speed};
}


void Hiker::speedUp() {
    if (acceleration == Hiker::NONE)
        acceleration = Hiker::SPEED_UP;
    else if (acceleration == Hiker::SLOW_DOWN)
        acceleration = Hiker::NONE;
}

void Hiker::slowDown() {
    if (acceleration == Hiker::NONE)
        acceleration = Hiker::SLOW_DOWN;
    else if (acceleration == Hiker::SPEED_UP)
        acceleration = Hiker::NONE;
}


Position2D Hiker::getRelativePosition(const Position2D &reference) const {
    return {position.getX(), position.getY() - reference.getY() - 2};
}















