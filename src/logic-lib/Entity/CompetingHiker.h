#ifndef TURBOHIKER_COMPETINGHIKER_H
#define TURBOHIKER_COMPETINGHIKER_H

#include <queue>
#include "Hiker.h"
#include "../Observer/Observable.h"
#include "../Score/Score.h"
#include "MovingEnemy.h"
#include "StaticEnemy.h"

namespace TurboHiker{

class ActiveItem;

class CompetingHiker : public Hiker, public Observable{
private:
    bool collision;
    int collision_slow_duration;
    int slowed_for;
    bool turbo_fast;
    std::shared_ptr<Score> score;
    std::deque<std::pair<bool,double>> rewards; // queue(<isMovingEnemy, speed>)
    bool bonus_speed = false;
    unsigned int bonus_speed_duration = 0;
    bool using_active_reward = false;


public:
    CompetingHiker(unsigned int lane, std::pair<double, double> &size, std::vector<double>& lanePositionsX, double speed,
                   double speedUpFactor);

    void update() override;

    void speedUp() final;

    void slowDown() final;

    void runAtTurboSpeed();

    void stopRunningAtTurboSpeed();

    void moveLeft();

    void moveRight();

    bool isColliding() const;

    void collide();

    void stopColliding();

    void speedBoost(unsigned int duration);

    void stopSpeedBoost();

    bool isBonusSpeed() const;

    const std::shared_ptr<Score> &getScore() const;

    void pushActiveReward(std::pair<bool,double> reward);

    const std::deque<std::pair<bool, double>> &getRewards() const;

    void useActiveReward();

    bool isUsingActiveReward() const;

    std::pair<bool,double> getFirstReward();

    void setUsingActiveReward(bool usingActiveReward);

    bool rewardsEmpty();

    int getSlowedFor() const;

    int getCollisionSlowDuration() const;

    void setSlowedFor(int slowedFor);
};
}

#endif //TURBOHIKER_COMPETINGHIKER_H
