#include <iostream>
#include "Game.h"

SFMLGame::SFMLGame() {
    window  = std::make_unique<sf::RenderWindow>(sf::VideoMode(1040, 780), "TurboHiker");
}

void SFMLGame::run() {
    auto factory = std::make_shared<EntityFactory>("../../game_configurations.ini");
    std::shared_ptr<SFMLWorld> world = factory->createWorld();
    world->buildWorld(factory);

    auto player = world->getSFMLPlayer();

    while (window->isOpen()){
        if (!Clock::getInstance().clockTicked())
            continue;
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;

        player->handleEvents(event, *window);
        world->update();
        // clear the window with black color
        window->clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);

        window->draw(player->getShape());

        for (const auto& competitor : world->getSFMLCompetingHikers()){
            window->draw(competitor->getShape());
        }
        for (const auto& enemy : world->getSFMLStaticEnemies()){
            window->draw(enemy->getShape());
        }
        for (const auto& enemy : world->getSFMLMovingEnemies()){
            window->draw(enemy->getShape());
        }



        // end the current frame
        window->display();
    }
}

