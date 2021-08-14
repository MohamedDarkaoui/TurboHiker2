#ifndef TURBOHIKER_ENTITY_H
#define TURBOHIKER_ENTITY_H

#include <memory>
#include <vector>
#include <cassert>
#include "../Position/Position2D.h"
#include "../Random/Random.h"

class Entity {

private:
    std::pair<double,double> size;
    unsigned int lane;
    std::vector<double> lanePositionsX;

protected:
    Position2D position;

public:
    Entity(unsigned int lane, std::pair<double,double>& size, std::vector<double>& lanePositionsX);

    Entity(Position2D position, std::pair<double,double>& size);

    virtual ~Entity() = default;

    const Position2D &getPosition() const;

    virtual void update() = 0;

    Position2D getRelativePosition(const Position2D &reference) const;

    const std::pair<double, double> &getSize() const;

    unsigned int getLane() const;

    void setLane(unsigned int lane);

    const std::vector<double> &getLanePositionsX() const;

    virtual void updateVisuals(const Position2D& reference);

};


#endif //TURBOHIKER_ENTITY_H
