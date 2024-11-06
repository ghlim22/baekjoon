#include <iostream>
#include <queue>
#include <set>
#include <utility>

typedef std::pair<int, std::string> pis_t;

int S;
int T;

void input(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> S >> T;
}

void solve(void) {
  if (S == T) {
    std::cout << 0;
    return;
  }

  std::set<int> visited;
  std::queue<pis_t> q;

  visited.insert(S);
  q.push(std::make_pair(S, ""));

  while (!q.empty()) {
    pis_t cur = q.front();
    q.pop();

    if (cur.first == T) {
      std::cout << cur.second;
      return;
    }

    if (cur.first <= 0) {
      continue;
    }

    long next[4] = {cur.first * (long)cur.first, (long)cur.first << 1, 0, 1};
    char op[4] = {'*', '+', '*', '/'};
    for (int i = 0; i < 4; ++i) {
      if (cur.first == 0 && i == 3) /* Avoid division by zero */
        continue;
      if (next[i] > T)
        continue;
      if (visited.find(next[i]) != visited.end())
        continue;
      visited.insert(next[i]);
      q.push(std::make_pair(next[i], cur.second + op[i]));
    }
  }

  std::cout << -1;
}

int main(void) {
  input();
  solve();
  return 0;
}