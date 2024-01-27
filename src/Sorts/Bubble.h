// Copyright (c) 2024 Natalie Wiggins. All rights reserved.
// SPDX-License-Identifier: MIT

#pragma once

#include <array>

#include "Utils.h"

namespace algorithms {
template<typename T, auto N>
void bubbleSort(std::array<T, N> & arr)
{
    bool done;
    do {
        done = true;
        for (auto i = 0; i < N - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr.at(i), arr.at(i + 1));
                done = false;
            }
        }
    } while (!done);
}
}// namespace algorithms