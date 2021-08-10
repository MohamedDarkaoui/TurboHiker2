#ifndef TURBOHIKER_MOVINGENEMY_H
#define TURBOHIKER_MOVINGENEMY_H


#include "Enemy.h"

class MovingEnemy : public Enemy {

    MovingEnemy(double speed, unsigned int lane) : Enemy(speed, lane) {}

    void gotYelledAt() override;

    void update() override;
};


#endif //TURBOHIKER_MOVINGENEMY_H
