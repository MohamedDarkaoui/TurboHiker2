#ifndef TURBOHIKER_ENEMY_H
#define TURBOHIKER_ENEMY_H

#include "Hiker.h"

class Enemy : public Hiker {

public:
    Enemy(double speed, unsigned int lane);

    /*
     * @brief:
     */
    virtual void gotYelledAt() = 0;

};



#endif //TURBOHIKER_ENEMY_H
