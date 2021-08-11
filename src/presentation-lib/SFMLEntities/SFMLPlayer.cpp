#include "SFMLPlayer.h"


SFMLPlayer::SFMLPlayer(double speed, unsigned int lane, const std::string& path_to_image) : Player(speed, lane) {
    shape = sf::RectangleShape(sf::Vector2f(float(getSize()),0.1));
    assert(player_texture.loadFromFile(path_to_image)&& "Failed to load player image");
    shape.setTexture(&player_texture);
}

void SFMLPlayer::handleEvents(sf::Event &event, sf::Window& window) {
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
//            if (event.key.code == sf::Keyboard::Up){
//                speedUp();
//            }
//            else if (event.key.code == sf::Keyboard::Left){
//                moveLeft();
//            }
//            else if (event.key.code == sf::Keyboard::Right){
//                moveRight();
//            }
//            else if (event.key.code == sf::Keyboard::Down){
//                slowDown();
//            }
//            else if (event.key.code == sf::Keyboard::Space){
//                yell();
//            }
        }
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            window.close();
    }
}
