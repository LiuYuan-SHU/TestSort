find_package(GTest REQUIRED)

add_executable(sort main.cpp
        test_env.hpp
        test_env.cpp
        test_case.hpp
        ../include/Bubble.hpp
        ../include/sort_algorithm_base.hpp
        ../include/utils.hpp)
target_link_libraries(sort GTest::gtest GTest::Main)