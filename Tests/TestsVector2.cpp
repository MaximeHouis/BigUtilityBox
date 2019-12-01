/*
** EPITECH PROJECT, 2019
** BigUtilityBox
** File description:
** TestsVector2.cpp
*/

#include <criterion/criterion.h>
#include <criterion/theories.h>

#include <atomic>

#include "BUB/Vector2.hpp"

Test(Vector2, Construct)
{
    bub::Vector2i vec;

    cr_assert(vec.x == 0 && vec.y == 0);
}

Test(Vector2, ConstructAtomic)
{
    bub::Vector2<std::atomic<int>> vec;

    cr_assert(vec.x == 0 && vec.y == 0);
}

Test(Vector2, Cast)
{
    bub::Vector2f v{5.5, 3.2};
    bub::Vector2i u{v};

    cr_assert(u.x == 5);
    cr_assert(u.y == 3);
}
