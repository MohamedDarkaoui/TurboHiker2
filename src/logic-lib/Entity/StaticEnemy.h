#ifndef TURBOHIKER_STATICENEMY_H
#define TURBOHIKER_STATICENEMY_H

#include "Enemy.h"
#include "Hiker.h"

namespace TurboHiker{

class StaticEnemy : public Enemy {

public:
    /**
     * Simple constructor
     * @param lane: the initial lane where the Hiker is located
     * @param size: the size of the hiker
     * @param lanePositionsX: all possible lane x-coordinates
     * @param speed: the initial speed of the hiker
     */
    explicit StaticEnemy(unsigned int lane, std::pair<double, double> &size,
                         std::vector<double> &lanePositionsX, double speed);

    /**
     * reacts to yelling
     */
    void gotYelledAt() override;

    /**
     * updates the hiker
     */
    void update() override;
};
}

#endif //TURBOHIKER_STATICENEMY_H
