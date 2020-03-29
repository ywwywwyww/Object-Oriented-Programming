/**
 * @file OptRouter.cpp
 * @author Wuwei YUAN
 * @date 3/26/20
 */

#include <iostream>
#include "OptRouter.h"

const static int kNumDirections=4;
const static int X[kNumDirections] = {0,-1,0,1};
const static int Y[kNumDirections] = {-1,0,1,0};
const static int kMaxInt = 0x7fffffff;


bool OptRouter::route()
{
  // Initialize the costs
  int num_grids = m_row * m_col;
  for (int grid : m_grids) {
    if (grid >= 0) {
      grid = num_grids;
    }
  }
  m_grids[m_sourceIndex] = 0;

  if (mazeSearch()) {
    mazeBacktrace();
    return true;
  }
  return false;
}

void OptRouter::mazeBacktrace() {
  // Find path with minimum turns
  optimal_turns_ = kMaxInt;
  Dfs(m_targetIndex, MIN, START);
  std::cout << "Found a path with minimum turns(" << optimal_turns_ << "): ";
  for (int index : m_path) {
    int x, y;
    compXYIndex(index, x, y);
    std::cout << "[" << x << "," << y << "] ";
  }
  std::cout << std::endl;

  // Find path with maximum turns
  optimal_turns_ = -1;
  Dfs(m_targetIndex, MAX, START);
  std::cout << "Found a path with maximum turns(" << optimal_turns_ << "): ";
  for (int index : m_path) {
    int x, y;
    compXYIndex(index, x, y);
    std::cout << "[" << x << "," << y << "] ";
  }
  std::cout << std::endl;
}

void OptRouter::Dfs(int current_index, int aim, int current_direction, int num_turns) {
  if (aim == MIN && num_turns >= optimal_turns_) {
    return;
  }
  current_path_.push_back(current_index);
  if (current_index == m_sourceIndex && num_turns * aim < optimal_turns_ * aim) {
    optimal_turns_ = num_turns;
    m_path = current_path_;
    current_path_.pop_back();
    return;
  }
  int current_x, current_y;
  compXYIndex(current_index, current_x, current_y);
  for (int i = 0; i < kNumDirections; i++) {
    int next_x = current_x + X[i];
    int next_y = current_y + Y[i];
    int next_index = compIndex(next_x, next_y);
    if (next_x >= 0 && next_x < m_row && next_y >= 0 && next_y < m_col && m_grids[next_index] == m_grids[current_index] - 1) {
      int next_direction = i & 1;
      Dfs(next_index, aim, next_direction, num_turns + (next_direction == (current_direction ^ 1)));
    }
  }
  current_path_.pop_back();
}