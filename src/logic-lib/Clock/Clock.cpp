
#include "Clock.h"

Clock::Clock(unsigned int tickTime) {
    start = std::chrono::steady_clock::now();
    elapsed = start;
    this->tickTime = tickTime;
}


bool Clock::clockTicked() {
    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(now - elapsed).count() >= tickTime){
        elapsed = now;
        return true;
    }
    return false;
}

unsigned int Clock::getElapsedTime() {
    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count();
}

void Clock::setTickTime(unsigned int time) {
    Clock::tickTime = time;
}

void Clock::reset() {
    start = std::chrono::steady_clock::now();
    elapsed = start;
}




