#ifndef TURBOHIKER_HIKER_H
#define TURBOHIKER_HIKER_H

#include "Entity.h"
#include <cmath>
#include <vector>

namespace TurboHiker{

class Hiker : public Entity {
public:
    enum Acceleration {NONE, SPEED_UP, SLOW_DOWN};
    enum Movement {STANDARD, MOVING_LEFT, MOVING_RIGHT};

private:
    double speed;
    double speedUpFactor;
    Acceleration acceleration;
    Movement movement;
    std::vector<double> lanePositionsX;


public:

    Hiker(unsigned int lane, std::pair<double, double> &size, std::vector<double>& lanePositionsX, double speed,
          double speedUpFactor);

    ~Hiker() override = default;


    void update() override;

    virtual void speedUp();

    virtual void slowDown();

    void setYposition(double y);

    Movement getMovement() const;

    void setMovement(Movement _movement);

    Acceleration getAcceleration() const;

    void setAcceleration(Acceleration _acceleration);

    double getSpeed() const;

    void setSpeed(double _speed);

    double getSpeedUpFactor() const;

};
}
#endif //TURBOHIKER_HIKER_H
