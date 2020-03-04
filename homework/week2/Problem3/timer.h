/**
 * @file timer.h
 * @author Wuwei YUAN
 * @date 3/4/2020
 */

#ifndef PROBLEM1_TIMER_H
#define PROBLEM1_TIMER_H

#include <sys/time.h>

/**
 * A class that can helps you measuring time
 * Example:
 *    Timer timer{};
 *    timer.Start();
 *    Sleep(1000);
 *    std::cout << "time elapsed: " << timer.Stop() << "s\n";
 */
class Timer {

 public:
  /**
   * Starts timing
   */
  void Start() {
    start_time_ = GetTimeOfDay();
  }

  /**
   * Stops timing
   * @return time elapsed by second
   */
  double Stop() {
    end_time_ = GetTimeOfDay();
    return end_time_ - start_time_;
  }

 private:
  /**
    * Gets time of day
    * @return Time of day
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
