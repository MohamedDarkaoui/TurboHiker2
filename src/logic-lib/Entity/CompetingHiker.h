#ifndef TURBOHIKER_COMPETINGHIKER_H
#define TURBOHIKER_COMPETINGHIKER_H


#include "Hiker.h"

class CompetingHiker : public Hiker {
private:
    bool collision;
    int collision_slow_duration;
    int slowed_for;


public:
    CompetingHiker(double speed, unsigned int lane);

    void update() override;

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
