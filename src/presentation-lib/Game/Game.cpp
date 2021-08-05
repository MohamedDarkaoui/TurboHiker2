#include "Game.h"

SFMLGame::SFMLGame() {
    window  = std::make_unique<sf::RenderWindow>(sf::VideoMode(1040, 780), "TurboHiker");
}

void SFMLGame::run() {
    MovingHiker player = MovingHiker({0,-3},Hiker::MOVING_STRAIGHT,5,0);

    while (window->isOpen()){
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        sf::CircleShape dot(10.f);
        Position2D pos = Transformation::getInstance().transform(player.getPosition());
        dot.setPosition(pos.getX(),pos.getY());

        handleEvent(event, player);
        player.update();
        // clear the window with black color
        window->clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        window->draw(dot);
        // end the current frame
        window->display();
    }
}

void SFMLGame::handleEvent(sf::Event& event, MovingHiker& e) {
    while (window->pollEvent(event)){
        if (event.type == sf::Event::KeyPressed){
            if (event.key.code == sf::Keyboard::Up){
                if (e.state != Hiker::MOVING_STRAIGHT){
                    e.state = Hiker::MOVING_STRAIGHT;
                }
            }
            else if (event.key.code == sf::Keyboard::Left){
                if (e.state != Hiker::MOVING_LEFT){
                    e.state = Hiker::MOVING_LEFT;
                }
            }
            else if (event.key.code == sf::Keyboard::Right){
                if (e.state != Hiker::MOVING_RIGHT){
                    e.state = Hiker::MOVING_RIGHT;
                }
            }
            else if (event.key.code == sf::Keyboard::Down){
                window->close();
            }
        }
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            window->close();
    }
}
