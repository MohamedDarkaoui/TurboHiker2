#ifndef TURBOHIKER_SFMLMOVINGENEMY_H
#define TURBOHIKER_SFMLMOVINGENEMY_H


#include "../../logic-lib/Entity/MovingEnemy.h"
#include "SFMLEntity.h"

namespace SFML{

class SFMLMovingEnemy : public TurboHiker::MovingEnemy, public SFMLEntity {
public:
    SFMLMovingEnemy(unsigned int lane, std::pair<double, double> &size,
                    std::vector<double> &lanePositionsX, double speed, double speedUpFactor,
                    const std::string &path_to_image);

    void updateVisuals(const TurboHiker::Position2D &relativePos, std::pair<double, double> size) final;

    void updateAnimation() final;
};
}


#endif //TURBOHIKER_SFMLMOVINGENEMY_H
