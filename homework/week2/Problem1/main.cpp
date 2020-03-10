/**
 * @file main.cpp
 * @author Wuwei YUAN
 * @date 3/4/2020
 */

#include <cstdlib>
#include "func.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include "timer.h"

int main(int argc, char **argv) {
  // If there is no input, report an error
  if (argc <= 2) {
    std::cerr << "Usage: ./Problem1 <coefficient 0> <coefficient 1> ...  <coefficient n-1> <independent variable>"
              << std::endl;
    return 0;
  }
  // Process input
  double x = atof(argv[argc - 1]);
  int n = argc - 2;
  std::vector<double> a;
  for (int i = 0; i < n; i++) {
    a.push_back(atof(argv[i + 1]));
  }

  if (fabs(x) < 1e-9) {
    std::cerr << "ERROR illegal input: x is zero" << std::endl;
    return 0;
  }

  std::cout << std::fixed << std::setprecision(2);
  // Compute result
  std::cout << "result of polynomial by brute force algorithm is " <<
            algorithm::BruteForceComputePolynomialFunction(a, x) << std::endl;
  std::cout << "result of polynomial by QINGJiuShao's algorithm is " <<
            algorithm::QingjiushaosComputePolynomialFunction(a, x) << std::endl;
  std::cout << "result of posynomial by brute force algorithm is " <<
            algorithm::BruteForceComputePosynomialFunction(a, x) << std::endl;
  std::cout << "result of posynomial by QINGJiuShao's algorithm is " <<
            algorithm::QingjiushaosComputePosynomialFunction(a, x) << std::endl;

  // Time and output
  const int times = 100000000;
  double brute_force_runtime, QINGJiuShaos_runtime, improvement;
  Timer timer{};
  timer.Start();
  for (int i = 1; i <= times; i++) {
    algorithm::BruteForceComputePolynomialFunction(a, x);
  }
  brute_force_runtime = timer.Stop();
  timer.Start();
  for (int i = 1; i <= times; i++) {
    algorithm::QingjiushaosComputePolynomialFunction(a, x);
  }
  QINGJiuShaos_runtime = timer.Stop();
  improvement = (brute_force_runtime - QINGJiuShaos_runtime) / brute_force_runtime;
  std::cout << "polynomial:\n  brute force: " << brute_force_runtime <<
            "s\n  QINGJiuShao's: " << QINGJiuShaos_runtime <<
            "s\n  improvement: " << improvement * 100 << "%" << std::endl;
  timer.Start();
  for (int i = 1; i <= times; i++) {
    algorithm::BruteForceComputePosynomialFunction(a, x);
  }
  brute_force_runtime = timer.Stop();
  timer.Start();
  for (int i = 1; i <= times; i++) {
    algorithm::QingjiushaosComputePosynomialFunction(a, x);
  }
  QINGJiuShaos_runtime = timer.Stop();
  improvement = (brute_force_runtime - QINGJiuShaos_runtime) / brute_force_runtime;
  std::cout << "posynomial:\n  brute force: " << brute_force_runtime <<
            "s\n  QINGJiuShao's: " << QINGJiuShaos_runtime <<
            "s\n  improvement: " << improvement * 100 << "%" << std::endl;
  return 0;
}