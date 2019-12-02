/*
** EPITECH PROJECT, 2019
** BigUtilityBox
** File description:
** Profiler.cpp
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
