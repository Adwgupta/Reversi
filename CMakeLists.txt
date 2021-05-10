cmake_minimum_required(VERSION 3.17)
project(Reversi C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(Code)

add_executable(Reversi
        Code/ascii.h
        AfterGame.c
        AfterGame.h
        main.c
        PreGame.c
        PreGame.h
        yes.c ascii.c ascii.h)
