#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>

#define MAX_SIZE (100000)

typedef std::pair<int, int> pii_t;

std::vector<pii_t> tree[MAX_SIZE + 1];
bool visited[MAX_SIZE + 1];

void input()
{
    int n;
    int s;
    int e;
    int w;

    std::scanf("%d", &n);
    while (--n) {
        scanf("%d %d %d", &s, &e, &w);
        tree[s].push_back(std::make_pair(e, w));
        tree[e].push_back(std::make_pair(s, w));
    }
}

pii_t bfs(int start, int removed)
{
    int max = 0;
    int farthest = 0;
    std::queue<pii_t> q;

    std::memset(visited, 0, sizeof(visited));
    visited[removed] = true;
    q.push(std::make_pair(start, 0));
    while (!q.empty()) {
        int cur = q.front().first;
        int dist = q.front().second;
        q.pop();

        visited[cur] = true;
        for (pii_t i : tree[cur]) {
            int next = i.first;
            int weight = i.second;

            if (visited[next]) {
                continue;
            }

            int sum = dist + weight;
            if (sum > max) {
                max = sum;
                farthest = next;
            }

            q.push(std::make_pair(next, sum));
        }
    }

    return (std::make_pair(farthest, max));
}

void solve()
{
    int a = bfs(1, 0).first;
    int b = bfs(a, 0).first;

    std::printf("%d\n", std::max(bfs(a, b).second, bfs(b, a).second));
}

int main(void)
{
    input();
    solve();
    return 0;
}