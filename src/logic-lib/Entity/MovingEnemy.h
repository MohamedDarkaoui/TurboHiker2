#ifndef TURBOHIKER_MOVINGENEMY_H
#define TURBOHIKER_MOVINGENEMY_H


#include "Enemy.h"
#include "Hiker.h"

class MovingEnemy : public Enemy {

    void gotYelledAt() override;

    void update() override;
};


#endif //TURBOHIKER_MOVINGENEMY_H
