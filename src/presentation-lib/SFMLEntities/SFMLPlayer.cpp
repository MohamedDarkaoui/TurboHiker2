#include <iostream>
#include "SFMLPlayer.h"

SFMLPlayer::SFMLPlayer(double speed, unsigned int lane, const std::string& path_to_image) : Player(speed, lane) {
    auto size = Transformation::getInstance().transformSize(getSize(),getSize());
    Position2D playerPos = Transformation::getInstance().transform(getRelativePosition(getPosition()));

    shape = sf::RectangleShape(sf::Vector2f (size.first, size.second));
    texture = std::make_shared<sf::Texture>();
    shape.setPosition(float(playerPos.getX()-size.first/2),float(playerPos.getY()-size.second/2));
    assert(texture->loadFromFile(path_to_image) && "Failed to load player image");
    shape.setTexture(&*texture);
}

const sf::RectangleShape& SFMLPlayer::getShape() const {
    return shape;
}

void SFMLPlayer::handleEvents(sf::Event &event, sf::RenderWindow& window) {
    while (window.pollEvent(event)){
        if (event.type == sf::Event::KeyPressed){
            switch(event.key.code){
                case sf::Keyboard::Up:
                    speedUp();
                    break;
                case sf::Keyboard::Left:
                    moveLeft();
                    break;
                case  sf::Keyboard::Right:
                    moveRight();
                    break;
                case sf::Keyboard::Down:
                    slowDown();
                    break;
                case sf::Keyboard::Space:
                     yell();
                     break;
                default:
                     break;
            }
        }
        // "close requested" event: we close the window
        else if (event.type == sf::Event::Closed)
            window.close();
    }
}

void SFMLPlayer::update() {
    Player::update();
    updateVisuals();
}

void SFMLPlayer::updateVisuals() {
    Position2D position = getRelativePosition(getPosition());
    Position2D transformed = Transformation::getInstance().transform(position);
    std::pair<float,float> SFMLSize = Transformation::getInstance().transformSize(getSize(),getSize());
    auto x = float(transformed.getX() - SFMLSize.first * 0.5);
    auto y = float(transformed.getY() - SFMLSize.second * 0.5);

    shape.setPosition(x,y);
}




