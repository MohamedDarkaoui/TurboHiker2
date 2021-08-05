#ifndef TURBOHIKER_WORLD_H
#define TURBOHIKER_WORLD_H

#include <list>
#include <tuple>
#include <set>
#include "Entity.h"
#include "Hiker.h"

class World : public Entity {
private:
    std::list<std::unique_ptr<Hiker>> hikers;
    std::set<double> lane_positions;

public:
    void update() override;
};

#endif //TURBOHIKER_WORLD_H
