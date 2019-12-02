/*
** EPITECH PROJECT, 2019
** BigUtilityBox
** File description:
** Profiler.hpp
*/

#pragma once

#include <chrono>

namespace bub {
    using namespace std::chrono_literals;

    class Profiler {
    public:
        using Clock = std::chrono::high_resolution_clock;
        using TimePoint = decltype(Clock::now());
        using DurationSeconds = std::chrono::duration<double>;
        using DurationMillis = std::chrono::duration<double, std::milli>;
    private:
        const TimePoint _start;
        const char *const _name;
    public:
        explicit Profiler(const char *name) noexcept;
        ~Profiler();

        Profiler(Profiler &&) = default;
        Profiler(const Profiler &) = default;

        Profiler &operator=(Profiler &&) = delete;
        Profiler &operator=(const Profiler &) = delete;
    };
}
