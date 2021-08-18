#ifndef TURBOHIKER_ENEMY_H
#define TURBOHIKER_ENEMY_H

#include "Hiker.h"

namespace TurboHiker{
class Enemy : public Hiker {

public:
    Enemy(unsigned int lane, std::pair<double, double> &size, std::vector<double>& lanePositionsX, double speed,
          double speedUpFactor);

    /*
     * @brief:
     */
    virtual void gotYelledAt() = 0;

};
}

#endif //TURBOHIKER_ENEMY_H
