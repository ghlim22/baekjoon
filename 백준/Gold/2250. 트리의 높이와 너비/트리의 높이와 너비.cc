#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>

#define MAX (10000)
#define L (0)
#define R (1)

typedef std::pair<int, int> pii_t;
typedef std::vector<int> vi_t;
typedef std::vector<pii_t> vpii_t;

int idx = 0;
int N;
int tree[MAX + 1][2];
bool isChild[MAX + 1];
std::vector<vi_t> board(MAX + 1);

void input() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    int node, left, right;
    std::cin >> node >> left >> right;
    tree[node][L] = left;
    tree[node][R] = right;
    if (left != -1)
      isChild[left] = true;
    if (right != -1)
      isChild[right] = true;
  }
}

int findRoot() {
  int root = -1;
  for (int i = 1; i <= N; ++i) {
    if (!isChild[i]) {
      root = i;
      break;
    }
  }
  return root;
}

/* 각 노드에 열 번호를 부여한다. */
int traverse(int offset, int level, int node) {
  if (node == -1)
    return 0;
  int l = traverse(offset, level + 1, tree[node][L]);
  board[level].push_back(offset + l);
  int r = traverse(offset + l + 1, level + 1, tree[node][R]);
  return l + r + 1;
}

void traverse(int level, int node) {
  if (node == - 1)
    return;
  traverse(level + 1, tree[node][L]);
  board[level].push_back(idx++);
  traverse(level + 1, tree[node][R]);
}

void findWidth() {
  int max_width = 1;
  int level = 1;
  int width;
  for (int i = 1; !board[i].empty(); ++i) {
    std::sort(board[i].begin(), board[i].end());
    width = board[i].back() - board[i].front() + 1;
    if (width > max_width) {
      max_width = width;
      level = i;
    }
  }
  std::cout << level << ' ' << max_width;
}

void solve() {
  int root = findRoot();
  //traverse(0, root, 1);
  traverse(1, root);
  findWidth();
}

int main() {
  input();
  solve();
  return 0;
}