#include <iostream>
#include <vector>

#define fastio                        \
  do                                  \
  {                                   \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0);                 \
  } while (0)

#define MAX 100001

int N, R, Q;
int sizes[MAX];
std::vector<std::vector<int>> edges(MAX);
std::vector<std::vector<int>> tree(MAX);

void make_tree(int parent, int node)
{
  for (int child : edges[node])
  {
    if (child != parent)
    {
      tree[node].push_back(child);
      make_tree(node, child);
    }
  }
}

int traverse(int node)
{
  sizes[node] = 1;
  for (int child : tree[node])
  {
    sizes[node] += traverse(child);
  }
  return sizes[node];
}

int main(void)
{
  fastio;
  std::cin >> N >> R >> Q;
  for (int i = 0; i < N - 1; ++i)
  {
    int u, v;
    std::cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  make_tree(0, R);
  traverse(R);

  for (int i = 0; i < Q; ++i)
  {
    int u;
    std::cin >> u;
    std::cout << sizes[u] << '\n';
  }

  return 0;
}