#ifndef TURBOHIKER_ENEMY_H
#define TURBOHIKER_ENEMY_H

#include "Hiker.h"

namespace TurboHiker{
class Enemy : public Hiker {

public:
    /**
     * simple constructor
     * @param lane: the initial lane where the Hiker is located
     * @param size: the size of the hiker
     * @param lanePositionsX: all possible lane x-coordinates
     * @param speed: the initial speed of the hiker
     * @param speedUpFactor: the factor by which the speed can change
     */
    Enemy(unsigned int lane, std::pair<double, double> &size, std::vector<double>& lanePositionsX, double speed,
          double speedUpFactor);

    /**
     * default destructor
     */
    ~Enemy() override = default;

    /**
     * reacts to yelling
     */
    virtual void gotYelledAt() = 0;
};
}

#endif //TURBOHIKER_ENEMY_H
