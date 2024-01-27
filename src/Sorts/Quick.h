// Copyright (c) 2024 Natalie Wiggins. All rights reserved.
// SPDX-License-Identifier: MIT

#pragma once

#include <array>
#include <functional>

#include "Utils.h"

namespace algorithms {
template<typename T, Size N>
void quickSort(std::array<T, N> & arr)
{
    auto partition = [&arr](Size left, Size right) mutable -> Size {
        auto pivot = arr.at(left);
        while (left < right) {
            while (arr.at(left) < pivot) ++left;
            while (arr.at(right) > pivot) --right;
            swap(arr.at(left), arr.at(right));
        }
        return left;
    };
    std::function<void(Size, Size)> sort = [&arr, &sort, partition](auto left, auto right) mutable {
        if (left < right) {
            auto pivot = partition(left, right);
            sort(left, pivot - 1);
            sort(pivot + 1, right);
        }
    };
    static_assert(N > 0, "Invalid array size");
    sort(0, N - 1);
}
}// namespace algorithms