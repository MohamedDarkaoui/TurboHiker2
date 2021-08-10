#ifndef TURBOHIKER_COMPETINGHIKER_H
#define TURBOHIKER_COMPETINGHIKER_H


#include "Hiker.h"

class CompetingHiker : public Hiker {
private:
    bool collision;


public:
    CompetingHiker(double speed, unsigned int lane);

    void update() override;

    void moveLeft();

    void moveRight();

    bool isColliding() const;

    void collide();

    void stopColliding();

};


#endif //TURBOHIKER_COMPETINGHIKER_H
