#ifndef TURBOHIKER_CLOCK_H
#define TURBOHIKER_CLOCK_H

#include <chrono>

class Clock {
private:
    Clock();

    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point elapsed;
    int tickTime;

public:
    Clock(Clock const&) = delete;
    void operator=(Clock const&) = delete;

    static Clock& getInstance();

    bool clockTicked();
};


#endif //TURBOHIKER_CLOCK_H
