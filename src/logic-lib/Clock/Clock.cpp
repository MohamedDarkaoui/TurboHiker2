#include "Clock.h"

TurboHiker::Clock::Clock(unsigned int tickTime)
{
        start = std::chrono::steady_clock::now();
        elapsed = start;
        this->tickTime = tickTime;
}

bool TurboHiker::Clock::clockTicked()
{
        std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
        if (std::chrono::duration_cast<std::chrono::milliseconds>(now - elapsed).count() >= tickTime) {
                elapsed = now;
                return true;
        }
        return false;
}

void TurboHiker::Clock::setTickTime(unsigned int time) { Clock::tickTime = time; }