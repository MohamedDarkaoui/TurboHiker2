#ifndef TURBOHIKER_CLOCK_H
#define TURBOHIKER_CLOCK_H

#include <chrono>
namespace TurboHiker {
class Clock {
private:
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point elapsed;
    unsigned int tickTime = 0;

public:
    /**
     * simple constructor
     * @param tickTime: the time of each tick
     */
    explicit Clock(unsigned int tickTime);

    /**
     * default constructor
     */
    Clock() = default;

    /**
     * checks if the clock has ticked
     * @return true if the clock has ticked, false otherwise
     */
    bool clockTicked();

    /**
     * simple setter of tick_time
     * @param time: the new tick_time
     */
    void setTickTime(unsigned int time);
};
}

#endif //TURBOHIKER_CLOCK_H
