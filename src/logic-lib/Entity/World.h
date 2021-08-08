#ifndef TURBOHIKER_WORLD_H
#define TURBOHIKER_WORLD_H

#include <list>
#include <tuple>
#include <set>
#include <utility>
#include <vector>
#include <utility>
#include "Entity.h"
#include "Hiker.h"
#include "Enemy.h"

class World : public Entity {
private:
    std::set<std::shared_ptr<Entity>> entities;

public:
    explicit World() = default;

    ~World() override = default;

    void update() override;

    void addEntity(const std::shared_ptr<Entity>& entity);



};

#endif //TURBOHIKER_WORLD_H
