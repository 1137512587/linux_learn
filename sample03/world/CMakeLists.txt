cmake_minimum_required(VERSION 3.16.3)
project(world)

set(WORLD_SRC ${CMAKE_CURRENT_SOURCE_DIR}/world.c)

add_library(worldlib SHARED ${WORLD_SRC})