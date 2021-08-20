#include "SFMLEntity.h"

SFML::SFMLEntity::SFMLEntity(const std::string& path_to_image)
{
        texture = std::make_shared<sf::Texture>();
        assert(texture->loadFromFile(path_to_image) && "Failed to load player image");
        shape.setTexture(&*texture);
        sf::Vector2u dimensions(4, 4);
        animation = std::make_unique<Animation>(texture, dimensions);
        clock = std::make_unique<TurboHiker::Clock>(100);
}

const sf::RectangleShape& SFML::SFMLEntity::getShape() const { return shape; }

void SFML::SFMLEntity::initialize(const std::pair<double, double>& size, const TurboHiker::Position2D& relativePos)
{
        auto playerSize = Transformation::getInstance().transformSize(size.first, size.second);
        TurboHiker::Position2D playerPos = Transformation::getInstance().transform(relativePos);

        shape.setSize(sf::Vector2f(playerSize.first, playerSize.second));
        shape.setPosition(float(playerPos.getX() - playerSize.first / 2),
                          float(playerPos.getY() - playerSize.second / 2));
}

void SFML::SFMLEntity::updateAnimation() {}

void SFML::SFMLEntity::setClockTickTime(const unsigned int& tickTime) { clock->setTickTime(tickTime); }

void SFML::SFMLEntity::updateVisuals(const TurboHiker::Position2D& relativePos, std::pair<double, double> size)
{
        TurboHiker::Position2D transformed = Transformation::getInstance().transform(relativePos);
        std::pair<float, float> SFMLSize = Transformation::getInstance().transformSize(size.first, size.second);
        auto x = float(transformed.getX() - SFMLSize.first * 0.5);
        auto y = float(transformed.getY() - SFMLSize.second * 0.5);
        shape.setPosition(x, y);
}
