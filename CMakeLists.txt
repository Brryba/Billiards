cmake_minimum_required(VERSION 3.29)
project(Billiards)

set(CMAKE_CXX_STANDARD 26)

add_executable(Billiards src/Main/main.cpp
        src/Main/main.cpp
        src/Graphics/Draw.cpp
        src/Graphics/Draw.h
        src/Main/Constants.h
        src/GamePlay/Balls.cpp
        src/Controls/Handlers.h
        src/Controls/Handlers.cpp
        src/Graphics/DrawTable.cpp
        src/Graphics/DrawTable.h
        src/GamePlay/Collisions.h
        src/GamePlay/Collisions.cpp
        src/GamePlay/GameState.h
        src/GamePlay/GameState.cpp
        src/GamePlay/BallConstants.h
        src/GamePlay/Player.h)

target_link_libraries(Billiards ${OPENGL_LIBRARIES})
target_link_libraries(Billiards -lopengl32 -g -lfreeglut)
target_link_libraries(Billiards ${GULT_LIBRARIES})
