cmake_minimum_required(VERSION 3.14)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 14)

include_directories(Src)

add_executable(GameOfLife
        Src/Cell.h
        Src/ConsoleDrawer.cpp
        Src/ConsoleDrawer.h
        Src/Drawer.h
        Src/Field.cpp
        Src/Field.h
        Src/Game.cpp
        Src/Game.h
        Src/main.cpp
        Src/State.cpp
        Src/State.h Src/NcursesDrawer.h Src/NcursesDrawer.cpp Src/CellProcessor.h Src/CellProcessor.cpp)

target_link_libraries(GameOfLife ncurses pthread)
