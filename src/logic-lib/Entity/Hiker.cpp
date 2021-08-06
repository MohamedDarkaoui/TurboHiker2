#include "Hiker.h"

Hiker::Hiker(Position2D position, int lane, double speed, bool sprinting, Hiker::Movement movement,
                         Hiker::Acceleration acceleration) :
                         position(position),
                         lane(lane),
                         speed(speed),
                         sprinting(sprinting),
                         movement(movement),
                         acceleration(acceleration) {}


const Position2D &Hiker::getPosition() const {
    return position;
}

Hiker::Movement Hiker::getMovement() const {
    return movement;
}

int Hiker::getLane() const {
    return lane;
}

void Hiker::setPosition(const Position2D &position) {
    Hiker::position = position;
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

    if (acceleration == Hiker::NONE)
        position += {0,speed};
    else if (acceleration == Hiker::SPEED_UP)
        position += {0,1.5*speed};
    else
        position += {0,0.75*speed};

}

void Hiker::sprint() {
    sprinting = true;
}

void Hiker::stopSprinting() {
    sprinting = false;
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
    if (Hiker::movement == STANDARD && lane > 0){
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











