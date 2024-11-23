#include <cstring>
#include <iostream>

int N;
int M;
bool AVOID[201][201];
int ANSWER;

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    int a, b;
    std::cin >> a >> b;
    AVOID[a][b] = true;
    AVOID[b][a] = true;
  }

  for (int i = 1; i <= N; ++i) {
    for (int j = i + 1; j <= N; ++j) {
      if (!AVOID[i][j]) {
        for (int k = j + 1; k <= N; ++k) {
          if (!AVOID[i][k] && !AVOID[j][k])
            ANSWER++;
        }
      }
    }
  }

  std::cout << ANSWER;

  return 0;
}