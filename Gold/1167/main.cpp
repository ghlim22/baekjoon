#include <cstdio>
#include <utility>
#include <vector>

#define MAX_SIZE (100000)

typedef std::pair<int, int> pii_t;
std::vector<pii_t> tree[MAX_SIZE + 1];
int n;
int result = 0;
bool vis[MAX_SIZE + 1] = {
    false,
};

void input()
{
    int node_index;
    int peer_index;
    int distance;

    std::scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        std::scanf("%d", &node_index);
        while (true) {
            std::scanf("%d", &peer_index);
            if (peer_index == -1) {
                break;
            }
            std::scanf("%d", &distance);
            tree[node_index].push_back(std::make_pair(peer_index, distance));
        }
    }
}

int solve(int cur)
{
    int sum = 0;
    int max = 0;
    int second = 0;

    vis[cur] = true;
    for (pii_t i : tree[cur]) {
        if (vis[i.first]) {
            continue;
        }
        sum = solve(i.first) + i.second;
        if (sum > max) {
            second = max;
            max = sum;
        } else if (sum > second) {
            second = sum;
        }
    }
    if (max + second > result) {
        result = max + second;
    }
    return max;
}

int main(void)
{
    input();
    solve(1);
    std::printf("%d\n", result);
    return 0;
}