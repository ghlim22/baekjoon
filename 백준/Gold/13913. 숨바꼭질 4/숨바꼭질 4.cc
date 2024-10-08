#include <cstring>
#include <iostream>
#include <queue>
#include <stack>

#define MAX (100000)

bool visited[MAX + 1];
int route[MAX + 1];
int N;
int K;

void input() { std::cin >> N >> K; }

void print_answer(int cost) {
  std::cout << cost << '\n';
  std::stack<int> s;
  int cur = K;
  while (cur != -1) {
	s.push(cur);
	cur = route[cur];
  }

  while (!s.empty()) {
    std::cout << s.top() << ' ';
    s.pop();
  }
}

void solve() {
  memset(route, -1, sizeof(route));

  std::queue<int> q;
  int cost = 0;

  q.push(N);
  visited[N] = true;
  while (!q.empty()) {
    const int size = q.size();
    for (int i = 0; i < size; i++) {
      int x = q.front();
      q.pop();
      if (x == K) {
        print_answer(cost);
        return;
      }

      int nx[3] = {x - 1, x + 1, x * 2};
      for (int j = 0; j < 3; ++j) {
        if (!(nx[j] >= 0 && nx[j] <= MAX)) {
          continue;
        }
        if (visited[nx[j]]) {
          continue;
        }
        q.push(nx[j]);
        visited[nx[j]] = true;
        route[nx[j]] = x;
      }
    }
    cost++;
  }
}

int main(void) {
  input();
  solve();
  return 0;
}