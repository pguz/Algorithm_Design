#pragma once

#include <chrono>
#include <ctime>

class TimeElapsedGuard {
public:
    TimeElapsedGuard(long long& p_microseconds) :   
        microseconds(p_microseconds),
        start(std::chrono::high_resolution_clock::now()) {
    }
    ~TimeElapsedGuard() {
        const auto& elapsed = chrono::high_resolution_clock::now() - start;
        microseconds = chrono::duration_cast<chrono::microseconds>(elapsed).count();
    }
private:
    long long& microseconds;
    const chrono::high_resolution_clock::time_point start;
};
