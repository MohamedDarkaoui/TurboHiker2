#include "SFMLEntity.h"

SFMLEntity::SFMLEntity(const std::string &path_to_image)  {
    texture = std::make_shared<sf::Texture>();
    assert(texture->loadFromFile(path_to_image) && "Failed to load player image");
    shape.setTexture(&*texture);
    sf::Vector2u dimensions(4,4);
    animation = std::make_unique<Animation>(texture,dimensions);
    clock = std::make_unique<Clock>(100);
}

const sf::RectangleShape &SFMLEntity::getShape() const {
    return shape;
}


void SFMLEntity::initialize(const std::pair<double,double> &size, const Position2D& relativePos) {
    auto playerSize = Transformation::getInstance().transformSize(size.first,size.second);
    Position2D playerPos = Transformation::getInstance().transform(relativePos);

    shape.setSize(sf::Vector2f (playerSize.first, playerSize.second));
    shape.setPosition(float(playerPos.getX()-playerSize.first/2),float(playerPos.getY()-playerSize.second/2));
}

void SFMLEntity::updateAnimation() {}

void SFMLEntity::setClockTickTime(const unsigned int& tickTime) {
    clock->setTickTime(tickTime);
}

void SFMLEntity::updateVisuals(const Position2D& relativePos, std::pair<double,double> size) {
    Position2D transformed = Transformation::getInstance().transform(relativePos);
    std::pair<float,float> SFMLSize = Transformation::getInstance().transformSize(size.first,size.second);
    auto x = float(transformed.getX() - SFMLSize.first * 0.5);
    auto y = float(transformed.getY() - SFMLSize.second * 0.5);
    shape.setPosition(x,y);
}

