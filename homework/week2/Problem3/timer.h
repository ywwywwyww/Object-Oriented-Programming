//
// Created by yww on 3/3/20.
//

#ifndef PROBLEM1_TIMER_H
#define PROBLEM1_TIMER_H

#include <sys/time.h>

/**
 * a timer
 */
class Timer {

 public:
  /**
   * start timing
   */
  void Start() {
    start_time_ = GetTimeOfDay();
  }

  /**
   * stop timing
   * @return time elapsed by second
   */
  double Stop() {
    end_time_ = GetTimeOfDay();
    return end_time_ - start_time_;
  }

 private:
  /**
    * get time of day
    * @return time of day
    */
  static double GetTimeOfDay() {
    timeval current_time;
    gettimeofday(&current_time, NULL);
    return current_time.tv_sec + current_time.tv_usec / double(kUsecsPerSec);
  }

  inline const static int kUsecsPerSec = {1000000};
  double start_time_;
  double end_time_;

};

#endif //PROBLEM1_TIMER_H
