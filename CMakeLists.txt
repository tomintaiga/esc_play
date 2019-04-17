cmake_minimum_required(VERSION 3.8)
project(ECS_Play)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

add_subdirectory(ecs)
add_subdirectory(game)