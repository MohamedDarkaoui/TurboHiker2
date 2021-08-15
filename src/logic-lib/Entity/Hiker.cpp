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
    position += {0,speed};
}

void Hiker::speedUp() {
    assert(speedUpFactor > 1);
    if (acceleration == Hiker::NONE){
        acceleration = Hiker::SPEED_UP;
        speed = speed*speedUpFactor;
    }
    else if (acceleration == Hiker::SLOW_DOWN){
        acceleration = Hiker::NONE;
        speed = speed*2*speedUpFactor;
    }
}

void Hiker::slowDown() {
    assert(speedUpFactor > 1);
    if (acceleration == Hiker::NONE){
        acceleration = Hiker::SLOW_DOWN;
        speed /= (2*speedUpFactor);
    }
    else if (acceleration == Hiker::SPEED_UP){
        acceleration = Hiker::NONE;
        speed /= speedUpFactor;
    }
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















