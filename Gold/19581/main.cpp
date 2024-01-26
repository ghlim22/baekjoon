#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#define MAX_SIZE (100000)

typedef std::pair<int, int> pii_t;

std::vector<pii_t> tree[MAX_SIZE + 1];
bool vis[MAX_SIZE + 1];

void input()
{
    int n;

    std::cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int s, e, w;
        std::cin >> s >> e >> w;
        tree[s].push_back(std::make_pair(e, w));
        tree[e].push_back(std::make_pair(s, w));
    }
}

pii_t bfs(int start, int remove)
{
    int max = 0;
    int farthest = 0;
    std::queue<pii_t> q;

    std::memset(vis, 0, sizeof(vis));
    vis[remove] = true;
    q.push(std::make_pair(start, 0));

    while (!q.empty()) {
        int cur = q.front().first;
        int dist = q.front().second;
        vis[cur] = true;
        q.pop();

        for (pii_t i : tree[cur]) {
            int next = i.first;
            int weight = i.second;
            int sum = weight + dist;
            if (vis[next]) {
                continue;
            }
            if (sum > max) {
                max = sum;
                farthest = next;
            }
            q.push(std::make_pair(next, sum));
        }
    }

    return std::make_pair(farthest, max);
}

void solve()
{
    int a = bfs(1, 0).first;
    int b = bfs(a, 0).first;
    std::cout << std::max(bfs(a, b).second, bfs(b, a).second) << std::endl;
}

int main(void)
{
    input();
    solve();
    return 0;
}