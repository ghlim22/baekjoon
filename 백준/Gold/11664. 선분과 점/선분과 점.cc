#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>

struct point {
  double x;
  double y;
  double z;
};

double distance(point x, point y) {
  double x2 = std::pow(x.x - y.x, 2);
  double y2 = std::pow(x.y - y.y, 2);
  double z2 = std::pow(x.z - y.z, 2);

  return std::sqrt(x2 + y2 + z2);
}

int main() {
  point a, b, c;
  std::cin >> a.x >> a.y >> a.z;
  std::cin >> b.x >> b.y >> b.z;
  std::cin >> c.x >> c.y >> c.z;

  point v = {b.x - a.x, b.y - a.y, b.z - a.z};
  double lo = 0.0;
  double hi = 1.0;

  while (std::abs(hi - lo) > 1e-9) {
    double m1 = lo + (hi - lo) / 3.0;
    double m2 = hi - (hi - lo) / 3.0;

    point m1p = {a.x + m1 * v.x, a.y + m1 * v.y, a.z + m1 * v.z};
    point m2p = {a.x + m2 * v.x, a.y + m2 * v.y, a.z + m2 * v.z};

    double m1d = distance(c, m1p);
    double m2d = distance(c, m2p);

    if (m1d < m2d) {
      hi = m2;
    } else {
      lo = m1;
    }
  }

  double m = (lo + hi) / 2.0;
  point p = {a.x + m * v.x, a.y + m * v.y, a.z + m * v.z};

  std::cout << std::fixed << std::setprecision(10) << distance(p, c);

  return 0;
}
