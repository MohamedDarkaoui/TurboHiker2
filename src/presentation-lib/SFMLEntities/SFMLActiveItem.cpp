#include "SFMLActiveItem.h"

SFML::SFMLActiveItem::SFMLActiveItem(const std::string& pathToImage, unsigned int lane, std::pair<double, double>& size,
                                     std::vector<double>& lanePositionsX)
    : ActiveItem(lane, size, lanePositionsX), SFMLEntity(pathToImage)
{
        auto relative_position = getRelativePosition(getPosition());
        initialize(size, relative_position);
}

void SFML::SFMLActiveItem::updateVisuals(const TurboHiker::Position2D& relativePos, std::pair<double, double> size)
{
        SFMLEntity::updateVisuals(relativePos, size);
}