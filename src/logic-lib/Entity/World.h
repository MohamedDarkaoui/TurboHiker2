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

class World : public Entity {
private:
    std::set<std::shared_ptr<Hiker>> hikers;
    std::vector<double> lane_positions;
    //double lane_positions[4];

public:
    explicit World(std::vector<double> lanePositions) : lane_positions(std::move(lanePositions)) {};

    void update() override;

    void addHiker(const std::shared_ptr<Hiker>& hiker);

};

#endif //TURBOHIKER_WORLD_H
