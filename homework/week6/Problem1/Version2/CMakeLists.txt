cmake_minimum_required(VERSION 3.15)
project(Version1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Version1 main.cpp BaseRouter.h BaseRouter.a OptRouter.cpp OptRouter.h)