cmake_minimum_required(VERSION 3.14)
project(practice_data_structures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

# Для Windows: исключает конфликт настроек рантайма Visual Studio.
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(data_structures_test
    tests/data_structures_test.cpp
)

target_include_directories(data_structures_test PRIVATE include)

target_link_libraries(data_structures_test
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(data_structures_test)
