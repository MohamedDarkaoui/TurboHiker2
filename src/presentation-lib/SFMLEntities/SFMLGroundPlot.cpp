#include "SFMLGroundPlot.h"

SFML::SFMLGroundPlot::SFMLGroundPlot(TurboHiker::Position2D position, std::pair<double, double> &size, const std::string& path_to_image,
std::pair<int,int> dimensions, std::pair<int,int> imageCoordinates) : GroundPlot(position, size), SFMLEntity(path_to_image) {
    auto relativePos = getRelativePosition(getPosition());
    initialize(size,relativePos);

    sf::IntRect piece;
    piece.width = int(shape.getTexture()->getSize().x / dimensions.first);
    piece.height = int(shape.getTexture()->getSize().y / dimensions.second);

    piece.left = imageCoordinates.first * piece.width;
    piece.top = imageCoordinates.second * piece.height;

    shape.setTextureRect(piece);
}

void SFML::SFMLGroundPlot::update() {}

void SFML::SFMLGroundPlot::updateVisuals(const TurboHiker::Position2D &relativePos, std::pair<double, double> size) {
    SFMLEntity::updateVisuals(relativePos, size);
}
