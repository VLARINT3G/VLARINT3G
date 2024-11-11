cmake_minimum_required(VERSION 3.29)
project(Separator)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Separator
        Database.h
        Input.cpp
        Input.h
        main.cpp
        Out.cpp
        Out.h
        Work.cpp
        Work.h)
find_package(SQLite3 REQUIRED)
include_directories(${SQLite3_INCLUDE_DIRS})
target_link_libraries(Separator ${SQLite3_LIBRARIES})
