#ifndef TURBOHIKER_ENEMY_H
#define TURBOHIKER_ENEMY_H

#include "Hiker.h"

class Enemy : public Hiker {

public:
    /*
     * @brief:
     */
    virtual void gotYelledAt() = 0;

};

#endif //TURBOHIKER_ENEMY_H
