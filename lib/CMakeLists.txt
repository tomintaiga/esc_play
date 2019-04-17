add_subdirectory(ecs)

option(GLM_TEST_ENABLE_FAST_MATH ON)
option(GLM_TEST_ENABLE ON)
option(GLM_TEST_ENABLE_CXX_17 ON)
add_subdirectory(glm)

add_subdirectory(glad)

set(ECS_include ${ECS_include} PARENT_SCOPE)
set(ECS_bin ${ECS_bin} PARENT_SCOPE)
set(GLM_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/glm PARENT_SCOPE)
set(GLAD_INCLUDE ${GLAD_INCLUDE} PARENT_SCOPE)
set(GLAD_SRC ${GLAD_SRC} PARENT_SCOPE)
set(GLAD_LIBS ${GLAD_LIBS} PARENT_SCOPE)
