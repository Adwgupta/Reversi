cmake_minimum_required(VERSION 3.17)
project(Othello)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Othello
        main.c
        colour.c
        colour.h
        ascii.c
        ascii.h
        preGame.c
        preGame.h
        initialize.c
        initialize.h
        findMoves.c
        findMoves.h
        turns.c
        turns.h
        updateGame.c
        updateGame.h
        afterGame.c
        afterGame.h)
