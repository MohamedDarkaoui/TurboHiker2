#ifndef TURBOHIKER_ENTITY_H
#define TURBOHIKER_ENTITY_H

#include <memory>
#include <vector>
#include <cassert>
#include "../Position/Position2D.h"
#include "../Random/Random.h"

namespace TurboHiker{

class Entity {

private:
    std::pair<double,double> size;
    unsigned int lane;
    std::vector<double> lanePositionsX;

protected:
    Position2D position;

public:

    /**
     * Simple constructor
     * @param lane: the lane number of the entity
     * @param size: the size of the entity
     * @param lanePositionsX: all the possible lane x-coordinates where the entity can be located
     */
    Entity(unsigned int lane, std::pair<double,double>& size, std::vector<double>& lanePositionsX);

    /**
     * SIMPLE constructor
     * @param position: the position where the entity spawns
     * @param size: the size of the entity
     */
    Entity(Position2D position, std::pair<double,double>& size);

    /**
     * Default copy constructor
     * @param other: the to-be-copied entity
     */
    Entity(const Entity& other) = default;

    /**
     * Default virtual destructor
     */
    virtual ~Entity() = default;

    /**
     * Simple getter of the position
     * @return: the current position of the entity
     */
    const Position2D &getPosition() const;

    /**
     * Simple getter of the entity size
     * @return the size of the entity
     */
    const std::pair<double, double> &getSize() const;

    /**
     * Simple getter of the entity lane
     * @return the lane of the entity
     */
    unsigned int getLane() const;

    /**
     * Simple setter of the lane
     * @param _lane: the new lane
     */
    void setLane(unsigned int _lane);

    /**
     * Simple setter of the position
     * @param pos: the new position
     */
    void setPosition(const Position2D &pos);

    /**
     * simple getter of the LanePositionsX
     * @return LanePositionsX
     */
    const std::vector<double> &getLanePositionsX() const;

    /**
     * Calculates the relative position with respect to a reference position
     * @param reference: the reference position
     * @return the relative position
     */
    Position2D getRelativePosition(const Position2D &reference) const;

    /**
     * Updates the entity
     */
    virtual void update() = 0;

    /**
     * virtual function that is implemented in subclasses to update visuals
     * @param relativePos: the relative position of the entity with respect to another position
     * @param size: the size of the entity
     */
    virtual void updateVisuals(const Position2D& relativePos, std::pair<double,double> size);

};

}
#endif //TURBOHIKER_ENTITY_H
