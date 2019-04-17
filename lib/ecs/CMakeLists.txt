cmake_minimum_required(VERSION 3.8)
project(ECS)

# ECS version
set(ECS_VERSION_MAJOR   1)
set(ECS_VERSION_MINOR   0)
set(ECS_VERSION_PATCH   0)
set(ECS_VERSION_FULL "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
mark_as_advanced(VERSION_MAJOR VERSION_MINOR VERSION_PATCH FULL_VERSION)

# C++ options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Dependencies
find_package(Threads REQUIRED)
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

set(include_dirs ${CMAKE_INCLUDE_PATH} ${Boost_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/include)

include_directories(${include_dirs})

add_subdirectory(test)

file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB headers ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
add_library(ecs SHARED ${sources} ${headers})
set_target_properties(ecs PROPERTIES VERSION "${ECS_VERSION_FULL}" SOVERSION "${ECS_VERSION_MAJOR}.${ECS_VERSION_MINOR}")
target_link_libraries(ecs ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

set(ECS_include ${Boost_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE)
set(ECS_bin ecs PARENT_SCOPE)