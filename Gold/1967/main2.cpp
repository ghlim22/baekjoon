#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>
#define MAX_SIZE (10000)

typedef std::pair<int, int> pii;

int ans = 0;
int n = 0;
bool visited[MAX_SIZE + 1] = {
    false,
};
std::vector<pii> tree[MAX_SIZE + 1];

void input()
{
    int a;
    int b;
    int weight;

    std::cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> a >> b >> weight;
        tree[a].push_back(std::make_pair(b, weight));
        tree[b].push_back((std::make_pair(a, weight)));
    }
}

void dfs(int start)
{
    std::stack<pii> s;

    std::memset(visited, 0, sizeof(visited));
    s.push(std::make_pair(start, 0));
    do {
        int cur_node = s.top().first;
        int cur_len = s.top().second;
        s.pop();
        if (visited[cur_node]) {
            continue;
        }
        ans = std::max(ans, cur_len);
        visited[cur_node] = true;
        for (int i = 0; i < tree[cur_node].size(); ++i) {
            int next_node = tree[cur_node][i].first;
            int edge_weight = tree[cur_node][i].second;
            if (visited[next_node]) {
                continue;
            }
            s.push(std::make_pair(next_node, cur_len + edge_weight));
        }
    } while (!s.empty());
}

void solve()
{
    for (int i = 1; i <= n; ++i) {
        dfs(i);
    }
    std::cout << ans << '\n';
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    input();
    solve();

    return 0;
}