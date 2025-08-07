#pragma once
#include <chrono>

class timer
{
    typedef std::chrono::high_resolution_clock clock;
    typedef clock::time_point point;
    typedef clock::duration duration;
public:
    timer():is_start(0),how_long(std::chrono::milliseconds(0)) {};
    int start();
    int stop();
    long long get_milliseconds();
    long long get_seconds();
protected:
    point start_time;
    duration how_long;
    bool is_start;
};
long long to_minutes(long long seconds);
