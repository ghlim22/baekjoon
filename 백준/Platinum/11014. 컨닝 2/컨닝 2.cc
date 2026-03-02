#include <cstring>
#include <iostream>
#include <utility>
#include <vector>

#define ROW_MAX 80
#define COL_MAX 80
#define SET_MAX (COL_MAX / 2 * ROW_MAX)

using namespace std;

int c, n, m, nodeMax;
bool map[ROW_MAX][COL_MAX];
int matchB[SET_MAX];
bool visitedA[SET_MAX];
vector<int> graphAB[SET_MAX];

int ind(int row, int col)
{
  return col / 2 * n + row;
}

void link(int row, int col)
{
  if (!map[row][col])
    return;
  int set = col % 2;
  int u = ind(row, col);
  vector<pair<int, int>> end = {{row - 1, col + 1}, {row, col + 1}, {row + 1, col + 1}};
  for (const auto &e : end)
  {
    if (e.first < 0 || e.first >= n)
      continue;
    if (!map[e.first][e.second])
      continue;
    int v = ind(e.first, e.second);
    if (set == 0) {
      graphAB[u].push_back(v);
    }
    else {
     graphAB[v].push_back(u);
    }
  }
}

void build()
{
  for (int col = 0; col < m - 1; ++col)
  {
    for (int row = 0; row < n; ++row)
      link(row, col);
  }
}

bool dfs(int nodeA)
{
  if (visitedA[nodeA]) {
    return false;
  }

  visitedA[nodeA] = true;
  for (int nodeB : graphAB[nodeA]) {
    if (matchB[nodeB] == -1 || dfs(matchB[nodeB])) {
      matchB[nodeB] = nodeA;
      return true;
    }
  }

  return false;
}

int solve()
{
  int total = 0;
  for (int r = 0; r < n; ++r)
  {
    for (int c = 0; c < m; ++c)
    {
      if (map[r][c]) {
        ++total;
      }
    }
  }

  build();
  int matched = 0;
  for (int nodeA = 0; nodeA < nodeMax; ++nodeA)
  {
    memset(visitedA, 0, sizeof(visitedA));
    if (dfs(nodeA))
      matched++;
  }

  return (total - matched);
}

int main()
{
  cin >> c;
  while (c--) {
    memset(map, 0, sizeof(map));
    memset(matchB, -1, sizeof(matchB));
    for (int i = 0; i < SET_MAX; ++i) {
      graphAB[i].clear();
    }

    cin >> n >> m;
    nodeMax = n * (m + 1) / 2;
    for (int r = 0; r < n; ++r) {
      string s;
      cin >> s;
      for (int c = 0; c < m; ++c) {
        if (s[c] == '.') {
            map[r][c] = true;
        }
      }
    }

    cout << solve() << endl;
  }

  return 0;
}
