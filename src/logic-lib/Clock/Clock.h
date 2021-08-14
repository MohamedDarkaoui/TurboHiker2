#ifndef TURBOHIKER_CLOCK_H
#define TURBOHIKER_CLOCK_H

#include <chrono>

class Clock {
private:
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point elapsed;
    unsigned int tickTime;

public:
    Clock(unsigned int tickTime);
//    Clock(Clock const&) = delete;
//    void operator=(Clock const&) = delete;

//    static Clock& getInstance();

    bool clockTicked();

    void setTickTime(unsigned int tickTime);

    unsigned int getElapsedTime();
};


#endif //TURBOHIKER_CLOCK_H
