#include <algorithm>
#include <climits>
#include <iostream>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int a, b, c, x, y;

  std::cin >> a >> b >> c >> x >> y;

  int banban = std::min(x, y);
  int answer = banban * c * 2 + (x - banban) * a + (y - banban) * b;
  answer = std::min(answer, std::max(x, y) * c * 2);
  answer = std::min(answer, a * x + b * y);

  std::cout << answer;

  return 0;
}
