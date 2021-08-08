#ifndef TURBOHIKER_HIKER_H
#define TURBOHIKER_HIKER_H

#include "Entity.h"
#include <cmath>
#include <vector>

class Hiker : public Entity {
public:
    enum Acceleration {NONE, SPEED_UP, SLOW_DOWN};
    enum Movement {STANDARD, MOVING_LEFT, MOVING_RIGHT};

protected:
    double slowDownFactor = 0.75;
    double speedUpFactor = 1.5;
    Position2D position;
    unsigned int lane;
    double speed;
    Movement movement;
    Acceleration acceleration;
    std::vector<double> lanePositionsX;


public:

    Hiker(Position2D position, double speed, std::vector<double>& lanePositionsX);

    ~Hiker() override = default;

    const Position2D &getPosition() const;

    Hiker::Movement getMovement() const;

    unsigned int getLane() const;

    void update() override;

    void speedUp();

    void slowDown();

    void normalSpeed();

    void moveLeft();

    void moveRight();

    void moveStraight();

    Position2D getRelativePosition(const Position2D& reference) const;

};

#endif //TURBOHIKER_HIKER_H
