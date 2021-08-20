#include "SFMLCompetingHiker.h"

SFML::SFMLCompetingHiker::SFMLCompetingHiker(unsigned int lane, std::pair<double, double>& size,
                                             std::vector<double>& lanePositionsX, double speed, double speedUpFactor,
                                             const std::string& path_to_image)
    : CompetingHiker(lane, size, lanePositionsX, speed, speedUpFactor), SFMLEntity(path_to_image)
{
        auto relative_position = getRelativePosition(getPosition());
        initialize(size, relative_position);
        animation->update(3);
        shape.setTextureRect(animation->getCurrentFrame());
}

void SFML::SFMLCompetingHiker::updateAnimation()
{

        setClockTickTime(floor(200 / (100 * getSpeed())));
        if (clock->clockTicked()) {
                animation->update(3);
                shape.setTextureRect(animation->getCurrentFrame());
        }
}

void SFML::SFMLCompetingHiker::updateVisuals(const TurboHiker::Position2D& relativePos, std::pair<double, double> size)
{
        SFMLEntity::updateVisuals(relativePos, size);
}
