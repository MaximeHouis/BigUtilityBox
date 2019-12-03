/*
** EPITECH PROJECT, 2019
** BigUtilityBox
** File description:
** Vector2.hpp
*/

#pragma once

#include <cstdint>
#include <cmath>

namespace bub {
    template<typename T>
    struct Vector2 {
        typedef T ValueType;
        typedef Vector2<T> VecType;

        T x;
        T y;

        Vector2() noexcept : x{0}, y{0}
        {}

        Vector2(T x_, T y_) noexcept : x{x_}, y{y_}
        {}

        template<typename U>
        explicit Vector2(const Vector2<U> &rhs) noexcept : x{static_cast<T>(rhs.x)}, y{static_cast<T>(rhs.y)}
        {}

        Vector2(Vector2<T> &&) noexcept = default;
        Vector2(const Vector2<T> &) noexcept = default;
        Vector2 &operator=(Vector2<T> &&) noexcept = default;
        Vector2 &operator=(const Vector2<T> &) noexcept = default;

        ~Vector2() = default;

        T normalize() const noexcept
        {
            if constexpr (std::is_floating_point<T>())
                return static_cast<T>(std::sqrt(x * x + y * y));
            else
                return static_cast<T>(std::round(std::sqrt(x * x + y * y)));
        }

        bool operator==(const Vector2 &rhs) const noexcept
        {
            return x == rhs.x &&
                   y == rhs.y;
        }

        bool operator!=(const Vector2 &rhs) const noexcept
        {
            return !(rhs == *this);
        }

        VecType operator+(const VecType &rhs) const noexcept
        {
            return VecType{x + rhs.x, y + rhs.y};
        }

        VecType operator-(const VecType &rhs) const noexcept
        {
            return VecType{x - rhs.x, y - rhs.y};
        }

        VecType operator*(const VecType &rhs) const noexcept
        {
            return VecType{x * rhs.x, y * rhs.y};
        }

        VecType operator/(const VecType &rhs) const noexcept
        {
            return VecType{x / rhs.x, y / rhs.y};
        }

        VecType &operator+=(const VecType &rhs) noexcept
        {
            x += rhs.x;
            y += rhs.y;

            return *this;
        }

        VecType &operator-=(const VecType &rhs) noexcept
        {
            x -= rhs.x;
            y -= rhs.y;

            return *this;
        }

        VecType &operator*=(const VecType &rhs) noexcept
        {
            x *= rhs.x;
            y *= rhs.y;

            return *this;
        }

        VecType &operator/=(const VecType &rhs) noexcept
        {
            x /= rhs.x;
            y /= rhs.y;

            return *this;
        }

        VecType operator*(T val) const noexcept
        {
            return VecType{x * val, y * val};
        }

        VecType operator/(T val) const noexcept
        {
            return VecType{x / val, y / val};
        }

        VecType &operator*=(T val) noexcept
        {
            x *= val;
            y *= val;

            return *this;
        }

        VecType &operator/=(T val) noexcept
        {
            x /= val;
            y /= val;

            return *this;
        }
    };

    typedef Vector2<float> Vector2f;
    typedef Vector2<double> Vector2d;
    typedef Vector2<int32_t> Vector2i;
    typedef Vector2<uint32_t> Vector2u;
    typedef Vector2<int64_t> Vector2l;
    typedef Vector2<uint64_t> Vector2ul;
}
