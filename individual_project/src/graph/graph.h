/**
 * @file graph.h
 * @author Wuwei YUAN
 * @date 5/20/20
 */

#ifndef SRC_GRAPH_GRAPH_H_
#define SRC_GRAPH_GRAPH_H_

#include <vector>
#include <utility>
#include <cmath>
#include <iostream>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>

struct ConstructionStrategy;

/**
 * A class to describe a undirected euclidean graph.
 */
class Graph {
 public:
  typedef CGAL::Exact_predicates_exact_constructions_kernel Kernel;
  typedef Kernel::Point_2 Point;
  typedef std::pair<int, int> Edge;

  /**
   * Construct the graph using given vertices and edges
   * @param vertices The points
   * @param edges The edges
   */
  explicit Graph(const std::vector<Point> &vertices, const std::vector<Edge> &edges = std::vector<Edge>{})
      : vertices_{vertices}, edges_{edges} {}

  /**
   * Construct the graph using data in the input stream
   * @param in The input stream
   */
  explicit Graph(std::istream &in);

  /**
   * Construct this graph using given vertices and strategy
   * @param vertices The points
   * @param strategy The construction strategy
   */
  Graph(const std::vector<Point> &vertices, ConstructionStrategy *const &strategy);

  virtual ~Graph() = default;

  void AddEdge(const Edge &edge);
  void AddEdges(const std::vector<Edge> &edges);

  int GetNumVertices() const {
    return this->vertices_.size();
  }
  int GetNumEdges() const {
    return this->edges_.size();
  }
  Point GetVertex(int id) const {
    return this->vertices_[id];
  }
  Edge GetEdge(int id) const {
    return this->edges_[id];
  }
  const std::vector<Point> &GetVertices() const {
    return this->vertices_;
  }
  const std::vector<Edge> &GetEdges() const {
    return this->edges_;
  }

  /**
   * Calculate the overall length, that is, the total length of all edges of the graph
   * @return The overall length
   */
  double OverallLength() const;

  void DisplayVertices(std::ostream &out) const;

  void DisplayEdges(std::ostream &out) const;

 private:
  std::vector<Point> vertices_;
  std::vector<Edge> edges_;
};

/**
 * Output the whole graph to the output stream
 * @param out The output stream
 * @param graph The graph
 * @return The output stream
 */
std::ostream &operator <<(std::ostream &out, const Graph &graph);

#endif //SRC_GRAPH_GRAPH_H_
