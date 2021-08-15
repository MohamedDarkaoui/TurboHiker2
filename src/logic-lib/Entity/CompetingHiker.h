#ifndef TURBOHIKER_COMPETINGHIKER_H
#define TURBOHIKER_COMPETINGHIKER_H


#include "Hiker.h"

class CompetingHiker : public Hiker {
private:
    bool collision;
    int collision_slow_duration;
    int slowed_for;
    bool turbo_fast;


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

    int getSlowedFor() const;

    int getCollisionSlowDuration() const;

    void setSlowedFor(int slowedFor);
};


#endif //TURBOHIKER_COMPETINGHIKER_H
