cmake_minimum_required(VERSION 3.31)
project(Tag1_05State)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tag1_05State main.cpp
        state/State.h
        state/AbstractState.h
        Business.h
        state/StateA.h
        Business.cpp
        Business.h)
