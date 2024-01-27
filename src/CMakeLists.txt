add_executable(algorithms main.cpp
        Sorts/Bubble.h
        Sorts/Insertion.h
        Sorts/Merge.h
        Sorts/Quick.h
        Utils.h
)
target_include_directories(algorithms
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR})