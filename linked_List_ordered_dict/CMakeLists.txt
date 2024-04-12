cmake_minimum_required(VERSION 3.27)
project(linked_List_ordered_dict)

set(CMAKE_CXX_STANDARD 17)

add_executable(linked_List_ordered_dict App.cpp
        Iterator.h
        Iterator.cpp
        DO.cpp
        DO.h
        TestExtins.h
        TestExtins.cpp
        TestScurt.cpp)
