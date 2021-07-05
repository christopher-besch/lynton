#include "timer.h"

#include "pch.h"

namespace Lynton {

Timer::Timer()
    : m_start_stamp(SDL_GetPerformanceCounter()), m_paused_stamp(0), m_paused_time(0.0), m_started(true), m_paused(false) {}

void Timer::reset()
{
    m_started = true;
    m_paused  = false;

    m_start_stamp  = SDL_GetPerformanceCounter();
    m_paused_stamp = 0;
    m_paused_time  = 0.0;
}

void Timer::stop()
{
    m_started = false;
    m_paused  = false;

    m_start_stamp  = 0;
    m_paused_stamp = 0;
    m_paused_time  = 0.0;
}

void Timer::pause()
{
    if(m_started && !m_paused) {
        m_paused       = true;
        m_paused_stamp = SDL_GetPerformanceCounter();
    }
}

void Timer::unpause()
{
    if(m_started && m_paused) {
        m_paused = false;
        m_paused_time += over_frequency(SDL_GetPerformanceCounter() - m_paused_stamp);
    }
}

double Timer::get_time()
{
    double time = 0.0;
    if(m_started) {
        // add all ticks <- either till now or till last pause
        time += m_paused ? over_frequency(m_paused_stamp - m_start_stamp) : over_frequency(SDL_GetPerformanceCounter() - m_start_stamp);
        // removed paused ones
        time -= m_paused_time;
    }
    return time;
}

double Timer::over_frequency(uint64_t stamp)
{
    return stamp / static_cast<double>(SDL_GetPerformanceFrequency());
}

} // namespace Lynton
