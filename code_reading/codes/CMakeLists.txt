cmake_minimum_required(VERSION 3.15)
project(codes)

set(CMAKE_CXX_STANDARD 17)

find_package(CGAL REQUIRED)
include(${CGAL_USE_FILE})

add_executable(codes main.cpp)

target_link_libraries(codes ${CGAL_LIBS})