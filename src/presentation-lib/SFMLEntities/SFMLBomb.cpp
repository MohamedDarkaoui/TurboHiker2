#include "SFMLBomb.h"

SFML::SFMLBomb::SFMLBomb(const std::string &pathToImage, TurboHiker::Position2D position,
                         std::pair<double, double> &size, double speed)
                         : Bomb(position, size, speed), SFMLEntity(pathToImage) {

    auto relative_position = getRelativePosition(getPosition());
    initialize(size,relative_position);
}

void SFML::SFMLBomb::updateVisuals(const TurboHiker::Position2D &relativePos, std::pair<double, double> size) {
    SFMLEntity::updateVisuals(relativePos, size);
}
