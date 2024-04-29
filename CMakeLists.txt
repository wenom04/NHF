cmake_minimum_required(VERSION 3.28)
project(sportegyesulet)

set(CMAKE_CXX_STANDARD 17)

add_definitions(-DMEMTRACE)

add_executable(sportegyesulet test_main.cpp
        Player.h
        Team.h
        Club.h
        Handball.h
        Football.h
        Basketball.h
        Genericteam.h
        memtrace.h
        functions.h
        Handball.cpp
        Football.cpp
        Basketball.cpp
        Club.cpp
        memtrace.cpp
        functions.cpp
        Team.cpp
        Player.cpp
        GenericTeam.cpp)