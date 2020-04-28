/*
** BigUtilityBox Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include <criterion/criterion.h>
#include <criterion/theories.h>

#include <thread>

#include "BUB/Vector3.hpp"
#include "BUB/Profiler.hpp"

#define DP_INTEGERS DataPoints(Vector3i::ValueType, std::numeric_limits<Vector3i::ValueType>::min(), -128, -10, -1, -0, 0, 1, 10, 128, std::numeric_limits<Vector3i::ValueType>::max())

#define DP_VECTORS DataPoints(Vector3f, Vector3f{-4, 5, 2}, Vector3f{0, 9, -6}, Vector3f{-6, -3, -12}, Vector3f{5, -5, 0})
#define DP_OPERANDS DataPoints(Vector3f::ValueType, -100, -9, -2, -1, 0, 1, 2, 33, 100)

using namespace bub;

Test(Vector3, CastFloatToInt)
{
    const Vector3f v{5.5, 3.2, 9.9};
    const Vector3i u{v};

    cr_assert(u.x == 5);
    cr_assert(u.y == 3);
    cr_assert(u.z == 9);
}

TheoryDataPoints(Vector3, Vector3iCtor) = {
        DP_INTEGERS,
        DP_INTEGERS,
        DP_INTEGERS,
};

TheoryDataPoints(Vector3, VectorScalarMul) = {
        DP_VECTORS,
        DP_OPERANDS
};

TheoryDataPoints(Vector3, VectorScalarDiv) = {
        DP_VECTORS,
        DP_OPERANDS
};

TheoryDataPoints(Vector3, VectorOpAdd) = {
        DP_VECTORS,
        DP_OPERANDS,
        DP_OPERANDS,
        DP_OPERANDS,
};

TheoryDataPoints(Vector3, VectorOpSub) = {
        DP_VECTORS,
        DP_OPERANDS,
        DP_OPERANDS,
        DP_OPERANDS,
};

TheoryDataPoints(Vector3, VectorOpMul) = {
        DP_VECTORS,
        DP_OPERANDS,
        DP_OPERANDS,
        DP_OPERANDS,
};

TheoryDataPoints(Vector3, VectorOpDiv) = {
        DP_VECTORS,
        DP_OPERANDS,
        DP_OPERANDS,
        DP_OPERANDS,
};

Theory((Vector3i::ValueType x, Vector3i::ValueType y, Vector3i::ValueType z), Vector3, Vector3iCtor)
{
    const Vector3i vec{x, y, z};

    cr_assert(vec.x == x);
    cr_assert(vec.y == y);
    cr_assert(vec.z == z);
}

Theory((Vector3f vec, Vector3f::ValueType val), Vector3, VectorScalarMul)
{
    const auto result = vec * val;

    cr_assert(result.x == vec.x * val);
    cr_assert(result.y == vec.y * val);
    cr_assert(result.z == vec.z * val);
}

Theory((Vector3f vec, Vector3f::ValueType val), Vector3, VectorScalarDiv)
{
    cr_assume(val != 0);

    const auto result = vec / val;

    cr_assert(result.x == vec.x / val);
    cr_assert(result.y == vec.y / val);
    cr_assert(result.z == vec.z / val);
}

Theory((Vector3f vec, Vector3f::ValueType x, Vector3f::ValueType y, Vector3f::ValueType z), Vector3, VectorOpAdd)
{
    const auto result = vec + Vector3f{x, y, z};

    cr_assert(result.x == vec.x + x);
    cr_assert(result.y == vec.y + y);
    cr_assert(result.z == vec.z + z);
}

Theory((Vector3f vec, Vector3f::ValueType x, Vector3f::ValueType y, Vector3f::ValueType z), Vector3, VectorOpSub)
{
    const auto result = vec - Vector3f{x, y, z};

    cr_assert(result.x == vec.x - x);
    cr_assert(result.y == vec.y - y);
    cr_assert(result.z == vec.z - z);
}

Theory((Vector3f vec, Vector3f::ValueType x, Vector3f::ValueType y, Vector3f::ValueType z), Vector3, VectorOpMul)
{
    const auto result = vec * Vector3f{x, y, z};

    cr_assert(result.x == vec.x * x);
    cr_assert(result.y == vec.y * y);
    cr_assert(result.z == vec.z * z);
}

Theory((Vector3f vec, Vector3f::ValueType x, Vector3f::ValueType y, Vector3f::ValueType z), Vector3, VectorOpDiv)
{
    cr_assume(x != 0);
    cr_assume(y != 0);
    cr_assume(z != 0);

    const auto result = vec / Vector3f{x, y, z};

    cr_assert(result.x == vec.x / x);
    cr_assert(result.y == vec.y / y);
    cr_assert(result.z == vec.z / z);
}
