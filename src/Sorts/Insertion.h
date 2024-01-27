// Copyright (c) 2024 Natalie Wiggins. All rights reserved.
// SPDX-License-Identifier: MIT

#pragma once

#include <array>

#include "Utils.h"

namespace algorithms {
template<typename T, Size N>
void insertionSort(std::array<T, N> & arr)
{
    // Assume the first value is sorted
    for (auto i = 1; i < N; ++i) {
        auto key = arr[i];
        auto end = i - 1;
        while (end >= 0 && arr[end] > key) {
            // Shift values left
            arr[end + 1] = arr[end];
            --end;
        }
        // Restore key at the end of the range
        arr[end + 1] = key;
    }
}
}// namespace algorithms