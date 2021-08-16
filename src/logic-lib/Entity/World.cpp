#include "World.h"
#include <iostream>

World::World(Position2D position, std::pair<double, double> &size) : Entity(position, size) {}

void World::update() {

    trackPlayer();
    // make one big set with all entities
    auto entities = getEntities();

    //update all entities
    for (auto& entity : entities){
        entity->update();
    }
    handleEvents();
    checkToDestroyEntities();
}

void World::addPlayer(const std::shared_ptr<Player>& p) {
    player = p;
}

void World::addCompetingHiker(const std::shared_ptr<CompetingHiker>& competing) {
    competing_hikers.insert(competing);
}

void World::addStaticEnemy(const std::shared_ptr<StaticEnemy>& static_enemy) {
    static_enemies.insert(static_enemy);
}

void World::addMovingEnemy(const std::shared_ptr<MovingEnemy> &moving_enemy) {
    moving_enemies.insert(moving_enemy);
}

void World::addGRoundPlot(const std::shared_ptr<GroundPlot> &groundPlot) {
    ground.insert(groundPlot);
}

void World::addFinishLine(const std::shared_ptr<FinishLine>& finishLine){
    finish_line = finishLine;
}

void World::handleHikerCollisions() {
    std::set<std::shared_ptr<CompetingHiker>> hikers = competing_hikers;
    hikers.insert(player);

    for (auto& hiker1 : hikers) {
        for (auto& hiker2 : hikers){
            if (hiker1 == hiker2)
                continue;
            if (hiker1->getLane() == hiker2->getLane()){
                double y1 = hiker1->getPosition().getY();
                double y2 = hiker2->getPosition().getY();
                double colliding_distance = (hiker1->getSize().second + (hiker2->getSize()).second)/4;
                if (std::abs(y1-y2) < colliding_distance && !hiker2->isColliding()) {
                    if (y1 <= y2){
                        hiker1->collide();
                        hiker1->notifyObservers(ObserverEvent::COMPETING_HIKER_COLLISION);
                    }
                    else{
                        hiker2->collide();
                        hiker2->notifyObservers(ObserverEvent::COMPETING_HIKER_COLLISION);
                    }
                }
            }
        }
    }
}

void World::handleHikerEnemyCollisions() {
    std::set<std::shared_ptr<CompetingHiker>> hikers = competing_hikers;
    hikers.insert(player);

    for (auto& hiker : hikers){
        for (auto& enemy : getEnemies()){
            if (hiker->getLane() == enemy->getLane()){
                double y1 = hiker->getPosition().getY();
                double y2 = enemy->getPosition().getY();
                double collision_distance = (hiker->getSize().second + (enemy->getSize()).second)/4;
                if (std::abs(y1-y2) < collision_distance){
                    hiker->collide();
                    hiker->notifyObservers(ObserverEvent::ENEMY_COLLISION);
                }
            }
        }
    }
}

void World::handleYelling() {
    if (player->isYelling()){
        for (auto& enemy : getEnemies()){
            if (enemy->getLane() == player->getLane()){
                double enemy_y = enemy->getPosition().getY();
                double player_y = player->getPosition().getY();
                double range = player->getYellingRange();

                if (enemy_y > player_y && enemy_y < player_y + range){
                    enemy->gotYelledAt();
                }
            }
        }
    }
}

void World::handleEvents() {
    handleHikerCollisions();
    handleHikerEnemyCollisions();
    handleYelling();
}

void World::trackPlayer() {
    if (player->getAcceleration() == Hiker::SLOW_DOWN){
        position += {0, player->getSpeed()*player->getSpeedUpFactor()*2};
        if (position.getY() - player->getPosition().getY() >= 0.5)
            player->speedUp();
    }
    else if (player->getAcceleration() == Hiker::SPEED_UP){
        position += {0, player->getSpeed()/player->getSpeedUpFactor()};
        if (player->getPosition().getY() - position.getY()  >= 4.5)
            player->slowDown();
    }
    else
        position += {0, player->getSpeed()};
}

std::set<std::shared_ptr<Entity>> World::getEntities() const{
    std::set<std::shared_ptr<Entity>> entities;
    entities.insert(ground.begin(), ground.end());
    entities.insert(competing_hikers.begin(), competing_hikers.end());
    entities.insert(static_enemies.begin(), static_enemies.end());
    entities.insert(moving_enemies.begin(), moving_enemies.end());
    entities.insert(finish_line);
    entities.insert(player);

    return entities;
}

std::set<std::shared_ptr<Enemy>> World::getEnemies() const {
    std::set<std::shared_ptr<Enemy>> enemies;
    enemies.insert(static_enemies.begin(), static_enemies.end());
    enemies.insert(moving_enemies.begin(), moving_enemies.end());

    return enemies;
}

const std::shared_ptr<Player> &World::getPlayer() const {
    return player;
}

const std::set<std::shared_ptr<CompetingHiker>> &World::getCompetingHikers() const {
    return competing_hikers;
}

const std::set<std::shared_ptr<StaticEnemy>> &World::getStaticEnemies() const {
    return static_enemies;
}

const std::set<std::shared_ptr<MovingEnemy>> &World::getMovingEnemies() const {
    return moving_enemies;
}

const std::shared_ptr<FinishLine> &World::getFinishLine() const {
    return finish_line;
}

void World::buildWorld(const std::shared_ptr<AbstractFactory>& factory) {}

const std::set<std::shared_ptr<GroundPlot>> &World::getGround() const {
    return ground;
}

void World::checkToDestroyEntities() {
    if (player->getPosition().getY() > getSize().second)
        player->setSpeed(0);

    for (const auto& hiker : competing_hikers){
        if (hiker->getPosition().getY() > getSize().second)
            competing_hikers.erase(hiker);
    }
    for (const auto& enemy : static_enemies){
        if (enemy->getPosition().getX() > 4 || enemy->getPosition().getX() < -4)
            static_enemies.erase(enemy);
    }
    for (const auto& enemy : moving_enemies){
        if (enemy->getPosition().getY() < 0)
            moving_enemies.erase(enemy);
    }
}


