#include <iostream>
#include "Game.h"

SFML::SFMLGame::SFMLGame() {
    window  = std::make_unique<sf::RenderWindow>(sf::VideoMode(1040, 780), "TurboHiker");
}

void SFML::SFMLGame::run(const std::string& config_path) {
    auto factory = std::make_shared<EntityFactory>(config_path);
    std::shared_ptr<SFMLWorld> world = factory->createWorld();
    world->buildWorld();
    auto player = world->getSFMLPlayer();

    TurboHiker::Clock loopClock(20);
    TurboHiker::Clock animationClock (100);

    sf::Sound yelling_sound;
    sf::SoundBuffer yelling_sound_buffer;
    assert(yelling_sound_buffer.loadFromFile("sounds/yell.wav") && "Error loading yelling sound");


    yelling_sound.setBuffer(yelling_sound_buffer);


    sf::Font font;
    assert(font.loadFromFile("res/Blazed.ttf") && "Error loading font file.");

    while (window->isOpen()){
        if (!loopClock.clockTicked())
            continue;
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
            yelling_sound.play();
        }

        player->handleEvents(event, *window);
        world->update();

        // clear the window with black color
        window->clear(sf::Color::Black);

        window->draw(player->getShape());

        for (const auto& entity : world->getSFMLEntities())
            entity->updateAnimation();
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
        window->draw(player->visualizeScore(font));
        window->draw(player->visualizeActiveRewards(font));
        window->draw(player->visualizePassiveRewards(font));
        window->display();
    }
}

