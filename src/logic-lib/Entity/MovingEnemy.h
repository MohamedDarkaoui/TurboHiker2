#ifndef TURBOHIKER_MOVINGENEMY_H
#define TURBOHIKER_MOVINGENEMY_H

#include "Enemy.h"

namespace TurboHiker{

class MovingEnemy : public Enemy {
public:
    /**
     * Simple constructor
     * @param lane: the initial lane where the Hiker is located
     * @param size: the size of the hiker
     * @param lanePositionsX: all possible lane x-coordinates
     * @param speed: the initial speed of the hiker
     * @param speedUpFactor: the factor by which the speed can change
     */
    MovingEnemy(unsigned int lane, std::pair<double, double> &size,
                std::vector<double> &lanePositionsX, double speed, double speedUpFactor);

    /**
     * default destructor
     */
    ~MovingEnemy() override = default;

    /**
     * reacts to yelling
     */
    void gotYelledAt() override;

    /**
     * updates the Hiker
     */
    void update() override;
};
}

#endif //TURBOHIKER_MOVINGENEMY_H
