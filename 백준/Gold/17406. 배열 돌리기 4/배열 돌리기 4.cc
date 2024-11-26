#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <tuple>
#include <vector>

int N;
int M;
int K;
int A[50][50];
int ANSWER = INT_MAX;
std::vector<std::tuple<int, int, int>> ROT;
bool USED[6];

void rotate(int (*arr)[50], int r, int c, int s) {
  if (s == 0)
    return;

  int upper_left = arr[r - s - 1][c - s - 1];

  for (int i = r - s - 1; i < r + s - 1; ++i) {
    arr[i][c - s - 1] = arr[i + 1][c - s - 1];
  }
  for (int i = c - s - 1; i < c + s - 1; ++i) {
    arr[r + s - 1][i] = arr[r + s - 1][i + 1];
  }
  for (int i = r + s - 1; i > r - s - 1; --i) {
    arr[i][c + s - 1] = arr[i - 1][c + s - 1];
  }
  for (int i = c + s - 1; i > c - s; --i) {
    arr[r - s - 1][i] = arr[r - s - 1][i - 1];
  }
  arr[r - s - 1][c - s] = upper_left;

  rotate(arr, r, c, s - 1);
}

void solve(int cnt) {
  if (cnt == K) {
    int val = INT_MAX;
    for (int i = 0; i < N; ++i) {
      int sum = 0;
      for (int j = 0; j < M; ++j)
        sum += A[i][j];
      val = std::min(val, sum);
    }
    ANSWER = std::min(ANSWER, val);
    return;
  }

  int tmp[50][50];
  std::memmove(tmp, A, sizeof(A));

  for (int i = 0; i < K; ++i) {
    if (USED[i])
      continue;
    USED[i] = true;
    rotate(A, std::get<0>(ROT[i]), std::get<1>(ROT[i]), std::get<2>(ROT[i]));
    solve(cnt + 1);
    std::memmove(A, tmp, sizeof(A));
    USED[i] = false;
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  
  std::cin >> N >> M >> K;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j)
      std::cin >> A[i][j];
  }
  for (int i = 0; i < K; ++i) {
    int r, c, s;
    std::cin >> r >> c >> s;
    ROT.push_back(std::make_tuple(r, c, s));
  }
  solve(0);
  std::cout << ANSWER;
  return 0;
}