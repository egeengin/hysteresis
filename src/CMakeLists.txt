cmake_minimum_required(VERSION 3.5)
project(hysteresis C)

set(HEADERS hysteresis.h)
set(SOURCES hysteresis.c main.c)

add_library(hysteresis_lib ${HEADERS} ${SOURCES})
set_target_properties(hysteresis_lib PROPERTIES LINKER_LANGUAGE C)

add_executable(hysteresis ${SOURCES})