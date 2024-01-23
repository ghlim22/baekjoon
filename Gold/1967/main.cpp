#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#define MAX_SIZE (10000)

typedef std::pair<int, int> pii;

int n;
int cache[MAX_SIZE + 1];
std::vector<pii> tree[MAX_SIZE + 1];

void input()
{
    int parent;
    int child;
    int weight;

    std::cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> parent >> child >> weight;
        tree[parent].push_back(std::make_pair(child, weight));
    }
}

void solve()
{
    int ans = 0;

    for (int i = n; i >= 1; --i) {
        int max = 0;
        int second = 0;
        for (int j = 0; j < tree[i].size(); ++j) {
            int child = tree[i][j].first;
            int weight = tree[i][j].second;
            int tmp = weight + cache[child];
            cache[i] = std::max(cache[i], tmp);
            if (tmp > max) {
                second = max;
                max = tmp;
            } else if (tmp > second) {
                second = tmp;
            }
        }
		ans = std::max(ans, max + second);
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