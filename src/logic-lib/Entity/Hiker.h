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
    /**
     * Simple constructor
     * @param lane: the initial lane where the Hiker is located
     * @param size: the size of the hiker
     * @param lanePositionsX: all possible lane x-coordinates
     * @param speed: the initial speed of the hiker
     * @param speedUpFactor: the factor by which the speed can change
     */
    Hiker(unsigned int lane, std::pair<double, double> &size, std::vector<double>& lanePositionsX, double speed,
          double speedUpFactor);

    /**
     * default copy constructor
     */
    Hiker(const Hiker&) = default;

    /**
     * default destructor
     */
    ~Hiker() override = default;

    /**
     * virtual function that updates all hikers
     */
    void update() override;

    /**
     * increases the speed of the Hiker
     */
    virtual void speedUp();

    /**
     * decreases the speed of the Hiker
     */
    virtual void slowDown();

    /**
     * Sets the y-coordinate of the Hiker position to a new y-coordinate
     * @param y: the new y-coordinate
     */
    void setYposition(double y);

    /**
     * Simple getter of the movement
     * @return the movement of the hiker
     */
    Movement getMovement() const;

    /**
     * Simple setter of the Hiker movement
     * @param _movement: the new movement
     */
    void setMovement(Movement _movement);

    /**
     * Simple getter of the acceleration
     * @return: the current state of the Hiker acceleration
     */
    Acceleration getAcceleration() const;

    /**
     * Simple setter of the Hiker acceleration state
     * @param _acceleration: the new acceleration state
     */
    void setAcceleration(Acceleration _acceleration);

    /**
     * Simple getter of the Hiker speed
     * @return: the current speed
     */
    double getSpeed() const;

    /**
     * Simple setter of the Hiker speed
     * @param _speed: the new speed
     */
    void setSpeed(double _speed);

    /**
     * simple getter of the speed_up_factor
     * @return the speed_up_factor
     */
    double getSpeedUpFactor() const;

};
}
#endif //TURBOHIKER_HIKER_H
