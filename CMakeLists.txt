cmake_minimum_required(VERSION 3.29)
project(Billiards)

set(CMAKE_CXX_STANDARD 26)

add_executable(Billiards src/main.cpp
        src/main.cpp
        src/Draw.cpp
        src/Draw.h
        src/Constants.h
        src/Balls.cpp
        src/Handlers.h
        src/Handlers.cpp
        src/DrawTable.cpp
        src/DrawTable.h
        src/Collisions.h
        src/Collisions.cpp)

target_link_libraries(Billiards ${OPENGL_LIBRARIES})
target_link_libraries(Billiards -lopengl32 -g -lfreeglut)
target_link_libraries(Billiards ${GULT_LIBRARIES})
