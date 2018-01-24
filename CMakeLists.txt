cmake_minimum_required (VERSION 2.6)
project (myApp)

set(CMAKE_VERBOSE_MAKEFILE 1)
set(APP_VERSION_MAJOR 1)
set(APP_VERSION_MINOR 0)
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )
set(APP_TARGET demo.app)


if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	message("You're on Mac OS !")
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	message("You're on Linux !")
        find_package(glfw3 REQUIRED)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	message("You're on Windows !")
        set(GLFW_INCLUDE_PATH "" CACHE PATH "libs/glfw/include" )
        set(GLFW_LIBRARY "" CACHE FILEPATH "libs/glfw/src/Release/glfw3.lib" )


endif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin") # Yes this is weird but you have to repeat the "if" here.

# opengl
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

# glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(libs/glfw)

include_directories(${GLFW_INCLUDE_DIRS})
link_libraries(${GLFW_LIBRARY_DIRS})

add_executable( 
    ${APP_TARGET} 
    main.cpp
    glad.c
)

target_link_libraries(
        ${APP_TARGET}
        ${GLFW_LIBRARY}
        ${CMAKE_DL_LIBS}
        ${OPENGL_LIBRARIES}
        #${GLEW_LIBRARIES}
        ${EXTRA_LIBS}
)

