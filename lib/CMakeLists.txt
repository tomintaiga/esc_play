add_subdirectory(ecs)

option(GLM_TEST_ENABLE_FAST_MATH ON)
option(GLM_TEST_ENABLE ON)
add_subdirectory(glm)

set(ECS_include ${ECS_include} PARENT_SCOPE)
set(ECS_bin ${ECS_bin} PARENT_SCOPE)
set(GLM_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/glm PARENT_SCOPE)