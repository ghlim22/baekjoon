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

int main() {
  fastio;
  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i)
    std::cin >> a[i];
  for (int i = 0; i < m; ++i)
    std::cin >> b[i];

  std::vector<int> v;
  int i = 0;
  int j = 0;
  while (i < n && j < m) {
    while (i < n && a[i] <= b[j]) {
      v.push_back(a[i++]);
    }
	if (i == n) {
		break;
	}
    while (j < m && b[j] <= a[i]) {
      v.push_back(b[j++]);
    }
  }
  while (i < n) {
    v.push_back(a[i++]);
  }
  while (j < m) {
    v.push_back(b[j++]);
  }

  for (int num : v) {
    std::cout << num << ' ';
  }
  std::cout << std::endl;

  return 0;
}