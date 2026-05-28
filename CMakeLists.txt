
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(hashmap C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(
    -std=c11
    -g
    -Wall
    -Wextra
    -Wpedantic
)

add_executable( hashmap
    src/main.c
    src/hashmap.c
    src/hashmap.h
)

target_include_directories(hashmap PRIVATE include)
