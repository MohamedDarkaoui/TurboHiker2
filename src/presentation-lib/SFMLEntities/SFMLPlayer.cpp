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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            speedUp();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            slowDown();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            yell();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            runAtTurboSpeed();
        if (event.type == sf::Event::KeyPressed){
            if (event.key.code == sf::Keyboard::Left)
                moveLeft();
            else if (event.key.code == sf::Keyboard::Right)
                moveRight();
            else if (event.key.code == sf::Keyboard::W)
                useActiveReward();
        }
        if (event.type == sf::Event::KeyReleased){
            if (event.key.code == sf::Keyboard::Up){
                if (getAcceleration() == Hiker::SPEED_UP)
                    slowDown();
            }
            if (event.key.code == sf::Keyboard::Down)
                if (getAcceleration() == Hiker::SLOW_DOWN)
                    speedUp();
            if (event.key.code == sf::Keyboard::Q)
                stopRunningAtTurboSpeed();

        }
        // "close requested" event: we close the window
        else if (event.type == sf::Event::Closed)
            window.close();
    }
}


void SFMLPlayer::updateAnimation() {
    if (getSpeed() == 0)
        return;
    setClockTickTime(floor(200/(100*getSpeed())));
    if (clock->clockTicked()){
        animation->update(3);
        shape.setTextureRect(animation->getCurrentFrame());
    }
}

void SFMLPlayer::updateVisuals(const Position2D &relativePos, std::pair<double, double> size) {
    SFMLEntity::updateVisuals(relativePos, size);
}







