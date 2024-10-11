#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>

#define MAX (100000)

typedef std::pair<int, int> pii_t;
typedef std::vector<int> vi_t;
typedef std::vector<pii_t> vpii_t;

int g_end;
int N;
bool visited[MAX + 1];

std::vector<vpii_t> tree(MAX + 1);

void input() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    int node, v, w;
    std::cin >> node;
    while (true) {
      std::cin >> v;
      if (v == -1)
        break;
      std::cin >> w;
      tree[node].push_back(std::make_pair(v, w));
    }
  }
}

int dfs(int start) {
  std::stack<pii_t> st;
  int max_len = 0;

  memset(visited, 0, sizeof(visited));

  st.push(std::make_pair(start, 0));
  while (!st.empty()){
    int cur = st.top().first;
    int len = st.top().second;
    st.pop();
    visited[cur] = true;
    
    if (len > max_len) {
      max_len = len;
      g_end = cur; 
    }

    for (pii_t v : tree[cur]) {
      if (visited[v.first])
        continue;
      st.push(std::make_pair(v.first, v.second + len));
    }
  }

  return max_len;
}

void solve() {
  dfs(1);
  std::cout << dfs(g_end);
}

int main(void) {
  input();
  solve();
  return 0;
}