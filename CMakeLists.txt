cmake_minimum_required(VERSION 3.3)
project(OLA3)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${OLA3}/cmake")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


include_directories(${OLA3})
include_directories(source/headers)
include_directories("/usr/bin/clang++")

set(SOURCE_FILES ola3.cpp Movie.h StoreItem.h Book.h Movie.cpp StoreItem.cpp Book.cpp)
add_executable(OLA3 ${SOURCE_FILES})