cmake_minimum_required (VERSION 2.6)
project (myApp)

set(CMAKE_VERBOSE_MAKEFILE 1)
set(APP_VERSION_MAJOR 1)
set(APP_VERSION_MINOR 0)
set(APP_TARGET demo.app)
include_directories(./include)

# glfw
find_package(glfw3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
link_libraries(${GLFW_LIBRARY_DIRS})

# opengl
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

add_executable( 
    ${APP_TARGET} 
    main.cpp
    glad.c
)

target_link_libraries(
        ${APP_TARGET}
        glfw
        ${CMAKE_DL_LIBS}
        ${OPENGL_LIBRARIES}
        ${GLEW_LIBRARIES}
        ${EXTRA_LIBS}
)

