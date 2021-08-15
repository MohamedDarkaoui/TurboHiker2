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
    CompetingHiker::update();
}


