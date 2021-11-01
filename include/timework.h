#ifndef TIMEWORK_H
#define TIMEWORK_H

#include <chrono>
#include <iostream>
#include <iomanip>

class Timework {
public:
    using Clock = std::chrono::steady_clock;
    Timework() = default;
    void GetTime(std::ostream& out) const;
    ~Timework() = default;
private:
    const Clock::time_point start_time_ = Clock::now();
};

#endif // TIMEWORK_H
