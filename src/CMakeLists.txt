find_package(GTest REQUIRED)

add_executable(sort main.cpp
        test_env.hpp
        test_env.cpp
        test_case.hpp
        Quick.cpp
        Heap.cpp
        )
target_link_libraries(sort GTest::gtest GTest::Main)