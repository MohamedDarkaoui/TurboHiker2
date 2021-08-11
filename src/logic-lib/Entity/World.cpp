#include "World.h"
#include <iostream>

#include "../../presentation-lib/EntityFactory/EntityFactory.h"
void World::update() {

    // make one big set with all entities
    auto entities = getEntities();

    //update all entities
    for (auto& entity : entities){
        entity->update();
    }
    handleEvents();
}



void World::createCompetingHikers() {
    auto* factory = new EntityFactory ("../../game_configurations.ini");

    addPlayer(factory->createPlayer());
    addCompetingHikers(factory->createCompetingHikers(player->getLane()));
    addEnemies(factory->createStaticEnemies());
}

void World::addPlayer(const std::shared_ptr<Player>& p) {
    player = p;
}

void World::addCompetingHikers(const std::set<std::shared_ptr<CompetingHiker>>& competing) {
    competing_hikers.insert(competing.begin(), competing.end());
}

void World::addEnemies(const std::set<std::shared_ptr<Enemy>>& e) {
    enemies.insert(e.begin(),e.end());
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
                double colliding_distance = (hiker1->getSize()+hiker2->getSize())/2;
                if (std::abs(y1-y2) < colliding_distance) {
                    if (y1 < y2)
                        hiker1->collide();
                    else
                        hiker2->collide();
                }
            }
        }
    }
}

void World::handleHikerEnemyCollisions() {
    std::set<std::shared_ptr<CompetingHiker>> hikers = competing_hikers;
    hikers.insert(player);

    for (auto& hiker : hikers){
        for (auto& enemy : enemies){
            if (hiker->getLane() == enemy->getLane()){
                double y1 = hiker->getPosition().getY();
                double y2 = enemy->getPosition().getY();
                double collision_distance = (hiker->getSize() + enemy->getSize())/2;
                if (std::abs(y1-y2) < collision_distance)
                    hiker->collide();
            }
        }
    }
}

void World::handleYelling() {
    if (player->isYelling()){
        for (auto& enemy : enemies){
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

std::set<std::shared_ptr<Entity>> World::getEntities() {
    std::set<std::shared_ptr<Entity>> entities;
    entities.insert(competing_hikers.begin(), competing_hikers.end());
    entities.insert(enemies.begin(), enemies.end());
    entities.insert(player);

    return entities;
}


const std::shared_ptr<Player> &World::getPlayer() const {
    return player;
}

const std::set<std::shared_ptr<CompetingHiker>> &World::getCompetingHikers() const {
    return competing_hikers;
}

const std::set<std::shared_ptr<Enemy>> &World::getEnemies() const {
    return enemies;
}











