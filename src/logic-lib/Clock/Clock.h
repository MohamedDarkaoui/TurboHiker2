#ifndef TURBOHIKER_CLOCK_H
#define TURBOHIKER_CLOCK_H

#include <chrono>

class Clock {
private:
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point elapsed;
    unsigned int tickTime = 0;

public:
    Clock() = default;

    explicit Clock(unsigned int tickTime);

    bool clockTicked();

    void setTickTime(unsigned int time);

    unsigned int getElapsedTime();

    void reset();
};


#endif //TURBOHIKER_CLOCK_H
