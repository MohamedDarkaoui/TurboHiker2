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

    sf::Font font;
    assert(font.loadFromFile("res/Blazed.ttf") && "Error loading font file.");

    while (window->isOpen()){
        if (!loopClock.clockTicked())
            continue;
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        player->handleEvents(event, *window, world->getSize().second);
        world->update();

        // clear the window with black color
        window->clear(sf::Color::Black);

        // draw everything
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

        window->draw(world->getSFMLPlayer()->getShape());
        window->draw(world->getSFMLFinishLine()->getShape());
        window->draw(player->visualizeScore(font));
        window->draw(player->visualizeActiveRewards(font));
        window->draw(player->visualizePassiveRewards(font));

        if (player->isFinished())
            displayScoreScreen(world->getCompetingHikers(),world->getPlayer(),font);

        window->display();
    }
}

void SFML::SFMLGame::displayScoreScreen(const std::set<std::shared_ptr<TurboHiker::CompetingHiker>>& competingHikers,
                                        const std::shared_ptr<TurboHiker::Player>& player, const sf::Font& font) {
    std::string text = "Player:               ";
    int score = player->getScore()->getPoints(player->getPosition().getY());
    text += std::to_string(score) + "\n";

    int i = 0;
    for (const auto& competingHiker : competingHikers){
        text += "Competing hiker " + std::to_string(i+1) + ": ";
        int s = competingHiker->getScore()->getPoints(competingHiker->getPosition().getY());
        text += std::to_string(s) + "\n";
        i++;
    }

    TurboHiker::Position2D pos = Transformation::getInstance().transform(TurboHiker::Position2D{-2,3});
    sf::Text sfmlText;
    sfmlText.setFont(font);
    sfmlText.setFillColor(sf::Color(0,0,0));
    sfmlText.setString(text);
    sfmlText.setPosition(float(pos.getX()),float(pos.getY()));
    window->draw(sfmlText);
}

