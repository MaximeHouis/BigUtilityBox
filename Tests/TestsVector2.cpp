/*
** EPITECH PROJECT, 2019
** BigUtilityBox
** File description:
** TestsVector2.cpp
*/

#include <criterion/criterion.h>
#include <criterion/theories.h>

#include <atomic>
#include <thread>

#include "BUB/Vector2.hpp"
#include "BUB/Profiler.hpp"

#define DP_INTEGERS DataPoints(   \
                    Vector2i::ValueType, std::numeric_limits<Vector2i::ValueType>::min(), \
                    -128, -10, -1, -0, 0, 1, 10, 128, std::numeric_limits<Vector2i::ValueType>::max())

using namespace bub;

TheoryDataPoints(Vector2, Vector2iCtor) = {
        DP_INTEGERS,
        DP_INTEGERS,
};

Theory((Vector2i::ValueType x, Vector2i::ValueType y), Vector2, Vector2iCtor)
{
    Vector2i vec{x, y};

    cr_assert(vec.x == x);
    cr_assert(vec.y == y);
}

Test(Vector2, Vector2iEmpty)
{
    Vector2i vec;

    cr_assert(vec.x == 0 && vec.y == 0);
}

Test(Vector2, ConstructAtomic)
{
    Vector2<std::atomic<uint64_t>> vec;

    cr_assert(vec.x == 0 && vec.y == 0);
}

Test(Vector2, Cast)
{
    Vector2f v{5.5, 3.2};
    Vector2i u{v};

    cr_assert(u.x == 5);
    cr_assert(u.y == 3);
}
