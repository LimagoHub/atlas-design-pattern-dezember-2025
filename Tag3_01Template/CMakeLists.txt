cmake_minimum_required(VERSION 3.31)
project(Tag3_01Template)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tag3_01Template main.cpp
        processor/FileProcessor.h
        processor/CharacterCounter.h
        processor/LineCounter.h)
