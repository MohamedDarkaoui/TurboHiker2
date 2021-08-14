#include "SFMLGroundPlot.h"

SFMLGroundPlot::SFMLGroundPlot(Position2D position, std::pair<double, double> &size, const std::string& path_to_image,
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

void SFMLGroundPlot::updateVisuals(const Position2D& reference) {
    Position2D relativePos = getRelativePosition(reference);
    std::pair<double,double> size = getSize();
    Position2D transformed = Transformation::getInstance().transform(relativePos);
    std::pair<float,float> SFMLSize = Transformation::getInstance().transformSize(size.first,size.second);
    auto x = float(transformed.getX() - SFMLSize.first * 0.5);
    auto y = float(transformed.getY() - SFMLSize.second * 0.5);
    shape.setPosition(x,y);
}

void SFMLGroundPlot::update() {}
