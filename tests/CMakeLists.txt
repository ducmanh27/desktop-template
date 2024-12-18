cmake_minimum_required(VERSION 3.16)
add_executable(tests
  main.cpp
)

target_link_libraries(tests
    gtest
    gtest_main)
