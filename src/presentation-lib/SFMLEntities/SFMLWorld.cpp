#include "SFMLWorld.h"

SFMLWorld::SFMLWorld(double top, double height, double left, double width) : World(top, height, left, width) {}

void SFMLWorld::buildWorld(const std::shared_ptr<AbstractFactory>& factory) {
    addPlayer(factory->createPlayer());

    for (const auto& hiker : factory->createCompetingHikers(getPlayer()->getLane()))
        addCompetingHiker(hiker);

    for (const auto& enemy : factory->createStaticEnemies())
        addEnemy(enemy);

}

