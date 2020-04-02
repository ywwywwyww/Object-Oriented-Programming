/**
 * @file OptRouter.h
 * @author Wuwei YUAN
 * @date 3/26/20
 */

#ifndef VERSION1__OPTROUTER_H_
#define VERSION1__OPTROUTER_H_

#include "BaseRouter.h"

class OptRouter : public BaseRouter
{
 public:
  OptRouter(int r, int c, const Point &source, const Point &target, const PointVector &obs)
      : BaseRouter{r, c, source, target, obs} {}
  ~OptRouter() {}
  void mazeBacktrace();
  bool route();
 protected:
  enum {START=-1, ROW=0, col=1}; // The current direction
  enum {MIN=1, MAX=-1}; // The aim of the path
  /**
   * Finds a path from the current grid to the source with minimum/maximum turns
   * @param current_index The current grid
   * @param aim The aim : MIN(minimum) or MAX(maximum)
   * @param current_direction The current direction
   * @param num_turns The current turns
   */
  void Dfs(int current_index, int aim=MIN, int current_direction=START, int num_turns=0);
  int optimal_turns_; // The current optimal turns
  vector <int> current_path_; // The path with optimal turns
};

#endif //VERSION1__OPTROUTER_H_
