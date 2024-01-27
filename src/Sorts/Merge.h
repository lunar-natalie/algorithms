// Copyright (c) 2024 Natalie Wiggins. All rights reserved.
// SPDX-License-Identifier: MIT

#pragma once

#include <array>
#include <vector>
#include <functional>
#include <stdexcept>

namespace algorithms {
template<typename T, auto N>
void mergeSort(std::array<T, N> & arr)
{
    std::function<std::vector<T>(std::vector<T>)> impl = [&impl](auto vec) {
        if (vec.size() > 1) {
            // Split into two partitions at midpoint
            std::size_t mid = vec.size() / 2;
            auto left = impl(std::vector(vec.begin(), vec.begin() + mid)); // 0..mid
            auto right = impl(std::vector(vec.begin() + mid, vec.end())); // mid..end

            // Merge left and right into original vector
            auto il = 0, ir = 0, iv = 0;
            while (il < left.size() && ir < right.size())
                vec.at(iv++) = left[il] <= right[ir] ? left[il++] : right[ir++];
            while (il < left.size())
                vec.at(iv++) = left[il++];
            while (ir < right.size())
                vec.at(iv++) = right[ir++];
        }
        return vec;
    };

    auto vec = impl(std::vector(arr.begin(), arr.end()));
    // Return fixed-length array
    if (vec.size() != N)
        throw std::runtime_error("Vector/array size mismatch");
    std::copy(vec.begin(), vec.end(), arr.begin());
}
}// namespace algorithms