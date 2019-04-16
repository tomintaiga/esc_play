cmake_minimum_required(VERSION 3.8)
project(ECS)

# Boost 1.63 requires CMake 3.7 or newer.
# Boost 1.64 requires CMake 3.8 or newer.
# Boost 1.65 and 1.65.1 require CMake 3.9.3 or newer.
# Boost 1.66 requires CMake 3.11 or newer.
# Boost 1.67 requires CMake 3.12 or newer.
# Boost 1.68, 1.69 require CMake 3.13 or newer.

# The project version number
set(VERSION_MAJOR   1)
set(VERSION_MINOR   0)
set(VERSION_PATCH   0)
set(VERSION_FULL "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
mark_as_advanced(VERSION_MAJOR VERSION_MINOR VERSION_PATCH FULL_VERSION)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Threads REQUIRED)
find_package(Boost REQUIRED COMPONENTS log unit_test_framework)

include_directories(${CMAKE_INCLUDE_PATH} ${Boost_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR})

enable_testing()
add_subdirectory(test)

file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_library(ecs SHARED ${SRC_FILES})
set_target_properties(ecs PROPERTIES VERSION "${VERSION_FULL}" SOVERSION "${VERSION_MAJOR}.${VERSION_MINOR}")
target_link_libraries(ecs ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})