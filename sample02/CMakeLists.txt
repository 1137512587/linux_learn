cmake_minimum_required(VERSION 3.16.3)
project(hello_world)

add_executable(main main.c hello/hello.c world/world.c)

target_include_directories(main PUBLIC world)