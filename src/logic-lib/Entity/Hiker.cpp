#include <cassert>
#include "Hiker.h"


Hiker::Hiker(Position2D position, double speed, std::vector<double>& lanePositionsX) :
        position(position), speed(speed), lanePositionsX(lanePositionsX) {

    // find out which lane
    for (unsigned int i = 0; i < lanePositionsX.size(); i++){
        if (position.getX() == lanePositionsX[i])
            this->lane = i;
    }

    assert (lane < 5 and lane >= 0);

    // default values
    this->movement = Hiker::STANDARD;
    this->acceleration = Hiker::NONE;
}

const Position2D &Hiker::getPosition() const {
    return position;
}

Hiker::Movement Hiker::getMovement() const {
    return movement;
}

unsigned int Hiker::getLane() const {
    return lane;
}


void Hiker::update() {
//    if (movement == Hiker::STANDARD) {
//        if (acceleration == Hiker::NONE)
//            position += {0,speed};
//        else if (acceleration == Hiker::SPEED_UP)
//            position += {0,speed*2};
//        else
//            position += {0,speed/2};
//    } else if (movement == Hiker::MOVING_RIGHT) {
//        if (acceleration == Hiker::NONE)
//            position += {speed/sqrt(2),speed/sqrt(2)};  //pythagoras
//        else if (acceleration == Hiker::SPEED_UP)
//            position += {2*speed/sqrt(2),2*speed/sqrt(2)};
//        else
//            position += {speed/(2*sqrt(2)),speed/(2*sqrt(2))};
//    } else if (movement == Hiker::MOVING_LEFT) {
//        if (acceleration == Hiker::NONE)
//            position += {-speed/sqrt(2),speed/sqrt(2)};
//        else if (acceleration == Hiker::SPEED_UP)
//            position += {-2*speed/sqrt(2),2*speed/sqrt(2)};
//        else
//            position += {-speed/(2*sqrt(2)),speed/(2*sqrt(2))};
//    }

    if (movement != Hiker::STANDARD){
        position.setX(0);
        position += {lanePositionsX[lane],0};
        moveStraight();
    }

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

void Hiker::normalSpeed() {
    acceleration = Hiker::Acceleration::NONE;
}

void Hiker::moveLeft() {
    if (Hiker::movement == Hiker::STANDARD && lane > 0){
        movement = Hiker::MOVING_LEFT;
        lane --;
    }
}

void Hiker::moveRight() {
    if (Hiker::movement == STANDARD && lane < 3){
        movement = Hiker::MOVING_RIGHT;
        lane++;
    }
}

void Hiker::moveStraight() {
    movement = Hiker::STANDARD;
}

Position2D Hiker::getRelativePosition(const Position2D &reference) const {
    return {position.getX(), position.getY() - reference.getY() - 2};
}













