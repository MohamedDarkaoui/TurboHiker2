
#include "Random.h"


TurboHiker::Random &TurboHiker::Random::getInstance() {
    static Random instance;
    return instance;
}

double TurboHiker::Random::random(double min, double max) {
    std::uniform_real_distribution<> val(min, max);

    return val(engine);
}

int TurboHiker::Random::randomInt(int min, int max) {
    return std::floor(random(min,max));
}






