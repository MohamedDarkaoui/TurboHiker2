#include <cassert>
#include "Hiker.h"


Hiker::Hiker(unsigned int lane, std::pair<double, double> &size, std::vector<double>& lanePositionsX, double speed,
             double speedUpFactor) : Entity(lane,size, lanePositionsX),
             speed(speed), speedUpFactor(speedUpFactor) {

    assert (position.getX() != 0);
    this->acceleration = Hiker::NONE;
    this->movement = Hiker::STANDARD;
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


void Hiker::setYposition(double y)  {
    position.setY(y);
}

Hiker::Movement Hiker::getMovement() const {
    return movement;
}

void Hiker::setMovement(Hiker::Movement movement) {
    Hiker::movement = movement;
}

Hiker::Acceleration Hiker::getAcceleration() const {
    return acceleration;
}

void Hiker::setAcceleration(Hiker::Acceleration acceleration) {
    Hiker::acceleration = acceleration;
}

double Hiker::getSpeed() const {
    return speed;
}

void Hiker::setSpeed(double speed) {
    Hiker::speed = speed;
}

double Hiker::getSpeedUpFactor() const {
    return speedUpFactor;
}















