#pragma once

#include "stdint.h"

namespace Lynton {
class Timer {
public:
    // automatically start on construction
    Timer();

    // start timer again
    void reset();
    void stop();

    void pause();
    void unpause();

    double get_time();

    bool is_started() { return m_started; }
    bool is_paused() { return m_paused; }

private:
    double over_frequency(uint64_t stamp);

private:
    // moment started/stopped
    uint64_t m_start_stamp;
    uint64_t m_paused_stamp;
    // that much time was paused
    long m_paused_time;
    bool m_started;
    bool m_paused;
};
} // namespace Lynton
