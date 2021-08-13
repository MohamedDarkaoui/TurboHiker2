#include "Player.h"

#include <utility>

Player::Player(unsigned int lane, std::pair<double, double> &size, std::vector<double>& lanePositionsX, double speed,
               double speedUpFactor, double yellingRange) :
               CompetingHiker(lane, size, lanePositionsX, speed, speedUpFactor), yelling_range(yellingRange) {
    yelling = false;
    yell_duration = 0;
}

void Player::yell() {
    if (yell_duration == 0){
        yelling = true;
        yell_duration = 1;
    }
}

bool Player::isYelling() const {
    return yelling;
}

double Player::getYellingRange() const {
    return yelling_range;
}

void Player::update() {
    if (isYelling()){
        if (yell_duration > 0)
            yell_duration--;
        else
            yelling = false;
    }
    if (getMovement() != Hiker::STANDARD){
        position.setX(0);
        position += {getLanePositionsX()[getLane()],0};
        setMovement(Hiker::STANDARD);
    }

    double speedTEMP = getSpeed();

    if (isColliding() && getSlowedFor() < getCollisionSlowDuration()){
        speedTEMP /= 3;
        setSlowedFor(getSlowedFor()+1);
    }
    else if (isColliding() && getSlowedFor() == getCollisionSlowDuration()){
        stopColliding();
        setSlowedFor(0);
    }

    if (getAcceleration() == Hiker::NONE)
        position += {0,speedTEMP};
    else if (getAcceleration() == Hiker::SPEED_UP)
        position += {0,getSpeedUpFactor()*speedTEMP};
    else
        position += {0,speedTEMP/getSpeedUpFactor()};


}