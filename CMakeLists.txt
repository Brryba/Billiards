cmake_minimum_required(VERSION 3.29)
project(Billiards)

set(CMAKE_CXX_STANDARD 26)

add_executable(Billiards main.cpp
        main.cpp)

target_link_libraries(Billiards ${OPENGL_LIBRARIES})
target_link_libraries(Billiards -lopengl32 -g -lfreeglut)
target_link_libraries(Billiards ${GULT_LIBRARIES})
