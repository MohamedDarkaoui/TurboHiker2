#ifndef TURBOHIKER_SFMLSTATICENEMY_H
#define TURBOHIKER_SFMLSTATICENEMY_H


#include "../../logic-lib/Entity/StaticEnemy.h"
#include "SFMLEntity.h"

class SFMLStaticEnemy : public StaticEnemy, public SFMLEntity{

public:
    SFMLStaticEnemy(unsigned int lane, std::pair<double, double> &size,std::vector<double> &lanePositionsX, double speed,
                    const std::string &path_to_image);

    void updateVisuals(const Position2D &relativePos, std::pair<double, double> size) final;

    void updateAnimation() final;
};


#endif //TURBOHIKER_SFMLSTATICENEMY_H
