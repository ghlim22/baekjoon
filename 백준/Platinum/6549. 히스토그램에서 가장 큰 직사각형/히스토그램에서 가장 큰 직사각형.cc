#include <algorithm>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

typedef std::pair<int, int> pii_t;

int h[100000];

long f(int h[], int low, int high) {
  if (low == high) {
    return h[low];
  }

  int mid = (low + high) / 2;
  int i = mid;
  int j = mid;
  int min_height = h[mid];
  long area = 0;

  while (low <= i && j <= high) {
    min_height = std::min(min_height, std::min(h[i], h[j]));
    area = std::max(area, (long)min_height * (j - i + 1));
    if (i == low) {
      j++;
    } else if (j == high) {
      i--;
    } else if (h[i - 1] > h[j + 1]) {
      i--;
    } else {
      j++;
    }
  }

  return std::max(area, std::max(f(h, low, mid), f(h, mid + 1, high)));
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int n;

  for (;;) {
    std::cin >> n;
    if (n == 0)
      break;

    for (int i = 0; i < n; ++i)
      std::cin >> h[i];

    std::cout << f(h, 0, n - 1) << std::endl;
  }

  return 0;
}