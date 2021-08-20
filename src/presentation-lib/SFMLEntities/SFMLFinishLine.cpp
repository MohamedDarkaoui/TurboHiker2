#include "SFMLFinishLine.h"

SFML::SFMLFinishLine::SFMLFinishLine(const std::string& pathToImage, TurboHiker::Position2D position,
                                     std::pair<double, double>& size, std::pair<int, int> imageCoordinates)
    : FinishLine(position, size), SFMLEntity(pathToImage)
{
        auto relativePos = getRelativePosition(getPosition());
        initialize(size, relativePos);

        sf::IntRect finish_line;
        finish_line.width = int(shape.getTexture()->getSize().x);
        finish_line.height = int(shape.getTexture()->getSize().y);

        finish_line.left = imageCoordinates.first * finish_line.width;
        finish_line.top = imageCoordinates.second * finish_line.height;

        shape.setTextureRect(finish_line);
}

void SFML::SFMLFinishLine::updateVisuals(const TurboHiker::Position2D& relativePos, std::pair<double, double> size)
{
        SFMLEntity::updateVisuals(relativePos, size);
}
