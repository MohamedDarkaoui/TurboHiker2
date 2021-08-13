#include <iostream>
#include "SFMLPlayer.h"

SFMLPlayer::SFMLPlayer(unsigned int lane, std::pair<double, double> &size, std::vector<double>& lanePositionsX, double
speed,double speedUpFactor, double yellingRange, const std::string& path_to_image) :
Player(lane,size,lanePositionsX,speed,speedUpFactor,yellingRange), SFMLEntity(path_to_image){
    auto relative_position = getRelativePosition(getPosition());
    initialize(size,relative_position);
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







