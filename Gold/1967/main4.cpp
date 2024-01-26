#include <cstring>
#include <iostream>
#include <utility>
#include <vector>
#define MAX_SIZE (10000)
typedef std::pair<int, int> pii_t;

std::vector<pii_t> tree[MAX_SIZE + 1];
bool visited[MAX_SIZE + 1];
int g_max = 0;
int g_node;

void input()
{
    int n;
    int s;
    int e;
    int w;

    std::cin >> n;
    while (--n) {
        std::cin >> s >> e >> w;
        tree[s].push_back(std::make_pair(e, w));
        tree[e].push_back(std::make_pair(s, w));
    }
}

void dfs(int cur, int sum)
{
    visited[cur] = true;
    for (pii_t i : tree[cur]) {
        if (visited[i.first]) {
            continue;
        }
        int len = i.second + sum;
        if (len > g_max) {
            g_max = len;
            g_node = i.first;
        }
        dfs(i.first, len);
    }
}

int main(void)
{
    input();
    dfs(1, 0);
    std::memset(visited, 0, sizeof(visited));
    g_max = 0;
    dfs(g_node, 0);
    std::cout << g_max << std::endl;
    return 0;
}