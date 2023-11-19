cmake_minimum_required(VERSION 3.26)
project(battleShip)

set(CMAKE_CXX_STANDARD 23)

add_executable(battleShip
        Board/Board.cpp
        Board/Board.h
        Ship/Ship.h
        Game/Game.h
        Ship/Ship.cpp
        Game/Game.cpp
        main.cpp
        Ai/Ai.cpp
        Ai/Ai.h
        Player/Player.cpp
        Player/Player.h

)
