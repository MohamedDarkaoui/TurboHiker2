#include <iostream>
#include "Game.h"

SFMLGame::SFMLGame() {
    window  = std::make_unique<sf::RenderWindow>(sf::VideoMode(1040, 780), "TurboHiker");
}

void SFMLGame::run() {
    auto factory = std::make_shared<EntityFactory>("game_configurations.ini");
    std::shared_ptr<SFMLWorld> world = factory->createWorld();
    world->buildWorld();
    auto player = world->getSFMLPlayer();

    Clock loopClock(20);
    Clock animationClock (100);

    sf::Font font;
    assert(font.loadFromFile("res/Blazed.ttf") && "Error loading font file.");
    sf::Text text;
    text.setFont(font);
    text.setFillColor(sf::Color(139,0,0));

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

        int score = player->getScore()->getPoints(player->getPosition().getY());
        std::string score_string = std::to_string(score);
        text.setString(score_string);

        for(const auto& gp : world->getSFMLGroundPlot())
            window->draw(gp->getShape());
        for(const auto& item : world->getSFMLPassiveItems())
            window->draw(item->getShape());
        for(const auto& item : world->getSFMLActiveItems())
            window->draw(item->getShape());
        for(const auto& enemy : world->getSFMLStaticEnemies())
            window->draw(enemy->getShape());
        for(const auto& enemy : world->getSFMLMovingEnemies())
            window->draw(enemy->getShape());
        for(const auto& comp : world->getSFMLCompetingHikers())
            window->draw(comp->getShape());

        window->draw(world->getSFMLFinishLine()->getShape());
        window->draw(world->getSFMLPlayer()->getShape());
        window->draw(text);
        window->display();
    }
}

