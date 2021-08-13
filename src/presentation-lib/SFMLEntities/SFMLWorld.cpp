#include "SFMLWorld.h"

SFMLWorld::SFMLWorld(double top, double height, double left, double width) : World(top, height, left, width) {}

void SFMLWorld::buildWorld(const std::shared_ptr<AbstractFactory>& factory) {
    addPlayer(factory->createPlayer());

    for (const auto& hiker : factory->createCompetingHikers(getPlayer()->getLane()))
        addCompetingHiker(hiker);

    for (const auto& enemy : factory->createStaticEnemies())
        addStaticEnemy(enemy);

    for (const auto& enemy : factory->createMovingEnemies())
        addMovingEnemy(enemy);
}

const std::set<std::shared_ptr<SFMLCompetingHiker>> &SFMLWorld::getSFMLCompetingHikers() const {
    return (const std::set<std::shared_ptr<SFMLCompetingHiker>> &) World::getCompetingHikers();
}

const std::set<std::shared_ptr<SFMLStaticEnemy>> &SFMLWorld::getSFMLStaticEnemies() const {
    return (const std::set<std::shared_ptr<SFMLStaticEnemy>> &) World::getStaticEnemies();
}

const std::set<std::shared_ptr<SFMLMovingEnemy>> &SFMLWorld::getSFMLMovingEnemies() const {
    return (const std::set<std::shared_ptr<SFMLMovingEnemy>> &) World::getMovingEnemies();
}


const std::shared_ptr<SFMLPlayer> &SFMLWorld::getSFMLPlayer() const {
    return (const std::shared_ptr<SFMLPlayer> &)World::getPlayer();
}

void SFMLWorld::update() {
    World::update();
    Position2D relativePlayerPos = getSFMLPlayer()->getRelativePosition(getSFMLPlayer()->getPosition());
    std::pair<double,double> playerSize = getSFMLPlayer()->getSize();
    getSFMLPlayer()->updateVisuals(relativePlayerPos,playerSize);

    for(const auto& competing : getSFMLCompetingHikers()) {
        Position2D relativePOS = competing->getRelativePosition(getPlayer()->getPosition());
        std::pair<double,double> size = competing->getSize();
        competing->updateVisuals(relativePOS, size);
    }
    for(const auto& enemy : getSFMLStaticEnemies()) {
        Position2D relativePOS = enemy->getRelativePosition(getPlayer()->getPosition());
        std::pair<double,double> size = enemy->getSize();
        enemy->updateVisuals(relativePOS, size);
    }
    for(const auto& enemy : getSFMLMovingEnemies()) {
        Position2D relativePOS = enemy->getRelativePosition(getPlayer()->getPosition());
        std::pair<double,double> size = enemy->getSize();
        enemy->updateVisuals(relativePOS, size);
    }
}






