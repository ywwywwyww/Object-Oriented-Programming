cmake_minimum_required(VERSION 3.15)
project(codes)

set(CMAKE_CXX_STANDARD 17)

find_package(CGAL REQUIRED)
include(${CGAL_USE_FILE})

add_executable(codes main.cpp example/points_and_segment.cpp example/surprising.cpp example/exact.cpp example/array_convex_hull_2.cpp example/vector_convex_hull_2.cpp example/convex_hull_yz.cpp)

target_link_libraries(codes ${CGAL_LIBS})