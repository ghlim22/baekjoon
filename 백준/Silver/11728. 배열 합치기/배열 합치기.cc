#include <iostream>
#include <vector>

#define fastio                                                                 \
  do {                                                                         \
    std::ios::sync_with_stdio(false);                                          \
    std::cin.tie(0);                                                           \
    std::cout.tie(0);                                                          \
  } while (0)

int a[1000000];
int b[1000000];
int c[2000000];

int main() {
  fastio;
  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i)
    std::cin >> a[i];
  for (int i = 0; i < m; ++i)
    std::cin >> b[i];

  int i = 0;
  int j = 0;
  int k = 0;
  while (i < n && j < m) {
    while (i < n && a[i] <= b[j]) {
      c[k++] = a[i++];
    }
    if (i == n) {
      break;
    }
    while (j < m && b[j] <= a[i]) {
      c[k++] = b[j++];
    }
  }
  while (i < n) {
    c[k++] = a[i++];
  }
  while (j < m) {
    c[k++] = b[j++];
  }

  i = 0;
  for (; i < k; ++i) {
    std::cout << c[i] << ' ';
  }

  std::cout << std::endl;

  return 0;
}