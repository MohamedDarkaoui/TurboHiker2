#include "Player.h"

#include <utility>

Player::Player(double speed, unsigned int lane) : CompetingHiker(speed, lane) {
    yelling_range = 2;
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

    if (movement != Hiker::STANDARD){
        position.setX(0);
        position += {lanePositionsX[lane],0};
        movement = Hiker::STANDARD;
    }

    double speedTEMP = speed;

    if (isColliding())
        speedTEMP /= 3;

    if (isColliding() && getSlowedFor() < getCollisionSlowDuration()){
        speedTEMP /= 3;
        setSlowedFor(getSlowedFor() + 1);
    }
    else if (isColliding() && getSlowedFor() == getCollisionSlowDuration()){
        stopColliding();
        setSlowedFor(0);
    }

    if (acceleration == Hiker::NONE)
        position += {0,speedTEMP};
    else if (acceleration == Hiker::SPEED_UP)
        position += {0,1.5*speedTEMP};
    else
        position += {0,0.75*speedTEMP};

}