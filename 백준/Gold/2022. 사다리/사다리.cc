#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>

int main() {
  double x, y, c;

  std::cin >> x >> y >> c;

  double lo = 0.0;
  double hi = std::min(x, y);
  for (int i = 0; i < 10000; ++i) {
    double mid = (lo + hi) / 2.0;
    double h1 = std::sqrt(std::pow(x, 2) - std::pow(mid, 2));
    double h2 = std::sqrt(std::pow(y, 2) - std::pow(mid, 2));
    double height = (h1 * h2) / (h1 + h2);
    if (height > c) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  std::cout << lo;

  return 0;
}