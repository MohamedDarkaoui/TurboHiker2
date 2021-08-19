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
    Random(Random const&) = delete;
    void operator=(Random const&) = delete;

    /**
     * typical singleton getInstance function
     * @return an instance of the Random singleton
     */
    static Random& getInstance();

    /**
     * generates a random double between two given numbers
     * @param min: the lower bound of the number
     * @param max: the upper bound of the number
     * @return the generated random number
     */
    double random(double min, double max);

    /**
     * generates a random int between two given numbers
     * @param min: the lower bound of the int
     * @param max: the upper bound of the int
     * @return the generated random int
     */
    int randomInt(int min, int max);
};
}

#endif //TURBOHIKER_RANDOM_H
