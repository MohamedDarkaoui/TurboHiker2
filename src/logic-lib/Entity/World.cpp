#include "World.h"
#include <iostream>
TurboHiker::World::World(Position2D position, std::pair<double, double>& size,
                         std::shared_ptr<AbstractFactory>& factory)
    : TurboHiker::Entity(position, size), factory(factory)
{
}

void TurboHiker::World::update()
{
        handleRewardUsage();
        trackPlayer();

        controlCompetingHikers();
        // make one big set with all entities
        auto entities = getEntities();

        // update all entities
        for (auto& entity : entities) {
                entity->update();
        }
        handleEvents();
        checkToDestroyEntities();
        chanceToSpawnBomb();
}

void TurboHiker::World::addPlayer(const std::shared_ptr<Player>& p) { player = p; }

void TurboHiker::World::addCompetingHiker(const std::shared_ptr<CompetingHiker>& competing)
{
        competing_hikers.insert(competing);
}

void TurboHiker::World::addStaticEnemy(const std::shared_ptr<StaticEnemy>& static_enemy)
{
        static_enemies.insert(static_enemy);
}

void TurboHiker::World::addMovingEnemy(const std::shared_ptr<MovingEnemy>& moving_enemy)
{
        moving_enemies.insert(moving_enemy);
}

void TurboHiker::World::addGRoundPlot(const std::shared_ptr<GroundPlot>& groundPlot) { ground.insert(groundPlot); }

void TurboHiker::World::addPassiveItem(const std::shared_ptr<PassiveItem>& passiveItem)
{
        passive_items.insert(passiveItem);
}

void TurboHiker::World::addActiveItem(const std::shared_ptr<ActiveItem>& activeItem)
{
        active_items.insert(activeItem);
}

void TurboHiker::World::addFinishLine(const std::shared_ptr<FinishLine>& finishLine) { finish_line = finishLine; }

void TurboHiker::World::addBomb(const std::shared_ptr<Bomb>& bomb) { bombs.insert(bomb); }

void TurboHiker::World::handleHikerCollisions()
{
        std::set<std::shared_ptr<CompetingHiker>> hikers = competing_hikers;
        hikers.insert(player);

        for (auto& hiker1 : hikers) {
                for (auto& hiker2 : hikers) {
                        if (hiker1 == hiker2)
                                continue;
                        if (hiker1->getLane() == hiker2->getLane()) {
                                double y1 = hiker1->getPosition().getY();
                                double y2 = hiker2->getPosition().getY();
                                double colliding_distance = (hiker1->getSize().second + (hiker2->getSize()).second) / 4;
                                if (std::abs(y1 - y2) < colliding_distance + 0.05) {
                                        if (y1 <= y2)
                                                controlHikerAtCollision(hiker1);
                                        else
                                                controlHikerAtCollision(hiker2);
                                }
                                if (std::abs(y1 - y2) < colliding_distance && !hiker2->isColliding()) {
                                        if (y1 <= y2) {
                                                hiker1->collide();
                                                hiker1->notifyObservers(ObserverEvent::COMPETING_HIKER_COLLISION);
                                        } else {
                                                hiker2->collide();
                                                hiker2->notifyObservers(ObserverEvent::COMPETING_HIKER_COLLISION);
                                        }
                                }
                        }
                }
        }
}

void TurboHiker::World::handleHikerEnemyCollisions()
{
        std::set<std::shared_ptr<CompetingHiker>> hikers = competing_hikers;
        hikers.insert(player);

        for (auto& hiker : hikers) {
                for (auto& enemy : getEnemies()) {
                        if (hiker->getLane() == enemy->getLane()) {
                                double y1 = hiker->getPosition().getY();
                                double y2 = enemy->getPosition().getY();
                                double collision_distance = (hiker->getSize().second + (enemy->getSize()).second) / 4;
                                if (std::abs(y1 - y2) < collision_distance + 0.05)
                                        controlHikerAtCollision(hiker);
                                if (std::abs(y1 - y2) < collision_distance) {
                                        hiker->collide();
                                        hiker->notifyObservers(ObserverEvent::ENEMY_COLLISION);
                                }
                        }
                }
        }
}

void TurboHiker::World::handleHikerBombCollision()
{
        std::set<std::shared_ptr<CompetingHiker>> hikers = getAllCompetingHikers();
        for (const auto& hiker : hikers) {
                for (const auto& bomb : bombs) {
                        bool x_collide = std::abs(hiker->getPosition().getX() - bomb->getPosition().getX()) <
                                         (bomb->getSize().first + hiker->getSize().first) / 2.5;
                        bool y_collide = std::abs(hiker->getPosition().getY() - bomb->getPosition().getY()) <
                                         (bomb->getSize().second + hiker->getSize().second) / 2.5;

                        if (x_collide and y_collide) {
                                hiker->setPosition({hiker->getPosition().getX(), 0});
                        }
                }
        }
}

