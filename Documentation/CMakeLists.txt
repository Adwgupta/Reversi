cmake_minimum_required(VERSION 3.17)
project(Code C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Code
        AfterGame.c
        AfterGame.h
        main.c
        PreGame.c
        PreGame.h
        tempCodeRunnerFile.c
        yes.c asc.cpp asc.h)
