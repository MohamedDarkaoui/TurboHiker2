#include "SFMLWorld.h"

SFMLWorld::SFMLWorld(Position2D position, std::pair<double, double> &size) : World(position, size){}


void SFMLWorld::buildWorld(const std::shared_ptr<AbstractFactory>& factory) {
    addPlayer(factory->createPlayer());

    for (const auto& hiker : factory->createCompetingHikers(getPlayer()->getLane()))
        addCompetingHiker(hiker);

    for (const auto& enemy : factory->createStaticEnemies())
        addStaticEnemy(enemy);

    for (const auto& enemy : factory->createMovingEnemies())
        addMovingEnemy(enemy);

    for (const auto& gp : factory->createGroundPlots())
        addGRoundPlot(gp);
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

const std::set<std::shared_ptr<SFMLGroundPlot>> &SFMLWorld::getSFMLGroundPlot() const {
    return (const std::set<std::shared_ptr<SFMLGroundPlot>> &) World::getGround();
}


std::set<std::shared_ptr<SFMLEntity>> SFMLWorld::getSFMLEntities() const {
    std::set<std::shared_ptr<SFMLEntity>> entities;
    entities.insert(getSFMLCompetingHikers().begin(), getSFMLCompetingHikers().end());
    entities.insert(getSFMLMovingEnemies().begin(), getSFMLMovingEnemies().end());
    entities.insert(getSFMLStaticEnemies().begin(), getSFMLStaticEnemies().end());
    entities.insert(getSFMLPlayer());
    return entities;
}


const std::shared_ptr<SFMLPlayer> &SFMLWorld::getSFMLPlayer() const {
    return (const std::shared_ptr<SFMLPlayer> &)World::getPlayer();
}

void SFMLWorld::update() {
    World::update();

    for(const auto& entity : getEntities()) {
        entity->updateVisuals(getPosition());
    }
}








