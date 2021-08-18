#ifndef TURBOHIKER_STATICENEMY_H
#define TURBOHIKER_STATICENEMY_H

#include "Enemy.h"
#include "Hiker.h"

namespace TurboHiker{

class StaticEnemy : public Enemy {

public:
    explicit StaticEnemy(unsigned int lane, std::pair<double, double> &size,
                         std::vector<double> &lanePositionsX, double speed);

    void gotYelledAt() override;

    void update() override;
};
}

#endif //TURBOHIKER_STATICENEMY_H
