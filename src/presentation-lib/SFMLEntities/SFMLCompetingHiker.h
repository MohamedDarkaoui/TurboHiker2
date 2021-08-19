#ifndef TURBOHIKER_SFMLCOMPETINGHIKER_H
#define TURBOHIKER_SFMLCOMPETINGHIKER_H

#include "../../logic-lib/Entity/CompetingHiker.h"
#include "SFMLEntity.h"

namespace SFML{

class SFMLCompetingHiker : public TurboHiker::CompetingHiker, public SFMLEntity{
public:
    /**
     * simple constructor
     * @param lane: the initial lane where the Hiker is located
     * @param size: the size of the hiker
     * @param lanePositionsX: all possible lane x-coordinates
     * @param speed: the initial speed of the hiker
     * @param speedUpFactor: the factor by which the speed can change
     * @param path_to_image: the path to the image of the competing hiker
     */
    SFMLCompetingHiker(unsigned int lane, std::pair<double, double> &size, std::vector<double>& lanePositionsX,
                       double speed, double speedUpFactor, const std::string &path_to_image);

    /**
     * default destructor
     */
    ~SFMLCompetingHiker() override = default;

    /**
     * updates entity visuals
     * @param relativePos: the relative position with respect to a given point
     * @param size: size of the competing hiker
     */
    void updateVisuals(const TurboHiker::Position2D &relativePos, std::pair<double, double> size) final;

    /**
     * updates the animation
     */
    void updateAnimation() final;

};
}

#endif //TURBOHIKER_SFMLCOMPETINGHIKER_H
