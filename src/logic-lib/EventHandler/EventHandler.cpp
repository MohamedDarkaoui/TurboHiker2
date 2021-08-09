
#include "EventHandler.h"
#include <iostream>


void EventHandler::handleHikerCollisions() {
    std::vector<std::shared_ptr<CompetingHiker>> hikers = competing_hikers;
//    hikers.push_back(player);

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

void EventHandler::handleHikerEnemyCollisions() {
    std::vector<std::shared_ptr<CompetingHiker>> hikers = competing_hikers;
//    hikers.push_back(player);

    for (auto& hiker : hikers){
        for (auto& enemy : enemy_hikers){
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

void EventHandler::handleYelling() {
    if (player->isYelling()){
        for (auto& enemy : enemy_hikers){
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

void EventHandler::handleEvents() {
    handleHikerCollisions();
//    handleHikerEnemyCollisions();
    //handleYelling();
}

void EventHandler::addPlayer(const std::shared_ptr<Player> &pl) {
    this->player = pl;
}

void EventHandler::addCompetingHiker(const std::shared_ptr<CompetingHiker> &competingHiker) {
    for (auto& hiker : competing_hikers){
        assert(hiker != competingHiker);
    }
    competing_hikers.push_back(competingHiker);
}

void EventHandler::addEnemyHiker(const std::shared_ptr<Enemy> &enemy) {
    for (auto& e : enemy_hikers){
        assert(e != enemy);
    }
    enemy_hikers.push_back(enemy);
}

std::vector<std::shared_ptr<CompetingHiker>> EventHandler::getCompeting() {
    return competing_hikers;
}



