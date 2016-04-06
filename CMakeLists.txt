cmake_minimum_required(VERSION 3.4)
project(JeuxdeBallon)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        src/ballon.cpp
        include/ballon.h
        src/but.cpp
        include/but.h
        src/joueur.cpp
        include/joueur.h
        src/stade.cpp)

add_executable(JeuxdeBallon ${SOURCE_FILES})