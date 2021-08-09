#ifndef TURBOHIKER_EVENTHANDLER_H
#define TURBOHIKER_EVENTHANDLER_H

#include <set>
#include "../Entity/Player.h"
#include "../Entity/StaticEnemy.h"
#include "../Entity/MovingEnemy.h"

class EventHandler {
private:
    std::shared_ptr<Player> player;
    std::vector<std::shared_ptr<CompetingHiker>> competing_hikers;
    std::vector<std::shared_ptr<Enemy>> enemy_hikers;

public:
    void handleHikerCollisions();

    void handleHikerEnemyCollisions();

    void handleYelling();

    void handleEvents();

    void addPlayer(const std::shared_ptr<Player>& pl);

    void addCompetingHiker(const std::shared_ptr<CompetingHiker>& competingHiker);

    void addEnemyHiker(const std::shared_ptr<Enemy>& enemy);

    std::vector<std::shared_ptr<CompetingHiker>> getCompeting();

};


#endif //TURBOHIKER_EVENTHANDLER_H
