// Copyright (c) 2024 Natalie Wiggins. All rights reserved.
// SPDX-License-Identifier: MIT

#pragma once

namespace algorithms {
template<typename T>
void swap(T & lhs, T & rhs)
{
    auto tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}
}// namespace algorithms