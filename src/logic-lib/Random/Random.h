#ifndef TURBOHIKER_RANDOM_H
#define TURBOHIKER_RANDOM_H

#include <random>

namespace TurboHiker{

class Random {
private:
    //initializing the engine with a random device
    std::random_device rd;
    std::mt19937 engine{rd()};

    Random() = default;
public:
    //making sure the instance can not be copied
    Random(Random const&) = delete;
    void operator=(Random const&) = delete;

    static Random& getInstance();

    double random(double min, double max);

    int randomInt(int min, int max);
};
}

#endif //TURBOHIKER_RANDOM_H
