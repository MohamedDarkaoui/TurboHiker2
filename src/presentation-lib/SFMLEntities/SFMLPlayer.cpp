#include <iostream>
#include "SFMLPlayer.h"

SFMLPlayer::SFMLPlayer(unsigned int lane, std::pair<double, double> &size, std::vector<double>& lanePositionsX, double
speed,double speedUpFactor, double yellingRange, const std::string& path_to_image) :
Player(lane,size,lanePositionsX,speed,speedUpFactor,yellingRange), SFMLEntity(path_to_image){
    auto relative_position = getRelativePosition(getPosition());
    initialize(size,relative_position);
    animation->update(3);
    shape.setTextureRect(animation->getCurrentFrame());
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

void SFMLPlayer::updateVisuals(const Position2D& reference) {
    Position2D relativePos = getRelativePosition(reference);
    std::pair<double,double> size = getSize();
    Position2D transformed = Transformation::getInstance().transform(relativePos);
    std::pair<float,float> SFMLSize = Transformation::getInstance().transformSize(size.first,size.second);
    auto x = float(transformed.getX() - SFMLSize.first * 0.5);
    auto y = float(transformed.getY() - SFMLSize.second * 0.5);
    shape.setPosition(x,y);
}

void SFMLPlayer::updateAnimation() {
    double factor = 1;
    switch (getAcceleration()) {

        case NONE:
            factor = 1;
            break;
        case SPEED_UP:
            factor = 0.5;
            break;
        case SLOW_DOWN:
            factor = 2;
            break;
    }
    factor = 100 * factor;
    setClockTickTime(floor(factor));
    if (clock->clockTicked()){
        animation->update(3);
        shape.setTextureRect(animation->getCurrentFrame());
    }
}







