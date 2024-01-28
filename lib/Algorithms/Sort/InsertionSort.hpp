// Copyright (c) 2024 Natalie Wiggins. All rights reserved.
// SPDX-License-Identifier: MIT

#pragma once

#include <array>

namespace Algorithms {
template<typename T, std::size_t N>
void insertionSort(std::array<T, N> & arr)
{
    // Assume the first value is sorted
    for (auto i = 1; i < N; ++i) {
        auto key = arr.at(i);
        auto end = i - 1;
        while (end >= 0 && arr.at(end) > key) {
            // Shift values left
            arr.at(end + 1) = arr[end];
            --end;
        }
        // Restore key at the end of the range
        arr.at(end + 1) = key;
    }
}
}// namespace Algorithms