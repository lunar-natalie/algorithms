add_executable(AlgorithmsTests SortTests.cpp)
target_link_libraries(AlgorithmsTests PRIVATE AlgorithmsLib Catch2::Catch2WithMain)

include(Catch)
catch_discover_tests(AlgorithmsTests)