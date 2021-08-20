#include "CompetingHiker.h"

TurboHiker::CompetingHiker::CompetingHiker(unsigned int lane, std::pair<double, double>& size,
                                           std::vector<double>& lanePositionsX, double speed, double speedUpFactor)
    : Hiker(lane, size, lanePositionsX, speed, speedUpFactor)
{
        collision = false;
        collision_slow_duration = 60;
        slowed_for = 0;
        turbo_fast = false;
        score = std::make_shared<Score>();
        addObserver(score);
}

void TurboHiker::CompetingHiker::update()
{
        if (getMovement() != Hiker::STANDARD) {
                position.setX(0);
                position += {getLanePositionsX()[getLane()], 0};
                setMovement(Hiker::STANDARD);
        }
        if (collision) {
                if (slowed_for < collision_slow_duration)
                        slowed_for++;
                else if (slowed_for == collision_slow_duration) {
                        stopColliding();
                        slowed_for = 0;
                }
        }

        position += {0, getSpeed()};

        if (bonus_speed) {
                if (bonus_speed_duration > 0)
                        bonus_speed_duration--;
                else
                        stopSpeedBoost();
        }
}

void TurboHiker::CompetingHiker::moveLeft()
{
        if (getMovement() == Hiker::STANDARD && getLane() > 0) {
                setMovement(Hiker::MOVING_LEFT);
                setLane(getLane() - 1);
        }
}

void TurboHiker::CompetingHiker::moveRight()
{
        if (getMovement() == STANDARD && getLane() < 3) {
                setMovement(Hiker::MOVING_RIGHT);
                setLane(getLane() + 1);
        }
}

void TurboHiker::CompetingHiker::collide()
{
        if (!collision and !bonus_speed) {
                if (turbo_fast)
                        stopRunningAtTurboSpeed();
                if (getAcceleration() == Hiker::SPEED_UP)
                        slowDown();
                else if (getAcceleration() == Hiker::SLOW_DOWN)
                        speedUp();
                setSpeed(getSpeed() / (getSpeedUpFactor() * 2));
                collision = true;
        }
}

void TurboHiker::CompetingHiker::stopColliding()
{
        setSpeed(getSpeed() * getSpeedUpFactor() * 2);
        collision = false;
}

bool TurboHiker::CompetingHiker::isColliding() const { return collision; }

void TurboHiker::CompetingHiker::speedUp()
{
        if (!isColliding() && !turbo_fast && !bonus_speed)
                Hiker::speedUp();
}

void TurboHiker::CompetingHiker::slowDown()
{
        if (!isColliding() && !turbo_fast && !bonus_speed)
                Hiker::slowDown();
}

void TurboHiker::CompetingHiker::runAtTurboSpeed()
{
        if (turbo_fast || getAcceleration() != Hiker::NONE || isColliding() || bonus_speed)
                return;
        turbo_fast = true;
        if (getAcceleration() == Hiker::SPEED_UP)
                slowDown();
        else if (getAcceleration() == Hiker::SLOW_DOWN)
                speedUp();
        setSpeed(getSpeed() * getSpeedUpFactor() * 1.5);
}

void TurboHiker::CompetingHiker::stopRunningAtTurboSpeed()
{
        if (!turbo_fast)
                return;
        turbo_fast = false;
        setSpeed(getSpeed() / (getSpeedUpFactor() * 1.5));
}

const std::shared_ptr<TurboHiker::Score>& TurboHiker::CompetingHiker::getScore() const { return score; }

void TurboHiker::CompetingHiker::speedBoost(unsigned int duration)
{
        if (bonus_speed)
                return;
        if (getAcceleration() == Hiker::SPEED_UP)
                slowDown();
        else if (getAcceleration() == Hiker::SLOW_DOWN)
                speedUp();
        if (turbo_fast)
                stopRunningAtTurboSpeed();

        bonus_speed_duration = duration;
        bonus_speed = true;
        setSpeed(getSpeed() * (getSpeedUpFactor() * 4));
}

void TurboHiker::CompetingHiker::stopSpeedBoost()
{
        if (!bonus_speed || bonus_speed_duration > 0)
                return;
        bonus_speed = false;
        bonus_speed_duration = 0;
        setSpeed(getSpeed() / ((getSpeedUpFactor() * 4)));
}

void TurboHiker::CompetingHiker::pushActiveReward(std::pair<bool, double> reward) { rewards.push_back(reward); }

std::pair<bool, double> TurboHiker::CompetingHiker::getFirstReward()
{
        std::pair<bool, double> reward = rewards.front();
        rewards.pop_front();
        return reward;
}

void TurboHiker::CompetingHiker::useActiveReward() { using_active_reward = true; }

bool TurboHiker::CompetingHiker::isUsingActiveReward() const { return using_active_reward; }

bool TurboHiker::CompetingHiker::rewardsEmpty() { return rewards.empty(); }

bool TurboHiker::CompetingHiker::isBonusSpeed() const { return bonus_speed; }

const std::deque<std::pair<bool, double>>& TurboHiker::CompetingHiker::getRewards() const { return rewards; }

void TurboHiker::CompetingHiker::setUsingActiveReward(bool usingActiveReward)
{
        using_active_reward = usingActiveReward;
}
