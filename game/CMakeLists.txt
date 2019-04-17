cmake_minimum_required(VERSION 3.8)
project(Game)

# C++ options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Dependencies
find_package(OpenGL REQUIRED)                                                                      
find_package(GLUT REQUIRED)                                                                        
find_package(GLEW REQUIRED)                                                                        

find_package(PkgConfig REQUIRED)                                                                   
pkg_check_modules(GLFW REQUIRED glfw3)