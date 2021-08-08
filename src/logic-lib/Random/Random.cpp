
#include "Random.h"


Random &Random::getInstance() {
    static Random instance;
    return instance;
}

double Random::random(double min, double max) {
    std::uniform_real_distribution<> val(min, max);

    return val(engine);
}

int Random::randomInt(int min, int max) {
    return std::floor(random(min,max));
}






