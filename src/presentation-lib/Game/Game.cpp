#include <iostream>
#include "Game.h"

SFMLGame::SFMLGame() {
    window  = std::make_unique<sf::RenderWindow>(sf::VideoMode(1040, 780), "TurboHiker");
}

void SFMLGame::run() {
    auto factory = std::make_shared<EntityFactory>("../../game_configurations.ini");
    std::shared_ptr<SFMLWorld> world = factory->createWorld();
    world->buildWorld(factory);

    std::vector<sf::CircleShape> dots;

    std::vector<std::shared_ptr<Hiker>> hikers;

    for (unsigned int i = 0; i < world->getEntities().size(); i++){
        dots.emplace_back(10.f);
    }
    for(const auto& compe : world->getCompetingHikers()){
        hikers.push_back(compe);
    }
    for(const auto& en : world->getEnemies()){
        hikers.push_back(en);
    }
    hikers.push_back(world->getPlayer());

    sf::RectangleShape r(sf::Vector2f (10,10));
    sf::Texture t;
    t.loadFromFile("../../images/player.png");
    r.setTexture(&t);


    while (window->isOpen()){
        if (!Clock::getInstance().clockTicked())
            continue;
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;

        for (unsigned int i = 0; i < dots.size(); i++) {
            Position2D pos = Transformation::getInstance().transform(hikers[i]->getRelativePosition(world->getPlayer()->getPosition()));
            dots[i].setPosition(pos.getX(),pos.getY());
        }


        auto player = std::dynamic_pointer_cast<SFMLPlayer>(world->getPlayer());
        player->handleEvents(event, *window);
        world->update();
        // clear the window with black color
        window->clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);

        for (const auto& dot : dots){
            //window->draw(dot);

        }
        window->draw(player->getShape());
        sf::CircleShape t(5.0f);
        auto p = Transformation::getInstance().transform({1.5,-2});
        t.setFillColor(sf::Color(255,0,0));
        t.setPosition(p.getX(),650);
        window->draw(t);
        window->draw(r);

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
