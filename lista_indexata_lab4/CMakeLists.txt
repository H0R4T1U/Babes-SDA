cmake_minimum_required(VERSION 3.28)
project(lista_indexata_lab4)

set(CMAKE_CXX_STANDARD 17)

add_executable(lista_indexata_lab4 main.cpp
        LI.cpp
        LI.h
        IteratorLI.cpp
        IteratorLI.h
        TestScurt.cpp
        TestScurt.h
        TestExtins.cpp
        TestExtins.h)
