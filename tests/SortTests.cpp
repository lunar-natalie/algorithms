// Copyright (c) 2024 Natalie Wiggins. All rights reserved.
// SPDX-License-Identifier: MIT

#include <array>
#include <functional>

#include <catch2/catch_test_macros.hpp>

#include <Algorithms/Sort.hpp>

using namespace Algorithms;

TEST_CASE("Sort sample data", "[SortTests]")
{
    using Array = std::array<int, 8>;
    const Array unsorted = {4, 2, 56, -1, 1, 0, 8, 9};
    const Array sorted = {-1, 0, 1, 2, 4, 8, 9, 56};

    auto run = [&unsorted, &sorted](const std::function<void(Array &)> & fn) {
        auto copy = unsorted;
        fn(copy);
        CHECK(copy == sorted);
    };

    SECTION("Bubble")
    {
        run([](auto & a) { bubbleSort(a); });
    }
    SECTION("Insertion")
    {
        run([](auto & a) { insertionSort(a); });
    }
    SECTION("Merge")
    {
        run([](auto & a) { mergeSort(a); });
    }
    SECTION("Quick")
    {
        run([](auto & a) { quickSort(a); });
    }
}
