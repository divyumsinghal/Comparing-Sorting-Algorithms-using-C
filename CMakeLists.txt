cmake_minimum_required(VERSION 3.15)


project(Sorting_Algorithms C)


set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})

add_executable(IGN_Popular_Games_YearWise
        t5.c
)

add_executable(IGN_Popular_Games
        t4.c
)

add_executable(Sorting_Algorithms
        t1.c
        t1.h
        t2.c
        t2.h
        t3.c
)
