#include "Player.h"

#include <utility>

TurboHiker::Player::Player(unsigned int lane, std::pair<double, double> &size, std::vector<double>& lanePositionsX, double speed,
               double speedUpFactor, double yellingRange) :
               CompetingHiker(lane, size, lanePositionsX, speed, speedUpFactor), yelling_range(yellingRange) {
    yelling = false;
    yell_duration = 0;
}

void TurboHiker::Player::yell() {
    if (yell_duration == 0){
        notifyObservers(ObserverEvent::YELLING);
        yelling = true;
        yell_duration = 1;
    }
}

bool TurboHiker::Player::isYelling() const {
    return yelling;
}

double TurboHiker::Player::getYellingRange() const {
    return yelling_range;
}

void TurboHiker::Player::update() {
    if(isUsingActiveReward())
        setUsingActiveReward(false);

    if (isYelling()){
        if (yell_duration > 0)
            yell_duration--;
        else
            yelling = false;
    }
    CompetingHiker::update();
}


