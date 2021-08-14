#include <iostream>
#include "Game.h"

SFMLGame::SFMLGame() {
    window  = std::make_unique<sf::RenderWindow>(sf::VideoMode(1040, 780), "TurboHiker");
}

void SFMLGame::run() {
    auto factory = std::make_shared<EntityFactory>("../../game_configurations.ini");
    std::shared_ptr<SFMLWorld> world = factory->createWorld();
    world->buildWorld(factory);
    std::cout<<"ok\n";
    auto player = world->getSFMLPlayer();

    Clock loopClock(20);
    Clock animationClock (100);
    std::string path = "../../images/ground.png";
    std::pair<double,double> size =std::make_pair(1.0,1.0);
//    SFMLGroundPlot plot({0,0}, size,path,std::make_pair(8,8),std::make_pair(0,4));
    while (window->isOpen()){
        if (!loopClock.clockTicked())
            continue;
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;

        player->handleEvents(event, *window);
        world->update();
        // clear the window with black color
        window->clear(sf::Color::Black);

        window->draw(player->getShape());


        for (const auto& entity : world->getSFMLEntities()){
            entity->updateAnimation();
        }
        for(const auto& gp : world->getSFMLGroundPlot())
            window->draw(gp->getShape());
        for(const auto& enemy : world->getSFMLStaticEnemies())
            window->draw(enemy->getShape());
        for(const auto& enemy : world->getSFMLMovingEnemies())
            window->draw(enemy->getShape());
        for(const auto& comp : world->getSFMLCompetingHikers())
            window->draw(comp->getShape());
        window->draw(world->getSFMLPlayer()->getShape());

        window->display();
    }
}

