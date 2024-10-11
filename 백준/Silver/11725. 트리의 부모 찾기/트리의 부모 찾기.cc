#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#define MAX (100000)

typedef std::pair<int, int> pii_t;
typedef std::vector<int> vi_t;

int N;
bool visited[MAX + 1];
int parent[MAX + 1];
std::vector<vi_t> tree(MAX + 1);

void input() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    int a, b;
    std::cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
}

void visit(int idx) {
  visited[idx] = true;
  for (int adj : tree[idx]) {
    if (visited[adj])
      continue;
    parent[adj] = idx;
    visit(adj);
  }
}

void solve() {
  visit(1);
  for (int i = 2; i <= N; ++i) {
    std::cout << parent[i] << '\n';
  }
}

int main(void) {
	input();
	solve();
	return 0;
}