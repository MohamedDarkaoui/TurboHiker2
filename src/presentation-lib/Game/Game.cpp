#include <iostream>
#include "Game.h"

SFMLGame::SFMLGame() {
    window  = std::make_unique<sf::RenderWindow>(sf::VideoMode(1040, 780), "TurboHiker");
}

void SFMLGame::run() {
    World world;
    world.createCompetingHikers();
//    std::shared_ptr<Player> player = world.getPlayer();
//    std::shared_ptr<CompetingHiker> h1 = world.getCompeting()[0];
//    std::shared_ptr<CompetingHiker> h2 = world.getCompeting()[1];
//    std::shared_ptr<Enemy> e = world.getEnemyHikers()[0];


    std::vector<sf::CircleShape> dots;

    std::vector<std::shared_ptr<Hiker>> hikers;

    for (unsigned int i = 0; i < world.getEntities().size(); i++){
        dots.emplace_back(10.f);
    }
    for(const auto& compe : world.getCompetingHikers()){
        hikers.push_back(compe);
    }
    for(const auto& en : world.getEnemies()){
        hikers.push_back(en);
    }
    hikers.push_back(world.getPlayer());




//    world.addEntity(h1);
//    world.addEntity(h2);


//    sf::RectangleShape line(sf::Vector2f(5, 900));
//    line.rotate(90);


    while (window->isOpen()){
        if (!Clock::getInstance().clockTicked())
            continue;
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;

        for (unsigned int i = 0; i < dots.size(); i++) {
            Position2D pos = Transformation::getInstance().transform(hikers[i]->getRelativePosition(world.getPlayer()->getPosition()));
            dots[i].setPosition(pos.getX(),pos.getY());
        }



        handleEvent(event, *world.getPlayer());
        world.update();
        // clear the window with black color
        window->clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);

        for (const auto& dot : dots){
            window->draw(dot);
        }

        // end the current frame
        window->display();
    }
}

void SFMLGame::handleEvent(sf::Event& event, Player& e) {
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
            else if (event.key.code == sf::Keyboard::Space){
                e.yell();
            }
        }
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            window->close();
    }
}
