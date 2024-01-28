cmake_minimum_required(VERSION 3.27)
project(Algorithms LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Catch2 3 CONFIG)

add_subdirectory(lib)
add_subdirectory(src)
if(Catch2_FOUND)
    add_subdirectory(tests)
endif()