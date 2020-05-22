cmake_minimum_required(VERSION 3.15)
project(src)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

find_package(CGAL REQUIRED)
include(${CGAL_USE_FILE})

add_executable(src main.cpp graph/graph.cpp graph/graph.h graph/complete_graph.cpp graph/complete_graph.h graph/delaunay_triangulation.cpp graph/delaunay_triangulation.h graph/kruskal.cpp graph/kruskal.h graph/disjoint_set.cpp graph/disjoint_set.h generator/generator.cpp generator/generator.h timer/timer.cpp timer/timer.h graph/construction_strategy.cpp graph/construction_strategy.h graph/minimal_spanning_tree.cpp graph/minimal_spanning_tree.h)

target_link_libraries(src ${CGAL_LIBS})