void TurboHiker::World::handleCollectingItem() const
{
        std::set<std::shared_ptr<CompetingHiker>> hikers = getAllCompetingHikers();
        for (auto hiker : hikers) {
                for (const auto& item : getItems()) {
                        if (hiker->getLane() == item->getLane()) {
                                double y1 = hiker->getPosition().getY();
                                double y2 = item->getPosition().getY();
                                double collision_distance = (hiker->getSize().second + (item->getSize()).second) / 4;
                                if (std::abs(y2 - y1) < collision_distance) {
                                        item->giveReward(hiker, hikers);
                                        hiker->notifyObservers(ObserverEvent::BONUS);
                                }
                        }
                }
        }
}

void TurboHiker::World::handleYelling()
{
        if (player->isYelling()) {
                for (auto& enemy : getEnemies()) {
                        if (enemy->getLane() == player->getLane()) {
                                double enemy_y = enemy->getPosition().getY();
                                double player_y = player->getPosition().getY();
                                double range = player->getYellingRange();

                                if (enemy_y > player_y && enemy_y < player_y + range) {
                                        enemy->gotYelledAt();
                                }
                        }
                }
        }
}

void TurboHiker::World::handleRewardUsage()
{
        std::set<std::shared_ptr<CompetingHiker>> hikers = getAllCompetingHikers();

        for (const auto& hiker : hikers) {
                if (hiker->isUsingActiveReward() and !hiker->rewardsEmpty()) {
                        std::pair<bool, double> reward = hiker->getFirstReward();
                        if (reward.first)
                                spawnMovingEnemy(hiker->getLane(), hiker->getPosition().getY(), reward.second);
                        else
                                spawnStaticEnemy(hiker->getLane(), hiker->getPosition().getY());
                }
        }
}

void TurboHiker::World::handleEvents()
{
        handleHikerCollisions();
        handleHikerEnemyCollisions();
        handleYelling();
        handleCollectingItem();
        handleHikerBombCollision();
}

void TurboHiker::World::trackPlayer()
{
        if (position.getY() >= getSize().second)
                return;
        if (getPosition().getY() - player->getPosition().getY() > 0.5) {
                position -= {0, 1};
                return;
        }

        if (player->getAcceleration() == Hiker::SLOW_DOWN) {
                position += {0, player->getSpeed() * player->getSpeedUpFactor() * 2};
                if (position.getY() - player->getPosition().getY() >= 0.5)
                        player->speedUp();
        } else if (player->getAcceleration() == Hiker::SPEED_UP) {
                position += {0, player->getSpeed() / player->getSpeedUpFactor()};
                if (player->getPosition().getY() - position.getY() >= 4.5)
                        player->slowDown();
        } else {
                position += {0, player->getSpeed()};
        }
}

std::set<std::shared_ptr<TurboHiker::Entity>> TurboHiker::World::getEntities() const
{
        std::set<std::shared_ptr<TurboHiker::Entity>> entities;
        entities.insert(ground.begin(), ground.end());
        entities.insert(competing_hikers.begin(), competing_hikers.end());
        entities.insert(static_enemies.begin(), static_enemies.end());
        entities.insert(moving_enemies.begin(), moving_enemies.end());
        entities.insert(passive_items.begin(), passive_items.end());
        entities.insert(active_items.begin(), active_items.end());
        entities.insert(bombs.begin(), bombs.end());
        entities.insert(finish_line);
        entities.insert(player);

        return entities;
}

std::set<std::shared_ptr<TurboHiker::Enemy>> TurboHiker::World::getEnemies() const
{
        std::set<std::shared_ptr<Enemy>> enemies;
        enemies.insert(static_enemies.begin(), static_enemies.end());
        enemies.insert(moving_enemies.begin(), moving_enemies.end());

        return enemies;
}

std::set<std::shared_ptr<TurboHiker::CollectableItem>> TurboHiker::World::getItems() const
{
        std::set<std::shared_ptr<CollectableItem>> items;
        items.insert(passive_items.begin(), passive_items.end());
        items.insert(active_items.begin(), active_items.end());

        return items;
}

std::set<std::shared_ptr<TurboHiker::CompetingHiker>> TurboHiker::World::getAllCompetingHikers() const
{
        std::set<std::shared_ptr<TurboHiker::CompetingHiker>> hikers = competing_hikers;
        hikers.insert(player);
        return hikers;
}

