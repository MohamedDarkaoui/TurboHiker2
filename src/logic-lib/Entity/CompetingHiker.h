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
    /**
     * Simple constructor
     * @param lane: the initial lane where the Hiker is located
     * @param size: the size of the hiker
     * @param lanePositionsX: all possible lane x-coordinates
     * @param speed: the initial speed of the hiker
     * @param speedUpFactor: the factor by which the speed can change
     */
    CompetingHiker(unsigned int lane, std::pair<double, double> &size, std::vector<double>& lanePositionsX, double speed,
                   double speedUpFactor);

    /**
     * default copy constructor
     */
    CompetingHiker(const CompetingHiker&) = default;

    /**
     * default destructor
     */
    ~CompetingHiker() override = default;

    /**
     * updates the position, movement, acceleration, speed, etc. of the hiker
     */
    void update() override;

    /**
     * increases the speed of the Hiker, this function is used to move the hiker up
     */
    void speedUp() final;

    /**
    * decreases the speed of the Hiker, this function is used to move the hiker down
    */
    void slowDown() final;

    /**
     * increases the speed of the Hiker, this function is used to move the hiker faster
     */
    void runAtTurboSpeed();

    /**
     * decreases the speed of the Hiker, this function is used to stop moving the hiker at fast speed
     */
    void stopRunningAtTurboSpeed();

    /**
     * moves the Hiker left
     */
    virtual void moveLeft();

    /**
     * moves the Hiker right
     */
    virtual void moveRight();

    /**
     * checks if the hiker is colliding
     * @return true if the hiker is colliding, false if not
     */
    bool isColliding() const;

    /**
     * changes the colliding status of the hiker to true
     */
    virtual void collide();

    /**
     * changes the colliding status to false
     */
    void stopColliding();

    /**
     * boost the speed of the hiker for a given duration
     * @param duration: the duration of the speed boost, in frames
     */
    void speedBoost(unsigned int duration);

    /**
     * Stops the speed boost
     */
    void stopSpeedBoost();

    /**
     * Checks whether the hiker is receiving bonus speed
     * @return true if the hiker has bonus speed, else false
     */
    bool isBonusSpeed() const;

    /**
     * Simple getter of the score
     * @return the score of the hiker
     */
    const std::shared_ptr<Score> &getScore() const;

    /**
     * Pushes an active reward into the queue of rewards
     * @param reward: the to-be-pushed reward
     */
    void pushActiveReward(std::pair<bool,double> reward);

    /**
     * Simple getter of the rewards queue
     * @return the queue of the rewards
     */
    const std::deque<std::pair<bool, double>> &getRewards() const;

    /**
     * Changes the state of using_reward to true
     */
    void useActiveReward();

    /**
     * Simple getter of using_active_reward
     * @return using_active_reward
     */
    bool isUsingActiveReward() const;

    /**
     * pops the first reward from the queue
     * @return the first reward
     */
    std::pair<bool,double> getFirstReward();

    /**
     * Simple setter of using_active_reward
     * @param usingActiveReward: the new state of using_active_reward
     */
    void setUsingActiveReward(bool usingActiveReward);

    /**
     * checks if the rewards queue is empty
     * @return true if empty, false otherwise
     */
    bool rewardsEmpty();
};
}

#endif //TURBOHIKER_COMPETINGHIKER_H
