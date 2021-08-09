#ifndef TURBOHIKER_COMPETINGHIKER_H
#define TURBOHIKER_COMPETINGHIKER_H


#include "Hiker.h"

class CompetingHiker : public Hiker {
private:
    bool collision;


public:
    CompetingHiker(Position2D position, double speed);

    void update() override;

    void moveLeft();

    void moveRight();

    void collide();

    void stopColliding();

};


#endif //TURBOHIKER_COMPETINGHIKER_H
