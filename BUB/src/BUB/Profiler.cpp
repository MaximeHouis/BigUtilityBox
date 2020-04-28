/*
** BigUtilityBox Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include <iostream>

#include "BUB/Profiler.hpp"

bub::Profiler::Profiler(const char *name) noexcept
        : _start{Clock::now()}, _name{name}
{
}

bub::Profiler::~Profiler()
{
    const auto end = Clock::now();
    auto &stream = std::cerr;
    const DurationSeconds durationSeconds = end - _start;
    const DurationMillis durationMillis = durationSeconds;

    stream << _name << ": ";
    if (durationSeconds.count() >= 1)
        stream << durationSeconds.count() << "s";
    else
        stream << durationMillis.count() << "ms";
    stream << std::endl;
}
