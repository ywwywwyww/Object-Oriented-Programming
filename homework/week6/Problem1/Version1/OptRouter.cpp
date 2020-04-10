/**
 * @file OptRouter.cpp
 * @author Wuwei YUAN
 * @date 3/26/20
 */

#include <iostream>
#include "OptRouter.h"

const static int kNumDirections = 4;
const static int X[kNumDirections] = {0, -1, 0, 1};
const static int Y[kNumDirections] = {-1, 0, 1, 0};
const static int kMaxInt = 0x7fffffff;

bool OptRouter::route() {
  // Initialize the costs
  int num_grids = this->m_row * this->m_col;
  for (int grid : this->m_grids) {
    if (grid >= 0) {
      grid = num_grids;
    }
  }
  this->m_grids[this->m_sourceIndex] = 0;

  if (this->mazeSearch()) {
    this->mazeBacktrace();
    return true;
  }
  return false;
}

void OptRouter::mazeBacktrace() {
  // Find path with minimum turns
  this->optimal_turns_ = kMaxInt;
  this->Dfs(this->m_targetIndex, this->MIN, this->START);
  std::cout << "Found a path with the minimum turns(" << this->optimal_turns_ << "): ";
  for (int index : this->m_path) {
    int x, y;
    this->compXYIndex(index, x, y);
    std::cout << "[" << x << "," << y << "] ";
  }
  std::cout << std::endl;

  // Find path with maximum turns
  this->optimal_turns_ = -1;
  this->Dfs(this->m_targetIndex, this->MAX, this->START);
  std::cout << "Found a path with the maximum turns(" << this->optimal_turns_ << "): ";
  for (int index : this->m_path) {
    int x, y;
    this->compXYIndex(index, x, y);
    std::cout << "[" << x << "," << y << "] ";
  }
  std::cout << std::endl;
}

void OptRouter::Dfs(int current_index, int aim, int current_direction, int num_turns) {
  if (aim == this->MIN && num_turns >= this->optimal_turns_) {
    return;
  }
  this->current_path_.push_back(current_index);
  if (current_index == this->m_sourceIndex && num_turns * aim < this->optimal_turns_ * aim) {
    this->optimal_turns_ = num_turns;
    this->m_path = this->current_path_;
    this->current_path_.pop_back();
    return;
  }
  // Move to the next grid
  int current_x, current_y;
  this->compXYIndex(current_index, current_x, current_y);
  for (int i = 0; i < kNumDirections; i++) {
    int next_x = current_x + X[i];
    int next_y = current_y + Y[i];
    int next_index = this->compIndex(next_x, next_y);
    if (next_x >= 0 && next_x < this->m_row && next_y >= 0 && next_y < this->m_col &&
        this->m_grids[next_index] == this->m_grids[current_index] - 1) {
      int next_direction = i & 1;
      this->Dfs(next_index, aim, next_direction, num_turns + (next_direction == (current_direction ^ 1)));
    }
  }
  this->current_path_.pop_back();
}