#include "SFMLWorld.h"

using namespace SFML;
using namespace TurboHiker;

SFMLWorld::SFMLWorld(Position2D position, std::pair<double, double>& size, std::shared_ptr<AbstractFactory>& factory)
    : World(position, size, factory)
{
}

void SFMLWorld::buildWorld()
{
        addPlayer(getFactory()->createPlayer());
        addFinishLine(getFactory()->createFinishLine());
        for (const auto& hiker : getFactory()->createCompetingHikers(getPlayer()->getLane()))
                addCompetingHiker(hiker);

        for (const auto& enemy : getFactory()->createStaticEnemies())
                addStaticEnemy(enemy);

        for (const auto& enemy : getFactory()->createMovingEnemies())
                addMovingEnemy(enemy);

        for (const auto& gp : getFactory()->createGroundPlots())
                addGRoundPlot(gp);

        for (const auto& item : getFactory()->createPassiveItem())
                addPassiveItem(item);

        for (const auto& item : getFactory()->createActiveItems())
                addActiveItem(item);
}

const std::set<std::shared_ptr<SFMLCompetingHiker>>& SFMLWorld::getSFMLCompetingHikers() const
{
        return (const std::set<std::shared_ptr<SFMLCompetingHiker>>&)World::getCompetingHikers();
}

const std::set<std::shared_ptr<SFMLStaticEnemy>>& SFMLWorld::getSFMLStaticEnemies() const
{
        return (const std::set<std::shared_ptr<SFMLStaticEnemy>>&)World::getStaticEnemies();
}

const std::set<std::shared_ptr<SFMLMovingEnemy>>& SFMLWorld::getSFMLMovingEnemies() const
{
        return (const std::set<std::shared_ptr<SFMLMovingEnemy>>&)World::getMovingEnemies();
}

const std::set<std::shared_ptr<SFMLPassiveItem>>& SFMLWorld::getSFMLPassiveItems() const
{
        return (const std::set<std::shared_ptr<SFMLPassiveItem>>&)getPassiveItems();
}

const std::set<std::shared_ptr<SFMLActiveItem>>& SFMLWorld::getSFMLActiveItems() const
{
        return (const std::set<std::shared_ptr<SFMLActiveItem>>&)getActiveItems();
}

const std::set<std::shared_ptr<SFMLGroundPlot>>& SFMLWorld::getSFMLGroundPlot() const
{
        return (const std::set<std::shared_ptr<SFMLGroundPlot>>&)World::getGround();
}

const std::shared_ptr<SFMLFinishLine>& SFMLWorld::getSFMLFinishLine() const
{
        return (const std::shared_ptr<SFMLFinishLine>&)getFinishLine();
}

const std::set<std::shared_ptr<SFMLBomb>>& SFMLWorld::getSFMLBombs() const
{
        return (const std::set<std::shared_ptr<SFMLBomb>>&)getBombs();
}

std::set<std::shared_ptr<SFMLEntity>> SFMLWorld::getSFMLEntities() const
{
        std::set<std::shared_ptr<SFMLEntity>> entities;
        entities.insert(getSFMLCompetingHikers().begin(), getSFMLCompetingHikers().end());
        entities.insert(getSFMLMovingEnemies().begin(), getSFMLMovingEnemies().end());
        entities.insert(getSFMLStaticEnemies().begin(), getSFMLStaticEnemies().end());
        entities.insert(getSFMLPassiveItems().begin(), getSFMLPassiveItems().end());
        entities.insert(getSFMLActiveItems().begin(), getSFMLActiveItems().end());
        entities.insert(getSFMLPlayer());
        return entities;
}

const std::shared_ptr<SFMLPlayer>& SFMLWorld::getSFMLPlayer() const
{
        return (const std::shared_ptr<SFMLPlayer>&)World::getPlayer();
}

void SFMLWorld::update()
{
        World::update();

        for (const auto& entity : getEntities()) {
                entity->updateVisuals(entity->getRelativePosition(getPosition()), entity->getSize());
        }
}

void SFMLWorld::spawnMovingEnemy(unsigned int lane, double y_pos, double speedFactor)
{
        if (speedFactor > 0)
                y_pos += getPlayer()->getSize().second;
        else
                y_pos -= getPlayer()->getSize().second;
        addMovingEnemy(getFactory()->createMovingEnemy(lane, y_pos, speedFactor));
}

void SFMLWorld::spawnStaticEnemy(unsigned int lane, double y_pos)
{
        addStaticEnemy(getFactory()->createStaticEnemy(lane, y_pos - getPlayer()->getSize().second));
}

void SFMLWorld::spawnBomb()
{
        auto playerPos = getPlayer()->getPosition().getY();
        double yPos = Random::getInstance().random(playerPos, playerPos + 10);

        auto bomb = getFactory()->createBomb();
        bomb->setPosition({-5, yPos});
        addBomb(bomb);
}
