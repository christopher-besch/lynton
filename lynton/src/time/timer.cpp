#include "timer.h"

#include "pch.h"

namespace Lynton {

Timer::Timer()
    : m_start_stamp(SDL_GetTicks()), m_paused_stamp(0), m_paused_ticks(0), m_started(true), m_paused(false) {}

void Timer::reset()
{
    m_started = true;
    m_paused  = false;

    m_start_stamp  = SDL_GetTicks();
    m_paused_stamp = 0;
    m_paused_ticks = 0;
}

void Timer::stop()
{
    m_started = false;
    m_paused  = false;

    m_start_stamp  = 0;
    m_paused_stamp = 0;
    m_paused_ticks = 0;
}

void Timer::pause()
{
    if(m_started && !m_paused) {
        m_paused       = true;
        m_paused_stamp = SDL_GetTicks();
    }
}

void Timer::unpause()
{
    if(m_started && m_paused) {
        m_paused = false;
        m_paused_ticks += SDL_GetTicks() - m_paused_stamp;
    }
}

uint32_t Timer::get_ticks()
{
    uint8_t ticks = 0;
    if(m_started) {
        // add all ticks <- either till now or till last pause
        ticks += m_paused ? m_paused_stamp - m_start_stamp : SDL_GetTicks() - m_start_stamp;
        // removed paused ones
        ticks -= m_paused_ticks;
    }
    return ticks;
}

} // namespace Lynton
