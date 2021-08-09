
#include "Clock.h"

Clock::Clock() {
    start = std::chrono::steady_clock::now();
    elapsed = start;
    tickTime = 50;
}

Clock &Clock::getInstance() {
    static Clock instance;
    return instance;
}

bool Clock::clockTicked() {
    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(now - elapsed).count() >= tickTime){
        elapsed = now;
        return true;
    }
    return false;
}



