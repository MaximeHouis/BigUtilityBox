/*
** BigUtilityBox Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

namespace bub {

    /**
     * This template can detect the type of a variable at compilation time.
     * It's useful when you are having doubts about auto or decltype deduction.
     *
     * Inspired from Scott Meyer's Effective Modern C++.
     */
    template<typename>
    class TypeDisplayer;

    // In order to display the type deduction at compile time, we need to force a compilation error.

}
