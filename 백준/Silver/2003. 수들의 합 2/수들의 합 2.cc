#include <iostream>

int A[10001];

int main(void) {
  int N;
  int M;
  int cnt = 0;

  std::cin >> N >> M;
  for (int i = 1; i < N + 1; ++i) {
    int num;
    std::cin >> num;
    A[i] = A[i - 1] + num;
    for (int j = 0; j < i; ++j) {
      if (A[i] - A[j] == M)
        cnt++;
    }
  }
  std::cout << cnt << std::endl;

  return 0;
}