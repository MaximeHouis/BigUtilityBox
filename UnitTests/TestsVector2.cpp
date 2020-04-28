/*
** BigUtilityBox Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include <criterion/criterion.h>
#include <criterion/theories.h>

#include <thread>

#include "BUB/Vector2.hpp"
#include "BUB/Profiler.hpp"

#define DP_INTEGERS DataPoints(Vector2i::ValueType, std::numeric_limits<Vector2i::ValueType>::min(), -128, -10, -1, -0, 0, 1, 10, 128, std::numeric_limits<Vector2i::ValueType>::max())

#define DP_VECTORS DataPoints(Vector2f, Vector2f{-4, 5}, Vector2f{0, 9}, Vector2f{3, 0}, Vector2f{6, 7}, Vector2f{-6, 11}, Vector2f{-6, -3}, Vector2f{5, -5})
#define DP_OPERANDS DataPoints(Vector2f::ValueType, -100, -33, -10, -9, -2, -1, 0, 1, 2, 5, 7, 11, 26, 33)

using namespace bub;

Test(Vector2, CastFloatToInt)
{
    const Vector2f v{5.5, 3.2};
    const Vector2i u{v};

    cr_assert(u.x == 5);
    cr_assert(u.y == 3);
}

Test(Vector2, Length)
{
    const Vector2f v1{5.5, 4.2};
    const Vector2i v2{5, 4};
    const Vector2i v3{3, 4};
    const Vector2i v4{8, 4};

    const auto v1dist = v1.length();

    cr_assert(v1dist < 7 && v1dist > 6.9);
    cr_assert(v2.length() == 6);
    cr_assert(v3.length() == 5);
    cr_assert(v4.length() == 9);
}

TheoryDataPoints(Vector2, Vector2iCtor) = {
        DP_INTEGERS,
        DP_INTEGERS,
};

TheoryDataPoints(Vector2, VectorScalarMul) = {
        DP_VECTORS,
        DP_OPERANDS
};

TheoryDataPoints(Vector2, VectorScalarDiv) = {
        DP_VECTORS,
        DP_OPERANDS
};

TheoryDataPoints(Vector2, VectorOpAdd) = {
        DP_VECTORS,
        DP_OPERANDS,
        DP_OPERANDS,
};

TheoryDataPoints(Vector2, VectorOpSub) = {
        DP_VECTORS,
        DP_OPERANDS,
        DP_OPERANDS,
};

TheoryDataPoints(Vector2, VectorOpMul) = {
        DP_VECTORS,
        DP_OPERANDS,
        DP_OPERANDS,
};

TheoryDataPoints(Vector2, VectorOpDiv) = {
        DP_VECTORS,
        DP_OPERANDS,
        DP_OPERANDS,
};

Theory((Vector2i::ValueType x, Vector2i::ValueType y), Vector2, Vector2iCtor)
{
    const Vector2i vec{x, y};

    cr_assert(vec.x == x);
    cr_assert(vec.y == y);
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

Theory((Vector2f vec, Vector2f::ValueType x, Vector2f::ValueType y), Vector2, VectorOpAdd)
{
    const auto result = vec + Vector2f{x, y};

    cr_assert(result.x == vec.x + x);
    cr_assert(result.y == vec.y + y);
}

Theory((Vector2f vec, Vector2f::ValueType x, Vector2f::ValueType y), Vector2, VectorOpSub)
{
    const auto result = vec - Vector2f{x, y};

    cr_assert(result.x == vec.x - x);
    cr_assert(result.y == vec.y - y);
}

Theory((Vector2f vec, Vector2f::ValueType x, Vector2f::ValueType y), Vector2, VectorOpMul)
{
    const auto result = vec * Vector2f{x, y};

    cr_assert(result.x == vec.x * x);
    cr_assert(result.y == vec.y * y);
}

Theory((Vector2f vec, Vector2f::ValueType x, Vector2f::ValueType y), Vector2, VectorOpDiv)
{
    cr_assume(x != 0);
    cr_assume(y != 0);

    const auto result = vec / Vector2f{x, y};

    cr_assert(result.x == vec.x / x);
    cr_assert(result.y == vec.y / y);
}
