#include <iostream>

#define MAX (10)

int N;
int W[MAX];
bool visited[MAX];
int max_sum;

void input() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::cin >> W[i];
  }
}

void recur(int size, int sum) {
  if (size == 2) {
    if (sum > max_sum)
      max_sum = sum;
    return;
  }

  for (int i = 1; i < N - 1; i++) {
    if (visited[i])
      continue;
    visited[i] = true;
    int j;
    for (j = i - 1; j >= 0 && visited[j]; j--)
      ;
    int k;
    for (k = i + 1; k < N && visited[k]; k++)
      ;
    recur(size - 1, sum + W[j] * W[k]);
    visited[i] = false;
  }
}

void solve() {
    recur(N, 0);
    std::cout << max_sum;
}

int main() {
    input();
    solve();
}