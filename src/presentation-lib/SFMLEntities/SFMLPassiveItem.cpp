#include "SFMLPassiveItem.h"

SFML::SFMLPassiveItem::SFMLPassiveItem(const std::string& pathToImage, unsigned int lane,
                                       std::pair<double, double>& size, std::vector<double>& lanePositionsX,
                                       std::vector<std::vector<int>>& possible_rewards)
    : PassiveItem(lane, size, lanePositionsX, possible_rewards), SFMLEntity(pathToImage)
{
        auto relative_position = getRelativePosition(getPosition());
        initialize(size, relative_position);
}

void SFML::SFMLPassiveItem::updateVisuals(const TurboHiker::Position2D& relativePos, std::pair<double, double> size)
{
        SFMLEntity::updateVisuals(relativePos, size);
}