const std::shared_ptr<TurboHiker::Player>& TurboHiker::World::getPlayer() const { return player; }

const std::set<std::shared_ptr<TurboHiker::CompetingHiker>>& TurboHiker::World::getCompetingHikers() const
{
        return competing_hikers;
}

const std::set<std::shared_ptr<TurboHiker::StaticEnemy>>& TurboHiker::World::getStaticEnemies() const
{
        return static_enemies;
}

const std::set<std::shared_ptr<TurboHiker::MovingEnemy>>& TurboHiker::World::getMovingEnemies() const
{
        return moving_enemies;
}

const std::set<std::shared_ptr<TurboHiker::PassiveItem>>& TurboHiker::World::getPassiveItems() const
{
        return passive_items;
}

const std::set<std::shared_ptr<TurboHiker::ActiveItem>>& TurboHiker::World::getActiveItems() const
{
        return active_items;
}

const std::shared_ptr<TurboHiker::FinishLine>& TurboHiker::World::getFinishLine() const { return finish_line; }

const std::set<std::shared_ptr<TurboHiker::GroundPlot>>& TurboHiker::World::getGround() const { return ground; }

const std::set<std::shared_ptr<TurboHiker::Bomb>>& TurboHiker::World::getBombs() const { return bombs; }

void TurboHiker::World::buildWorld() {}

void TurboHiker::World::checkToDestroyEntities()
{
        if (player->getPosition().getY() >= getSize().second)
                player->notifyObservers(ObserverEvent::FINISHED);
        for (const auto& competitor : competing_hikers)
                if (competitor->getPosition().getY() >= getSize().second)
                        competitor->notifyObservers(ObserverEvent::FINISHED);

        for (const auto& enemy : static_enemies) {
                if (enemy->getPosition().getX() > 4 || enemy->getPosition().getX() < -4)
                        static_enemies.erase(enemy);
        }

        for (const auto& enemy : moving_enemies) {
                if (enemy->getPosition().getY() < 0)
                        moving_enemies.erase(enemy);
        }

        for (const auto& item : passive_items) {
                if (item->isRewardGiven())
                        passive_items.erase(item);
        }

        for (const auto& item : active_items) {
                if (item->isRewardGiven())
                        active_items.erase(item);
        }
}

void TurboHiker::World::spawnMovingEnemy(unsigned int lane, double y_pos, double speedFactor) {}

void TurboHiker::World::spawnStaticEnemy(unsigned int lane, double y_pos) {}

void TurboHiker::World::spawnBomb() {}

void TurboHiker::World::chanceToSpawnBomb()
{
        if (player->getPosition().getY() > getSize().second - 12)
                return;
        int randomChance = Random::getInstance().randomInt(0, 1001);
        if (randomChance < 4)
                spawnBomb();
}

const std::shared_ptr<TurboHiker::AbstractFactory>& TurboHiker::World::getFactory() const { return factory; }

void TurboHiker::World::controlCompetingHikers()
{
        for (auto& competingHiker : competing_hikers) {
                bool is_on_side_lane = competingHiker->getLane() == 0 || competingHiker->getLane() == 3;
                int random1 = Random::getInstance().randomInt(0, 2);
                int randomLaneChange = Random::getInstance().randomInt(0, 1001);
                if (is_on_side_lane)
                        randomLaneChange = Random::getInstance().randomInt(0, 1002);
                int randomSpeedUp = Random::getInstance().randomInt(0, 101);

                if (randomLaneChange >= 999) {
                        if (random1 == 0)
                                competingHiker->moveRight();
                        else
                                competingHiker->moveLeft();
                }
                if (randomSpeedUp >= 50)
                        competingHiker->runAtTurboSpeed();
                else if (randomSpeedUp == 0)
                        competingHiker->stopRunningAtTurboSpeed();
                if (!competingHiker->rewardsEmpty()) {
                        competingHiker->useActiveReward();
                }
        }
}

void TurboHiker::World::controlHikerAtCollision(const std::shared_ptr<CompetingHiker>& competingHiker)
{
        if (competingHiker == player)
                return;
        int dodge = Random::getInstance().randomInt(0, 101);
        if (dodge > 70)
                return;

        bool is_on_side_lane = competingHiker->getLane() == 0 || competingHiker->getLane() == 3;
        if (!is_on_side_lane) {
                int random = Random::getInstance().randomInt(0, 2);
                if (random == 0)
                        competingHiker->moveRight();
                else
                        competingHiker->moveLeft();
        } else if (competingHiker->getLane() == 0)
                competingHiker->moveRight();
        else
                competingHiker->moveLeft();
}
