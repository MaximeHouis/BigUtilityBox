/*
** EPITECH PROJECT, 2019
** BigUtilityBox
** File description:
** Vector3.hpp
*/

#pragma once

#include <cstdint>
#include <cmath>

namespace bub {
    template<typename T>
    struct Vector3 {
        typedef T ValueType;
        typedef Vector3<T> VecType;

        T x;
        T y;
        T z;

        Vector3() noexcept
                : x{0}, y{0}, z{0}
        {}

        Vector3(T x_, T y_, T z_) noexcept
                : x{x_}, y{y_}, z{z_}
        {}

        template<typename U>
        explicit Vector3(const Vector3<U> &rhs) noexcept : x{static_cast<T>(rhs.x)}, y{static_cast<T>(rhs.y)},
                                                           z{static_cast<T>(rhs.z)}
        {}

        Vector3(Vector3<T> &&) noexcept = default;
        Vector3(const Vector3<T> &) noexcept = default;
        Vector3 &operator=(Vector3<T> &&) noexcept = default;
        Vector3 &operator=(const Vector3<T> &) noexcept = default;

        ~Vector3() = default;

        T length() const noexcept
        {
            if constexpr (std::is_floating_point<T>())
                return static_cast<T>(std::sqrt(x * x + y * y + z * z));
            else
                return static_cast<T>(std::round(std::sqrt(x * x + y * y + z * z)));
        }

        VecType normalize() const noexcept
        {
            return *this * (1.0 / length());
        }

        bool operator==(const Vector3 &rhs) const noexcept
        {
            return x == rhs.x &&
                   y == rhs.y &&
                   z == rhs.z;
        }

        bool operator!=(const Vector3 &rhs) const noexcept
        {
            return !(rhs == *this);
        }

        VecType operator+(const VecType &rhs) const noexcept
        {
            return VecType{x + rhs.x, y + rhs.y, z + rhs.z};
        }

        VecType operator-(const VecType &rhs) const noexcept
        {
            return VecType{x - rhs.x, y - rhs.y, z - rhs.z};
        }

        VecType operator*(const VecType &rhs) const noexcept
        {
            return VecType{x * rhs.x, y * rhs.y, z * rhs.z};
        }

        VecType operator/(const VecType &rhs) const noexcept
        {
            return VecType{x / rhs.x, y / rhs.y, z / rhs.z};
        }

        VecType &operator+=(const VecType &rhs) noexcept
        {
            x += rhs.x;
            y += rhs.y;
            z += rhs.z;

            return *this;
        }

        VecType &operator-=(const VecType &rhs) noexcept
        {
            x -= rhs.x;
            y -= rhs.y;
            z -= rhs.z;

            return *this;
        }

        VecType &operator*=(const VecType &rhs) noexcept
        {
            x *= rhs.x;
            y *= rhs.y;
            z *= rhs.z;

            return *this;
        }

        VecType &operator/=(const VecType &rhs) noexcept
        {
            x /= rhs.x;
            y /= rhs.y;
            z /= rhs.z;

            return *this;
        }

        VecType operator*(T val) const noexcept
        {
            return VecType{x * val, y * val, z * val};
        }

        VecType operator/(T val) const noexcept
        {
            return VecType{x / val, y / val, z / val};
        }

        VecType &operator*=(T val) noexcept
        {
            x *= val;
            y *= val;
            z *= val;

            return *this;
        }

        VecType &operator/=(T val) noexcept
        {
            x /= val;
            y /= val;
            z /= val;

            return *this;
        }
    };

    typedef Vector3<float> Vector3f;
    typedef Vector3<double> Vector3d;
    typedef Vector3<long double> Vector3ld;
    typedef Vector3<int32_t> Vector3i;
    typedef Vector3<uint32_t> Vector3u;
    typedef Vector3<int64_t> Vector3l;
    typedef Vector3<uint64_t> Vector3ul;
}
