# To generete GLAD:
# https://glad.dav1d.de
# To work with GLAD need to link to ${CMAKE_DL_LIBS}

set(GLAD_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE)
set(GLAD_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/glad.c PARENT_SCOPE)
set(GLAD_LIBS ${CMAKE_DL_LIBS} PARENT_SCOPE)
