#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int array[5000];
int temp[5000];

bool check(int n, int m, int k) {
  int min = 10000;
  int max = 1;
  int intervalCount = 1;
  for (int i = 0; i < n; ++i) {
    min = std::min(array[i], min);
    max = std::max(array[i], max);
    if (max - min > k) {
      intervalCount++;
      min = array[i];
      max = array[i];
    }
  }
  return intervalCount <= m;
}

int main() {
  int n;
  int m;

  std::cin >> n >> m;
  for (int i = 0; i < n; ++i)
    std::cin >> array[i];

  int lo = 0;
  int hi = 10000;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (check(n, m, mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  std::cout << hi;

  return 0;
}