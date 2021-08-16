#include "SFMLFinishLine.h"

SFMLFinishLine::SFMLFinishLine(const std::string &pathToImage, Position2D position,
                               std::pair<double, double> &size, std::pair<int,int> imageCoordinates)
                               : FinishLine(position, size), SFMLEntity(pathToImage) {
    auto relativePos = getRelativePosition(getPosition());
    initialize(size,relativePos);

    sf::IntRect finish_line;
    finish_line.width = int(shape.getTexture()->getSize().x);
    finish_line.height = int(shape.getTexture()->getSize().y);

    finish_line.left = imageCoordinates.first * finish_line.width;
    finish_line.top = imageCoordinates.second * finish_line.height;

    shape.setTextureRect(finish_line);
}

void SFMLFinishLine::updateVisuals(const Position2D& reference) {
    Position2D relativePos = getRelativePosition(reference);
    std::pair<double,double> size = getSize();
    Position2D transformed = Transformation::getInstance().transform(relativePos);
    std::pair<float,float> SFMLSize = Transformation::getInstance().transformSize(size.first,size.second);
    auto x = float(transformed.getX() - SFMLSize.first * 0.5);
    auto y = float(transformed.getY() - SFMLSize.second * 0.5);
    shape.setPosition(x,y);
}