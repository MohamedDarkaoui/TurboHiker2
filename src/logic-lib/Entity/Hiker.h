#ifndef TURBOHIKER_HIKER_H
#define TURBOHIKER_HIKER_H

#include "Entity.h"
#include <cmath>

class Hiker : public Entity {
public:
    enum Movement {STANDARD, MOVING_LEFT, MOVING_RIGHT};
    enum Acceleration {NONE, SPEED_UP, SLOW_DOWN};

private:
    Position2D position;
    int lane;
    double speed;
    bool sprinting; // run faster
    Movement movement;
    Acceleration acceleration;


public:

    Hiker(Position2D position,int lane, double speed, bool sprinting, Movement movement, Acceleration acceleration);

    const Position2D &getPosition() const;

    Movement getMovement() const;

    void setPosition(const Position2D &position);

    int getLane() const;

    void update() override;

    void sprint();

    void stopSprinting();

    void speedUp();

    void slowDown();

    void normalSpeed();

    void moveLeft();

    void moveRight();

    void moveStraight();

    Position2D getRelativePosition(const Position2D& reference) const;

};

#endif //TURBOHIKER_HIKER_H
