cmake_minimum_required(VERSION 3.29)
project(hw_l15)

set(CMAKE_CXX_STANDARD 20)

add_executable(hw_l15 main.cpp
        console_utils.h
        console_utils.cpp
        clan.h
        clan.cpp
        player.h
        Player.cpp
        battle.h
        battle.cpp
        loby.h
        loby.cpp)
