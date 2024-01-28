// Copyright (c) 2024 Natalie Wiggins. All rights reserved.
// SPDX-License-Identifier: MIT

#pragma once

#include <array>
#include <functional>

#include "../Utils.hpp"

namespace Algorithms {
template<typename T, std::size_t N>
void quickSort(std::array<T, N> & arr)
{
    auto partition = [&arr](std::size_t left, std::size_t right) mutable -> std::size_t {
        auto pivot = arr.at(left);
        while (left < right) {
            while (arr.at(left) < pivot) ++left;
            while (arr.at(right) > pivot) --right;
            swap(arr.at(left), arr.at(right));
        }
        return left;
    };

    std::function<void(std::size_t, std::size_t)> sort = [&sort, partition](auto left, auto right) mutable {
        if (left < right) {
            auto pivot = partition(left, right);
            sort(left, pivot - 1);
            sort(pivot + 1, right);
        }
    };

    static_assert(N > 0, "Invalid array size");
    sort(0, N - 1);
}
}// namespace Algorithms