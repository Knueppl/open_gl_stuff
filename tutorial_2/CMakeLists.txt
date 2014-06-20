cmake_minimum_required (VERSION 2.6)
project(tutorial_2)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(opengl-window
               src/main.cpp
               )

target_link_libraries(opengl-window
                      ${OpenGL_LIBRARIES}
                      ${GLUT_LIBRARIES}
                      GLEW
                      )
