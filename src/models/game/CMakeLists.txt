cmake_minimum_required(VERSION 3.5)

project(Checkers-models-game VERSION 0.1 LANGUAGES CXX)

set(SOURCES
    source/Board.cpp
)

set (HEADERS
    headers/IPlayer.h
    headers/Board.h
)

set(PROJECT_SOURCES
        ${SOURCES}
        ${HEADERS}
)

add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES})
