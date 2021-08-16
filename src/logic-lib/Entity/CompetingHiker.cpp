#include "CompetingHiker.h"

CompetingHiker::CompetingHiker(unsigned int lane, std::pair<double, double> &size, std::vector<double>& lanePositionsX, double speed,
                               double speedUpFactor) :
        Hiker(lane,size,lanePositionsX,speed,speedUpFactor) {
    collision = false;
    collision_slow_duration = 60;
    slowed_for = 0;
    turbo_fast = false;
    score = std::make_shared<Score>();
    addObserver(score);
}

void CompetingHiker::update() {

    if (getMovement() != Hiker::STANDARD){
        position.setX(0);
        position += {getLanePositionsX()[getLane()],0};
        setMovement(Hiker::STANDARD);
    }

    if (collision){
        if (slowed_for < collision_slow_duration)
            slowed_for++;
        else if (slowed_for == collision_slow_duration){
            stopColliding();
            slowed_for = 0;
        }
    }

    if (getAcceleration() == Hiker::NONE)
        position += {0,getSpeed()};
    else if (getAcceleration() == Hiker::SPEED_UP)
        position += {0,getSpeedUpFactor()*getSpeed()};
    else
        position += {0,getSpeed()/getSpeedUpFactor()};
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
    if (!collision){
        if (turbo_fast)
            stopRunningAtTurboSpeed();
        if (getAcceleration() == Hiker::SPEED_UP)
            slowDown();
        else if (getAcceleration() == Hiker::SLOW_DOWN)
            speedUp();
        setSpeed(getSpeed()/(getSpeedUpFactor()*2));
        collision = true;
    }
}

void CompetingHiker::stopColliding() {
    setSpeed(getSpeed()*getSpeedUpFactor()*2);
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

void CompetingHiker::speedUp() {
    if (!isColliding() && !turbo_fast)
        Hiker::speedUp();
}

void CompetingHiker::slowDown() {
    if (!isColliding() && !turbo_fast)
        Hiker::slowDown();
}

void CompetingHiker::runAtTurboSpeed() {
    if (turbo_fast || getAcceleration() != Hiker::NONE || isColliding())
        return;
    turbo_fast = true;
    if (getAcceleration() == Hiker::SPEED_UP)
        slowDown();
    else if (getAcceleration() == Hiker::SLOW_DOWN)
        speedUp();
    setSpeed(getSpeed()*getSpeedUpFactor()*1.5);
}

void CompetingHiker::stopRunningAtTurboSpeed() {
    if (!turbo_fast)
        return;
    turbo_fast = false;
    setSpeed(getSpeed()/(getSpeedUpFactor()*1.5));
}

const std::shared_ptr<Score> &CompetingHiker::getScore() const {
    return score;
}
