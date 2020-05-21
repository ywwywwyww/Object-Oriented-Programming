cmake_minimum_required(VERSION 3.15)
project(src)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

find_package(CGAL REQUIRED)
include(${CGAL_USE_FILE})

add_executable(src main.cpp graph/undirected_graph.cpp graph/undirected_graph.h graph/complete_graph.cpp graph/complete_graph.h graph/delaunay_triangulation.cpp graph/delaunay_triangulation.h minimal_spanning_tree/minimal_spanning_tree.cpp minimal_spanning_tree/minimal_spanning_tree.h minimal_spanning_tree/kruskal.cpp minimal_spanning_tree/kruskal.h minimal_spanning_tree/disjoint_set.cpp minimal_spanning_tree/disjoint_set.h generator/generator.cpp generator/generator.h timer/timer.cpp timer/timer.h)

target_link_libraries(src ${CGAL_LIBS})