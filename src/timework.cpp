#include "timework.h"

void Timework::GetTime(std::ostream& out) const {
    using namespace std::chrono;
    using namespace std::literals;

    const auto end_time = Clock::now();
    auto ms = duration_cast<milliseconds>(end_time - start_time_);

    auto secs = duration_cast<seconds>(ms);
    ms -= duration_cast<milliseconds>(secs);
    auto mins = duration_cast<minutes>(secs);
    secs -= duration_cast<seconds>(mins);
    auto hour = duration_cast<hours>(mins);
    mins -= duration_cast<minutes>(hour);

    out << std::setfill('0') << std::setw(2) << hour.count() <<":"s;
    out << std::setfill('0') << std::setw(2) << mins.count() <<":"s;
    out << std::setfill('0') << std::setw(2) << secs.count();
}
