cmake_minimum_required(VERSION 3.12)
project(BigUtilityBox)

set(CMAKE_CXX_STANDARD 17)

if (UNIX)
    add_compile_options(-Wall -Wextra -Weffc++)
endif ()

include_directories(BUB/include)

add_library(
        bub STATIC
        BUB/include/BUB/Vector2.hpp
        BUB/include/BUB/Vector3.hpp
        BUB/include/BUB/TypeDisplayer.hpp
        BUB/src/BUB/Profiler.cpp BUB/include/BUB/Profiler.hpp
)

add_executable(
        unit_tests
        UnitTests/TestsVector2.cpp
        UnitTests/TestsVector3.cpp
)
target_link_libraries(unit_tests bub criterion)
