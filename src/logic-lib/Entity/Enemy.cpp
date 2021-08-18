#include "Enemy.h"

TurboHiker::Enemy::Enemy(unsigned int lane, std::pair<double, double> &size, std::vector<double> &lanePositionsX,
                  double speed, double speedUpFactor): Hiker(lane, size, lanePositionsX, speed,speedUpFactor) {}
