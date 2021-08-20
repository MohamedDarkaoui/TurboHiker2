#include "Hiker.h"
#include <cassert>

TurboHiker::Hiker::Hiker(unsigned int lane, std::pair<double, double>& size, std::vector<double>& lanePositionsX,
                         double speed, double speedUpFactor)
    : Entity(lane, size, lanePositionsX), speed(speed), speedUpFactor(speedUpFactor)
{

        assert(position.getX() != 0);
        this->acceleration = TurboHiker::Hiker::NONE;
        this->movement = TurboHiker::Hiker::STANDARD;
}

void TurboHiker::Hiker::update() { position += {0, speed}; }

void TurboHiker::Hiker::speedUp()
{
        assert(speedUpFactor > 1);
        if (acceleration == TurboHiker::Hiker::NONE) {
                acceleration = TurboHiker::Hiker::SPEED_UP;
                speed = speed * speedUpFactor;
        } else if (acceleration == TurboHiker::Hiker::SLOW_DOWN) {
                acceleration = TurboHiker::Hiker::NONE;
                speed = speed * 2 * speedUpFactor;
        }
}

void TurboHiker::Hiker::slowDown()
{
        assert(speedUpFactor > 1);
        if (acceleration == TurboHiker::Hiker::NONE) {
                acceleration = TurboHiker::Hiker::SLOW_DOWN;
                speed /= (2 * speedUpFactor);
        } else if (acceleration == TurboHiker::Hiker::SPEED_UP) {
                acceleration = TurboHiker::Hiker::NONE;
                speed /= speedUpFactor;
        }
}

void TurboHiker::Hiker::setYposition(double y) { position.setY(y); }

TurboHiker::Hiker::Movement TurboHiker::Hiker::getMovement() const { return movement; }

void TurboHiker::Hiker::setMovement(TurboHiker::Hiker::Movement _movement) { TurboHiker::Hiker::movement = _movement; }

TurboHiker::Hiker::Acceleration TurboHiker::Hiker::getAcceleration() const { return acceleration; }

void TurboHiker::Hiker::setAcceleration(TurboHiker::Hiker::Acceleration _acceleration)
{
        TurboHiker::Hiker::acceleration = _acceleration;
}

double TurboHiker::Hiker::getSpeed() const { return speed; }

void TurboHiker::Hiker::setSpeed(double _speed) { TurboHiker::Hiker::speed = _speed; }

double TurboHiker::Hiker::getSpeedUpFactor() const { return speedUpFactor; }
