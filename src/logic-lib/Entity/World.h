#ifndef TURBOHIKER_WORLD_H
#define TURBOHIKER_WORLD_H

#include <set>
#include "Entity.h"
#include "Hiker.h"
#include "Enemy.h"
#include "../EventHandler/EventHandler.h"

class World : public Entity, public EventHandler {

private:
    std::set<std::shared_ptr<Entity>> entities;

public:
    explicit World() = default;

    ~World() override = default;

    void update() override;

    void addEntity(const std::shared_ptr<Entity>& entity);

    void createCompetingHikers();

};

#endif //TURBOHIKER_WORLD_H
