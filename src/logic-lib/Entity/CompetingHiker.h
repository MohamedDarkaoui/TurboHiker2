#ifndef TURBOHIKER_COMPETINGHIKER_H
#define TURBOHIKER_COMPETINGHIKER_H


#include "Hiker.h"
#include "../Observer/Observable.h"
#include "../Score/Score.h"

class CompetingHiker : public Hiker, public Observable{
private:
    bool collision;
    int collision_slow_duration;
    int slowed_for;
    bool turbo_fast;
    std::shared_ptr<Score> score;

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

    const std::shared_ptr<Score> &getScore() const;

    int getSlowedFor() const;

    int getCollisionSlowDuration() const;

    void setSlowedFor(int slowedFor);
};


#endif //TURBOHIKER_COMPETINGHIKER_H
