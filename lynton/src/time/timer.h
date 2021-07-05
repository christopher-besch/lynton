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

    uint32_t get_ticks();

    bool is_started() { return m_started; }
    bool is_paused() { return m_paused; }

private:
    // moment started/stopped
    uint32_t m_start_stamp;
    uint32_t m_paused_stamp;
    // that many ticks were paused
    uint32_t m_paused_ticks;
    bool     m_started;
    bool     m_paused;
};
} // namespace Lynton
