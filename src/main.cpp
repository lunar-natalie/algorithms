// Copyright (c) 2024 Natalie Wiggins. All rights reserved.
// SPDX-License-Identifier: MIT

#include <iostream>
#include <array>
#include <iterator>
#include <functional>
#include <type_traits>
#include <exception>

#include "Sorts/Bubble.h"
#include "Sorts/Insertion.h"
#include "Sorts/Merge.h"
#include "Sorts/Quick.h"
#include "SampleData.h"

using namespace algorithms;

int main() try
{
    auto unsorted = sampleData;
    using Array = typeof(unsorted);

    auto show = [unsorted](const std::string & label, const std::function<void(Array &)> & fn = [](auto &) {},
                           bool last = false) {
        // Copy array and execute sort callback
        auto copy = unsorted;
        fn(copy);

        // Print "LABEL: copy[0], ...copy[n]"
        using Iterator = std::ostream_iterator<std::remove_all_extents<decltype(copy)>::type::value_type>;
        std::cout << label << ": ";
        std::copy(std::begin(copy), std::end(copy), Iterator(std::cout, " "));
        if (!last)
            std::cout << std::endl;
    };

    show("Unsorted");
    show("Bubble", [](auto & a) { bubbleSort(a); });
    show("Insertion", [](auto & a) { insertionSort(a); });
    show("Merge", [](auto & a) { mergeSort(a); });
    show("Quick", [](auto & a) { quickSort(a); }, true);
    return 0;
}
catch (std::exception & e) {
    std::cerr << e.what() << std::endl;
}