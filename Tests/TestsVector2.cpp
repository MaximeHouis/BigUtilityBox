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

#define DP_INTEGERS DataPoints(Vector2i::ValueType, std::numeric_limits<Vector2i::ValueType>::min(), -128, -10, -1, -0, 0, 1, 10, 128, std::numeric_limits<Vector2i::ValueType>::max())

#define DP_SCALAR_VEC DataPoints(Vector2f, Vector2f{-4, 5}, Vector2f{0, 9}, Vector2f{3, 0}, Vector2f{6, 7}, Vector2f{-6, 11}, Vector2f{-6, -3}, Vector2f{5, -5})
#define DP_SCALAR_NBR DataPoints(Vector2f::ValueType, -10, -2, -1, 0, 1, 2, 10)

using namespace bub;

TheoryDataPoints(Vector2, Vector2iCtor) = {
        DP_INTEGERS,
        DP_INTEGERS,
};

TheoryDataPoints(Vector2, VectorScalarMul) = {
        DP_SCALAR_VEC,
        DP_SCALAR_NBR
};

TheoryDataPoints(Vector2, VectorScalarDiv) = {
        DP_SCALAR_VEC,
        DP_SCALAR_NBR
};

Theory((Vector2i::ValueType x, Vector2i::ValueType y), Vector2, Vector2iCtor)
{
    const Vector2i vec{x, y};

    cr_assert(vec.x == x);
    cr_assert(vec.y == y);
}

Test(Vector2, CastFloatToInt)
{
    const Vector2f v{5.5, 3.2};
    const Vector2i u{v};

    cr_assert(u.x == 5);
    cr_assert(u.y == 3);
}

Test(Vector2, Normalization)
{
    const Vector2f v1{5.5, 4.2};
    const Vector2i v2{5, 4};
    const Vector2i v3{3, 4};
    const Vector2i v4{8, 4};

    const auto v1dist = v1.normalize();

    cr_assert(v1dist < 7 && v1dist > 6.9);
    cr_assert(v2.normalize() == 6);
    cr_assert(v3.normalize() == 5);
    cr_assert(v4.normalize() == 9);
}

Theory((Vector2f vec, Vector2f::ValueType val), Vector2, VectorScalarMul)
{
    const auto result = vec * val;

    cr_assert(result.x == vec.x * val);
    cr_assert(result.y == vec.y * val);
}

Theory((Vector2f vec, Vector2f::ValueType val), Vector2, VectorScalarDiv)
{
    cr_assume(val != 0);

    const auto result = vec / val;

    cr_assert(result.x == vec.x / val);
    cr_assert(result.y == vec.y / val);
}
