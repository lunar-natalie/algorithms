// Copyright (c) 2024 Natalie Wiggins. All rights reserved.
// SPDX-License-Identifier: MIT

#pragma once

#include <cstddef>

namespace Algorithms {
template<typename T>
constexpr void swap(T & lhs, T & rhs)
{
    auto tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}
}// namespace Algorithms