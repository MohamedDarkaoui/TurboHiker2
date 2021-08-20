#include "Entity.h"

TurboHiker::Entity::Entity(unsigned int lane, std::pair<double, double>& size, std::vector<double>& lanePositionsX)
{
        this->position = {0, 0};
        this->position.setX(lanePositionsX[lane]);
        this->lane = lane;
        this->size = size;
        this->lanePositionsX = lanePositionsX;
}

TurboHiker::Entity::Entity(Position2D position, std::pair<double, double>& size) : size(size), position(position)
{
        lane = 100;
        lanePositionsX = {};
}

const TurboHiker::Position2D& TurboHiker::Entity::getPosition() const { return position; }

TurboHiker::Position2D TurboHiker::Entity::getRelativePosition(const Position2D& reference) const
{
        return {position.getX(), position.getY() - reference.getY() - 2};
}

const std::pair<double, double>& TurboHiker::Entity::getSize() const { return size; }

unsigned int TurboHiker::Entity::getLane() const { return lane; }

const std::vector<double>& TurboHiker::Entity::getLanePositionsX() const { return lanePositionsX; }

void TurboHiker::Entity::setLane(unsigned int _lane) { TurboHiker::Entity::lane = _lane; }

void TurboHiker::Entity::setPosition(const Position2D& pos) { TurboHiker::Entity::position = pos; }

void TurboHiker::Entity::updateVisuals(const Position2D& relativePos, std::pair<double, double> _size) {}
