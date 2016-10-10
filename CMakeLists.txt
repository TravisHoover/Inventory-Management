cmake_minimum_required(VERSION 3.3)
project(OLA3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ola3.cpp Movie.h StoreItem.h)
add_executable(OLA3 ${SOURCE_FILES})