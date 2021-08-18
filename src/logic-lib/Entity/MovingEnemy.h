#ifndef TURBOHIKER_MOVINGENEMY_H
#define TURBOHIKER_MOVINGENEMY_H

#include "Enemy.h"

namespace TurboHiker{

class MovingEnemy : public Enemy {
public:
    MovingEnemy(unsigned int lane, std::pair<double, double> &size,
                std::vector<double> &lanePositionsX, double speed, double speedUpFactor);

    void gotYelledAt() override;

    void update() override;
};
}

#endif //TURBOHIKER_MOVINGENEMY_H
