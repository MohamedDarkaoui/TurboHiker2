#ifndef TURBOHIKER_STATICENEMY_H
#define TURBOHIKER_STATICENEMY_H

#include "Enemy.h"
#include "Hiker.h"

class StaticEnemy : public Enemy {

public:
    explicit StaticEnemy(unsigned int lane) : Enemy(0,lane) {}

    void gotYelledAt() override;

    void update() override;
};

#endif //TURBOHIKER_STATICENEMY_H
