#include <cstring>
#include <iostream>
#include <stack>

int N;
long B[100];
bool V[100];
int TRACE[100];

void solve(int cur, int depth) {
  for (int i = 0; i < N; ++i) {
    if (V[i])
      continue;
    if ((B[cur] % 3 == 0 && B[cur] / 3 == B[i]) || B[cur] * 2 == B[i]) {
      V[i] = true;
      TRACE[i] = cur;
      if (depth == N - 1) {
        std::stack<long> s;
        for (int j = i; j != -1; j = TRACE[j]) {
          s.push(B[j]);
        }
        while (!s.empty()) {
          std::cout << s.top() << ' ';
          s.pop();
        }
        return;
      }
      solve(i, depth + 1);
      TRACE[i] = -1;
      V[i] = false;
    }
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::memset(TRACE, -1, sizeof(TRACE));

  std::cin >> N;
  for (int i = 0; i < N; ++i)
    std::cin >> B[i];

  for (int i = 0; i < N; ++i) {
    V[i] = true;
    solve(i, 1);
    V[i] = false;
    TRACE[i] = -1;
  }

  return 0;
}