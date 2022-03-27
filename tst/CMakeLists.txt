cmake_minimum_required(VERSION 3.5)
project(hysteresis)

add_executable(unitTestHysteresis tst_main.cpp tst_hysteresis.cpp)

target_link_libraries(unitTestHysteresis hysteresis_lib gtest gtest_main pthread)
