#include "Bomb.h"

TurboHiker::Bomb::Bomb(Position2D position, std::pair<double, double> &size, double speed) : Entity(position, size),
        speed(speed){}

void TurboHiker::Bomb::update() {
    position += {speed,0};
}
