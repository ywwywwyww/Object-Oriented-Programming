/**
 * @file main.cpp
 * @author Wuwei YUAN
 * @date 3/4/2020
 */

#include <cstdlib>
#include "func.h"
#include <iostream>
#include <iomanip>
#include "timer.h"

int main(int argc, char **argv) {
  // If there is no input, report an error
  if (argc == 1) {
    std::cerr << "ERROR no input: please input a[] and x" << "\n";
    return 0;
  }
  // Process input
  double x = atof(argv[argc - 1]);
  int n = argc - 2;
  auto *a = new double[n];
  for (int i = 0; i < n; i++) {
    a[i] = atof(argv[i + 1]);
  }

  std::cout << std::fixed << std::setprecision(2);
  // Compute result
  std::cout << "result of polynomial by brute force algorithm is " <<
         BruteForceComputePolynomialFunction(a, n, x) << "\n";
  std::cout << "result of polynomial by QINGJiuShao's algorithm is " <<
         QingjiushaosComputePolynomialFunction(a, n, x) << "\n";
  std::cout << "result of posynomial by brute force algorithm is " <<
         BruteForceComputePosynomialFunction(a, n, x) << "\n";
  std::cout << "result of posynomial by QINGJiuShao's algorithm is " <<
         QingjiushaosComputePosynomialFunction(a, n, x) << "\n";

  // Time and output
  const int times = 100000000;
  double brute_force_runtime, QINGJiuShaos_runtime, improvement;
  Timer timer{};
  timer.Start();
  for (int i = 1; i <= times; i++) {
    BruteForceComputePolynomialFunction(a, n, x);
  }
  brute_force_runtime = timer.Stop();
  timer.Start();
  for (int i = 1; i <= times; i++) {
    QingjiushaosComputePolynomialFunction(a, n, x);
  }
  QINGJiuShaos_runtime = timer.Stop();
  improvement = (brute_force_runtime - QINGJiuShaos_runtime) / brute_force_runtime;
  std::cout << "polynomial:\n  brute force: " << brute_force_runtime <<
      "s\n  QINGJiuShao's: " << QINGJiuShaos_runtime <<
      "s\n  improvement: " << improvement * 100 << "%\n";
  timer.Start();
  for (int i = 1; i <= times; i++) {
    BruteForceComputePosynomialFunction(a, n, x);
  }
  brute_force_runtime = timer.Stop();
  timer.Start();
  for (int i = 1; i <= times; i++) {
    QingjiushaosComputePosynomialFunction(a, n, x);
  }
  QINGJiuShaos_runtime = timer.Stop();
  std::cout << "posynomial:\n  brute force: " << brute_force_runtime <<
            "s\n  QINGJiuShao's: " << QINGJiuShaos_runtime <<
            "s\n  improvement: " << improvement * 100 << "%\n";
  return 0;
}