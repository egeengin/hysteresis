cmake_minimum_required(VERSION 3.5)

project(hysteresis)

include(FetchContent)
set(CMAKE_CXX_STANDARD 14)

# Fetch GoogleTest into the project
# To follow current Google Test commits, it is useful to update URL frequently.
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
        SOURCE_DIR "../lib/googletest/"
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(lib/googletest/googletest/include/ lib/googletest/googletest/)

add_subdirectory(src)
add_subdirectory(tst)