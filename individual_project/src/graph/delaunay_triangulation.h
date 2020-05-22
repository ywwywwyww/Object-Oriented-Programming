/**
 * @file delaunay_triangulation.h
 * @author Wuwei YUAN
 * @date 5/20/20
 */

#ifndef SRC_GRAPH_DELAUNAY_TRIANGULATION_H_
#define SRC_GRAPH_DELAUNAY_TRIANGULATION_H_

#include "construction_strategy.h"
#include "graph.h"

class DelaunayTriangulation : public ConstructionStrategy {
 public:
   /**
    * Constructs the Delaunay triangulation of the graph
    * @param graph The graph
    */
  void Construct(Graph *const &graph) const override;
};

#endif //SRC_GRAPH_DELAUNAY_TRIANGULATION_H_
