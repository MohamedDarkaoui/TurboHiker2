#include "StaticEnemy.h"

void StaticEnemy::runAway() {
    this->position -= {0.1,0};
    this->state = MOVING_LEFT;
}
