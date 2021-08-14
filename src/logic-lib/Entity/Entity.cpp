#include "Entity.h"

Entity::Entity(unsigned int lane, std::pair<double, double> &size, std::vector<double>& lanePositionsX) {
    this->position = {0,0};
    this->position.setX(lanePositionsX[lane]);
    this->lane = lane;
    this->size = size;
    this->lanePositionsX = lanePositionsX;
}

Entity::Entity(Position2D position, std::pair<double, double> &size) : size(size), position(position){
    lane = 100;
    lanePositionsX = {};
}

const Position2D &Entity::getPosition() const {
    return position;
}

Position2D Entity::getRelativePosition(const Position2D &reference) const {
    return {position.getX(), position.getY() - reference.getY() -2};
}

const std::pair<double, double> &Entity::getSize() const {
    return size;
}

unsigned int Entity::getLane() const {
    return lane;
}

const std::vector<double> &Entity::getLanePositionsX() const {
    return lanePositionsX;
}

void Entity::setLane(unsigned int lane) {
    Entity::lane = lane;
}

void Entity::updateVisuals(const Position2D& reference) {}







