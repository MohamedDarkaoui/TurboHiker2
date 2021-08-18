
#ifndef TURBOHIKER_SFMLCOMPETINGHIKER_H
#define TURBOHIKER_SFMLCOMPETINGHIKER_H


#include "../../logic-lib/Entity/CompetingHiker.h"
#include "SFMLEntity.h"

namespace SFML{

class SFMLCompetingHiker : public TurboHiker::CompetingHiker, public SFMLEntity{
public:
    SFMLCompetingHiker(unsigned int lane, std::pair<double, double> &size, std::vector<double>& lanePositionsX,
                       double speed, double speedUpFactor, const std::string &path_to_image);


    void updateVisuals(const TurboHiker::Position2D &relativePos, std::pair<double, double> size) final;

    void updateAnimation() final;

};
}

#endif //TURBOHIKER_SFMLCOMPETINGHIKER_H
