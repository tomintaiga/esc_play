cmake_minimum_required(VERSION 3.8)
project(EcsGame)

# C++ options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Dependencies
find_package(OpenGL REQUIRED)                                                                      
find_package(GLUT REQUIRED)                                                                        
find_package(GLEW REQUIRED)
find_package(Boost REQUIRED COMPONENTS program_options)

find_package(PkgConfig REQUIRED)                                                                   
pkg_check_modules(GLFW REQUIRED glfw3)

include_directories( ${OPENGL_INCLUDE_DIR} 
                     ${GLFW_INCLUDE_DIRS} 
                     ${GLEW_INCLUDE_DIRS} 
                     ${GLUT_INCLUDE_DIRS}
                     ${GLAD_INCLUDE}
                     ${GLM_INCLUDE}
                     ${ECS_include}
                     ${Boost_INCLUDE_DIRS})

file(GLOB source ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp                                                 
                 ${CMAKE_CURRENT_SOURCE_DIR}/*.h)  
    
    
add_executable(EcsGame ${GLAD_SRC} ${source})

target_link_libraries(EcsGame ${OPENGL_LIBRARIES} 
                              ${GLFW_LIBRARIES} 
                              ${GLEW_LIBRARIES} 
                              ${GLUT_LIBRARIES} 
                              ${GLAD_LIBS}
                              glm_shared
                              ${ECS_bin}
                              ${Boost_LIBRARIES})                     