#include <algorithm>
#include <iostream>

#define fastio                                                                 \
  do {                                                                         \
    std::ios::sync_with_stdio(false);                                          \
    std::cin.tie(0);                                                           \
    std::cout.tie(0);                                                          \
  } while (0)

int cards[500000];
int numbers[500000];

int lowerbound(int n, int key) {
  int low = 0;
  int high = n;
  while (low < high) {
    int mid = (low + high) / 2;
    if (cards[mid] >= key)
      high = mid;
    else
      low = mid + 1;
  }

  return high;
}

int upperbound(int n, int key) {
  int low = 0;
  int high = n;
  while (low < high) {
    int mid = (low + high) / 2;
    if (cards[mid] <= key)
      low = mid + 1;
    else
      high = mid;
  }

  return high;
}

int main() {
  fastio;
  int n, m;

  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> cards[i];
  }
  std::sort(cards, cards + n);

  std::cin >> m;
  for (int i = 0; i < m; ++i) {
    int num;
    std::cin >> num;
    std::cout << upperbound(n, num) - lowerbound(n, num) << ' ';
  }
  std::cout << std::endl;

  return 0;
}