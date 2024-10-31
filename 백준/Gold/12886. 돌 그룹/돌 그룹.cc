#include <iostream>

int gcd(int a, int b) {
  if (a < b) {
    int t = a;
    a = b;
    b = t;
  }

  while (b != 0) {
    int t = a % b;
    a = b;
    b = t;
  }

  return a;
}

int solve(int a, int b, int c) {
  int s = a + b + c;
  int g = gcd(gcd(a, b), c);

  if ((s / g) % 3 != 0) {
    return 0;
  }

  s /= g;
  s /= 3;
  int cnt = 0;
  while (s > 0) {
    if (s & 1) {
      cnt++;
    }
    s >>= 1;
  }

  return (cnt == 1);
}

int main(void) {

  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int a, b, c;

  std::cin >> a >> b >> c;

  std::cout << solve(a, b, c);

  return 0;
}
