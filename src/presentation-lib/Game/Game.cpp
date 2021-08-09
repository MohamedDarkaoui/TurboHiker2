#include <iostream>
#include "Game.h"

SFMLGame::SFMLGame() {
    window  = std::make_unique<sf::RenderWindow>(sf::VideoMode(1040, 780), "TurboHiker");
}

void SFMLGame::run() {
    World world;
    world.createCompetingHikers();
    std::shared_ptr<CompetingHiker> h1 = world.getCompeting()[0];
    std::shared_ptr<CompetingHiker> h2 = world.getCompeting()[1];

//    world.addEntity(h1);
//    world.addEntity(h2);


//    sf::RectangleShape line(sf::Vector2f(5, 900));
//    line.rotate(90);


    while (window->isOpen()){
        if (!Clock::getInstance().clockTicked())
            continue;
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        sf::CircleShape dot(10.f);
        sf::CircleShape dot2(10.f);
        Position2D pos = Transformation::getInstance().transform(h1->getRelativePosition(h1->getPosition()));
        dot.setPosition(pos.getX(),pos.getY());

        Position2D pos2 = Transformation::getInstance().transform(h2->getRelativePosition(h1->getPosition()));
        dot2.setPosition(pos2.getX(),pos2.getY());

        handleEvent(event, *h1);
        world.update();
        // clear the window with black color
        window->clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);

        window->draw(dot);
        window->draw(dot2);
        // end the current frame
        window->display();
    }
}

void SFMLGame::handleEvent(sf::Event& event, CompetingHiker& e) {
    while (window->pollEvent(event)){
        if (event.type == sf::Event::KeyPressed){
            if (event.key.code == sf::Keyboard::Up){
                e.speedUp();
            }
            else if (event.key.code == sf::Keyboard::Left){
                e.moveLeft();
            }
            else if (event.key.code == sf::Keyboard::Right){
                e.moveRight();
            }
            else if (event.key.code == sf::Keyboard::Down){
                e.slowDown();
            }
        }
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            window->close();
    }
}
